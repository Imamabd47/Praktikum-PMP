/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 3 - Structures and Dynamic Arrays
 *   Hari dan Tanggal    : Selasa, 6 Mei 2025
 *   Nama (NIM)          : Imam Ahmad Abdullah (13223050)
 *   Nama File           : soal2.c
 *   Deskripsi           : Membaca File.txt yang berisi list pasien sertam mencari data pasien dari input nama
 * 
 */


 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
 typedef struct 
 {
    char Nama[10];
    int umur;
    float BB;
    char Darah[5];

 }Template;
  
 Template *Rumah_sakit = NULL;

 void nambah(int i, char nama[10], int umur, float BB, char Darah[5]){
    if(Rumah_sakit == NULL){
        Rumah_sakit = malloc((i+1)*sizeof(Template));
        Rumah_sakit[i].BB = BB;
        Rumah_sakit[i].umur = umur;
        strcpy(Rumah_sakit[i].Darah,Darah);
        strcpy(Rumah_sakit[i].Nama,nama);
    }
    else {
        Rumah_sakit = realloc(Rumah_sakit,(i+1)*sizeof(Template));
        Rumah_sakit[i].BB = BB;
        Rumah_sakit[i].umur = umur;
        strcpy(Rumah_sakit[i].Darah,Darah);
        strcpy(Rumah_sakit[i].Nama,nama);
    }
 }

void Pemisahan(char Kalimat[100],char *nama,int *umur,float *BB,char *Darah){
    int a = 0;
    char *token;
        token = strtok(Kalimat,",");
        while (token != NULL)
        {   
            switch (a)
            {
            case 0:
                strcpy(nama,token);
                break;
            case 1:
                *umur = atoi(token);
                break;
            case 2:
                *BB = atof(token);
                break;
            default:
                 strcpy(Darah,token);
                break;
            }
            a++;
            token = strtok(NULL,",");
        }
}

void cetak(int i){
    printf("%d. %s, %d tahun, %.1f kg, Golongan darah %s",i+1,Rumah_sakit[i].Nama,Rumah_sakit[i].umur,Rumah_sakit[i].BB,Rumah_sakit[i].Darah);
}

void Search(char nama_yang_dicari[20],int i){
    int j;
    for(j=0;j<i;j++){
        if (strcmp(Rumah_sakit[j].Nama,nama_yang_dicari)==0){
            printf("\nPasien ditemukan: %s, %d tahun, %.1f kg, Golongan darah %s\n",Rumah_sakit[j].Nama,Rumah_sakit[j].umur,Rumah_sakit[j].BB,Rumah_sakit[j].Darah);
            break;
        }
        
    }
}


 int main() {
    int i=0;
    char temp_nama[20];
    int temp_umur;
    float temp_BB;
    char temp_darah[5];

    FILE * Data;
    char Nama_File[20];
    char cari[20];
    char In[40];
    char Kalimat[100];
    fgets(In, 40,stdin);
    sscanf(In,"%s %s",Nama_File,cari);
    Data = fopen(Nama_File,"r");
    char *token;
    printf("Daftar pasien: \n");
    while (fgets(Kalimat,100,Data))
    {
       Pemisahan(Kalimat,temp_nama,&temp_umur,&temp_BB,temp_darah);
       nambah(i,temp_nama,temp_umur,temp_BB,temp_darah);
       cetak(i);
       i++;
    }
    Search(cari,i);
    printf("Jumlah total pasien: %d",i);
    fclose(Data);

    return 0;
 }
 
 
