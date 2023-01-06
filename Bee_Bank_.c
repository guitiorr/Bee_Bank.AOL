#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// fungsi void untuk menampilkan main menu
void MainMenu()
{
    printf("--------------------------------------------------------\n");
    printf("####    ######  ######  ####     #####   #     #  #    #\n");
    printf("#   ##  ##      ##      #   ##  #     #  ##    #  #   #\n");
    printf("#  ##   ##      ##      #  ##   #     #  # #   #  #  #\n");
    printf("###     ######  ######  ###     #     #  #  #  #  # #\n");
    printf("#  ##   ##      ##      #  ##   ## # ##  #   # #  #  #\n");
    printf("#   ##  ##      ##      #   ##  #     #  #    ##  #   #\n");
    printf("####    ######  ######  ####    #     #  #     #  #    #\n");
    printf("--------------------------------------------------------\n\n");
    printf("M E N U :\n\n");
    printf("1. DEPOSITO\n");
    printf("2. TABUNGAN  BERENCANA\n\n");
    printf("ENTER NUMBER(1/2): ");
}

//fungsi menghitung deposito
double Deposito(double save,float interest)
{
    return save*interest*0.8;
}

//fungsi menghitung Tabungan berencana
double TabunganBerencana(double  saving,float rate)
{
    return saving*rate;
}

//fungsi untuk menghitung bunga tabungan berencana
float tabel(int save,int lang)
{
    if(save<1000000)
    {
        if(lang<=120&&lang>60)
        {
            return 0.015;
        }
        else if(lang<=60&&lang>36)
        {
            return 0.012;
        }
        else if(lang<=36&&lang>=12)
        {
            return 0.01;
        }
        else
        {
            return 0.01;
        }
    }
    else 
    {
        if(lang<=120&&lang>60)
        {
            return 0.017;
        }
        else if(lang<=60&&lang>36)
        {
            return 0.015;
        }
        else if(lang<=36&&lang>=12)
        {
            return 0.012;
        }
        else
        {
            return 0.01;
        }
    }
}

int main()
{
    int option;
    char opp;

    do{
    MainMenu();
    scanf("%d",&option);getchar();
    system("cls");
    
    //Menu Driven
    if(option==1)
    {
    int month;
    double sum,tabungan;
    float bungaPerTahun,bunga;
    printf("BEE BANK DEPOSITO\n\n");

    //validasi tabungan tidak boleh 0 atau negative
    do{
    printf("Masukan Jumlah Tabungan: ");scanf("%lf",&tabungan);getchar();
    }while(tabungan<1);

    //validasi bunga tidak boleh 0 atau negative
    do{   
    printf("Masukan bunga pertahun (persen): ");scanf("%f",&bunga);getchar();
    }while(bunga<1);

    //validasi lama deposito tidak boleh 0 atau negative
    do{  
    printf("Lama deposito (bulan): ");scanf("%d",&month);getchar();
    }while(month<1);

    system("cls");
    FILE   *depositRepot = fopen("Laporan_Deposito.txt","w");
    

    fprintf(depositRepot,"+-------------------------------------------+\n");
    fprintf(depositRepot,"|             LAPORAN DEPOSITO              |\n");
    fprintf(depositRepot,"+----------+------------+-------------------+\n");
    fprintf(depositRepot,"| Bulan ke |  bunga(%%)  |       saldo       |\n");
    fprintf(depositRepot,"+----------+------------+-------------------+\n");

    printf("+-------------------------------------------+\n");
    printf("|             LAPORAN DEPOSITO              |\n");
    printf("+----------+------------+-------------------+\n");
    printf("| Bulan ke |  bunga(%%)  |       saldo       |\n");
    printf("+----------+------------+-------------------+\n");
    
   
    for(int x=1;x<=month;x++)
    {
        bungaPerTahun = (bunga/100)/12;
        sum = tabungan + Deposito(tabungan,bungaPerTahun);
        tabungan = sum;
        
        printf("| %-8d | %-10.1f | Rp.%-14.2lf |\n",x,bunga,sum);

        fprintf(depositRepot,"| %-8d | %-10.4f | Rp.%-14.2lf |\n",x,bunga,sum);
        
    }
    printf("+-------------------------------------------+\n");
    fprintf(depositRepot,"+----------+------------+-------------------+\n");

    printf("Laporan Deposito Dapat di Lihat pada file Laporan_Deposito.txt\n\n");
    printf("Transaksi Kembali(y/n): ");scanf("%s",&opp);
    system("cls");
    fclose(depositRepot);
    }

    if(option==2)
    {
        int month;
        double sum,summary,tabungan;
        float bunga,show;
        char namaTabungan[1001];
        
        system("cls");
        printf("TABUNGAN BERENCANA\n\n");

        do{
            printf("Nama Tabungan(minimal 5 karater): ");scanf("%[^\n]",namaTabungan);getchar();

        } while (strlen(namaTabungan)<5);
        
        do{
        printf("Setoran Rutin Bulanan: ");scanf("%lf",&tabungan);getchar();
        }while(tabungan<1);

        do{
        printf("Periode Menabung(bulan): ");scanf("%d",&month);getchar();
        }while(month<1);
        system("cls");

        FILE *tabunganRencana = fopen("Laporan_Tabungan_Berencana.txt","w");

        

        printf("NAMA TABUNGAN : %s\n",namaTabungan);

        printf("+-------------------------------------------+\n");
        printf("|             LAPORAN TABUNGAN              |\n");
        printf("+----------+------------+-------------------+\n");
        printf("| Bulan ke |  bunga(%%)  |       saldo       |\n");
        printf("+----------+------------+-------------------+\n");

        fprintf(tabunganRencana,"NAMA TABUNGAN : %s\n",namaTabungan);
        fprintf(tabunganRencana,"+-------------------------------------------+\n");
        fprintf(tabunganRencana,"|             LAPORAN TABUNGAN              |\n");
        fprintf(tabunganRencana,"+----------+------------+-------------------+\n");
        fprintf(tabunganRencana,"| Bulan ke |  bunga(%%)  |       saldo       |\n");
        fprintf(tabunganRencana,"+----------+------------+-------------------+\n");

        summary=0;
    for(int x=1;x<=month;x++)
    {
        bunga = tabel(tabungan,x);
        show = bunga*100;

        sum = tabungan + TabunganBerencana(tabungan,bunga);
        summary = summary + sum;

        printf("| %-8d | %-10.1f | Rp.%-14.2lf |\n",x,show,summary);
        fprintf(tabunganRencana,"| %-8d | %-10.1f | Rp.%-14.2lf |\n",x,show,summary);
    }
    printf("+----------+------------+-------------------+\n");
    fprintf(tabunganRencana,"+----------+------------+-------------------+\n");

    printf("\nLaporan Deposito Dapat di Lihat pada file Laporan_Tabungan_Berencana.txt\n\n");
    printf("KEMBALI KE MENU?(y/n): ");scanf("%s",&opp);
    system("cls");
    fclose(tabunganRencana);
    }

    }while(opp=='y');

    return 0;
}
