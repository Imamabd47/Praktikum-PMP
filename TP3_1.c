#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *nama;
    int NIM,pemilihanSoal,test1,test2,test3,test4,test5;
}Praktikan;

int valid = 0;
Praktikan *Mahasiswa=NULL;
int a = 0;
void terakhir_null(char *Arr){
    int i;
    for(i=0;i<50;i++){
        if(*(Arr+i)=='\n'){
            *(Arr+i)='\0';
            break;}
    }
}

void nambah(){
    char nama[50];
    int NIM,pemilihanSoal,test1,test2,test3,test4,test5;

    if(Mahasiswa==NULL)
        Mahasiswa = malloc((a+1)*sizeof(Praktikan));
    else 
        Mahasiswa = realloc(Mahasiswa,(a+1)*sizeof(Praktikan));

    printf("\nMasukkan Nama Praktikan: ");fgets(nama,50,stdin);fgets(nama,50,stdin);terakhir_null(nama);
    printf("Masukkan NIM Praktikan: ");scanf("%d",&NIM);
    printf("Masukkan nomor soal yang dipilih praktikan: ");scanf("%d",&pemilihanSoal);
    printf("Masukkan Nilai dari Test Case 1 hingga 5 secara berurutan dipisahkan Spasi: ");
    scanf("%d %d %d %d %d",&test1,&test2,&test3,&test4,&test5);
    Mahasiswa[a].nama = malloc(strlen(nama) + 1);strcpy(Mahasiswa[a].nama,nama);
    Mahasiswa[a].NIM = NIM;
    Mahasiswa[a].pemilihanSoal = pemilihanSoal;
    Mahasiswa[a].test1 = test1;
    Mahasiswa[a].test2 = test2;
    Mahasiswa[a].test3 = test3;
    Mahasiswa[a].test4 = test4;
    Mahasiswa[a].test5 = test5;
    a++;
    printf("!!!SELAMAT DATA PRAKTIKAN SUDAH DITAMBAHKAN!!!\n");
    
}

void muncul_NIM(){
    int i;
    printf("\nData Praktikan Yang Tersedia: \n");
    for(i=0;i<a;i++){
        printf("[%d] %d\n",i+1, Mahasiswa[i].NIM);
    }
    printf("\n[0] Untuk CANCEL!!!\n");
}

void Lihat(){
    int i;
    int identify_NIM;
    if(a==0)
        printf("\nMaaf Belum ada data Praktikan yang masuk!!!\n");
    else if(a==1){
            printf("\nBerikut Data Praktikan yang bernama %s", Mahasiswa[a-1].nama);
            printf(" Dengan NIM %d\n",Mahasiswa[a-1].NIM);
            printf("Mengerjakan soal nomor %d dengan nilai test case sebagai berikut:\n",Mahasiswa[a-1].pemilihanSoal);
            printf("test case 1: %d\n",Mahasiswa[a-1].test1);
            printf("test case 2: %d\n",Mahasiswa[a-1].test2);
            printf("test case 3: %d\n",Mahasiswa[a-1].test3);
            printf("test case 4: %d\n",Mahasiswa[a-1].test4);
            printf("test case 5: %d\n",Mahasiswa[a-1].test5);
    }
    else {
    muncul_NIM();
    valid = 0; 
    printf("\nMasukkan NIM dari data praktikan yang ingin dilihat: ");
    scanf("%d", &identify_NIM);
    if(identify_NIM!= 0){
        for (i=0; i<a+1;i++){
            if(Mahasiswa[i].NIM == identify_NIM){
                printf("\nBerikut Data Praktikan yang bernama %s", Mahasiswa[i].nama);
                printf(" Dengan NIM %d\n",Mahasiswa[i].NIM);
                printf("Mengerjakan soal nomor %d dengan nilai test case sebagai berikut:\n",Mahasiswa[i].pemilihanSoal);
                printf("test case 1: %d\n",Mahasiswa[i].test1);
                printf("test case 2: %d\n",Mahasiswa[i].test2);
                printf("test case 3: %d\n",Mahasiswa[i].test3);
                printf("test case 4: %d\n",Mahasiswa[i].test4);
                printf("test case 5: %d\n",Mahasiswa[i].test5);
                valid = 1;
                break;}
            }
        if(valid == 0){
            printf("\nMaaf NIM praktikan yang anda masukkan Tidak ditemukan!!!\n");
            Lihat();
            }
        }
    }
}



void ubah(){
    int identify_NIM,i;
    if(a==0)
        printf("\nMaaf Belum ada data Praktikan yang masuk!!!\n");
    else if (a==1){
        printf("Masukkan Perubahan nomor soal yang dikerjakan praktikan: ");
        scanf("%d",&Mahasiswa[a-1].pemilihanSoal);
        printf("!!!SELAMAT DATA PRAKTIKAN SUDAH DI-UPDATE!!!\n");
    }
    else {
        muncul_NIM();
        valid = 0;
        printf("Masukkan NIM praktikan yang ingin diubah data pengerjaan nomor soal: ");
        scanf("%d", &identify_NIM);
        if(identify_NIM!=0){
            for (i=0; i<a+1;i++){
                if(Mahasiswa[i].NIM == identify_NIM){
                    printf("Masukkan Perubahan nomor soal yang dikerjakan praktikan: ");
                    scanf("%d",&Mahasiswa[i].pemilihanSoal);
                    valid = 1;
                    printf("!!!SELAMAT DATA PRAKTIKAN SUDAH DI-UPDATE!!!\n");
                    break;
                }
            }
            if(valid == 0){
                printf("\nMaaf NIM praktikan yang anda masukkan Tidak ditemukan!!!\n");
                ubah();
            }
        }
    }
}

void test_case(){
    int identify_NIM,i;
    if(a==0)
        printf("\nMaaf Belum ada data Praktikan yang masuk!!!\n");
    else if (a==1){
        printf("Masukkan Hasil test case 1 - 5 yang baru secara berurutan dengan spasi sebagai pemisah: ");
        scanf("%d %d %d %d %d",&Mahasiswa[a-1].test1,&Mahasiswa[a-1].test2,&Mahasiswa[a-1].test3,&Mahasiswa[a-1].test4,&Mahasiswa[a-1].test5);
        printf("!!!SELAMAT DATA PRAKTIKAN SUDAH DI-UPDATE!!!\n");
    }
    else {
        muncul_NIM();
        valid = 0;
        printf("Masukkan NIM praktikan yang ingin diubah data Nilai test casenya: ");
        scanf("%d", &identify_NIM);
        if(identify_NIM!=0){
            for (i=0; i<a+1;i++){
                if(Mahasiswa[i].NIM == identify_NIM){
                    printf("Masukkan Hasil test case 1 - 5 yang baru secara berurutan dengan spasi sebagai pemisah: ");
                    scanf("%d %d %d %d %d",&Mahasiswa[i].test1,&Mahasiswa[i].test2,&Mahasiswa[i].test3,&Mahasiswa[i].test4,&Mahasiswa[i].test5);
                    valid = 1;
                    printf("!!!SELAMAT DATA PRAKTIKAN SUDAH DI-UPDATE!!!\n");
                    break;
                }
            }
            if(valid == 0){
                printf("\nMaaf NIM praktikan yang anda masukkan Tidak ditemukan!!!\n");
                test_case();
            }
        }
    }
}
void total(){
    int identify_NIM,i,sum;
    if(a==0)
        printf("\nMaaf Belum ada data Praktikan yang masuk!!!\n");
    else if (a==1){
        sum = Mahasiswa[a-1].test1 + Mahasiswa[a-1].test2 + Mahasiswa[a-1].test3 + Mahasiswa[a-1].test4 + Mahasiswa[a-1].test5;
        printf("\nBerikut merupakan Hasil Total Nilai Test Case 1-5: %d\n", sum);
        printf("Yang merupakan penjumlahan dari %d + %d + %d + %d + %d\n",Mahasiswa[a-1].test1,Mahasiswa[a-1].test2,Mahasiswa[a-1].test3,Mahasiswa[a-1].test4,Mahasiswa[a-1].test5);
    }
    else {
        muncul_NIM();
        valid = 0;
        printf("Masukkan NIM praktikan yang ingin dicari total Nilai test case  yang didapat: ");
        scanf("%d", &identify_NIM);
        if(identify_NIM!=0){
            for (i=0; i<a+1;i++){
                if(Mahasiswa[i].NIM == identify_NIM){
                    sum = Mahasiswa[i].test1 + Mahasiswa[i].test2 + Mahasiswa[i].test3 + Mahasiswa[i].test4 + Mahasiswa[i].test5;
                    printf("\nBerikut merupakan Hasil Total Nilai Test Case 1-5: %d\n", sum);
                    printf("Yang merupakan penjumlahan dari %d + %d + %d + %d + %d\n",Mahasiswa[i].test1,Mahasiswa[i].test2,Mahasiswa[i].test3,Mahasiswa[i].test4,Mahasiswa[i].test5);
                    valid=1;
                    break;
                }
            }
            if(valid == 0){
                printf("\nMaaf NIM praktikan yang anda masukkan Tidak ditemukan!!!\n");
                total();
            }
        }
    }   
}
int main(){

    int perintah = 0;
    printf("!!!SELAMAT DATANG ASISTEN PRAKTIKUM EZ2008!!!\n");
    while (perintah != 6){
        printf("\n\nApa yang ingin Anda Lakukan:\n[1] Menambah Data Praktikan Baru\n[2] Mengubah Pemilihan Soal\n[3] Mengubah hasil test case\n[4] Melihat Nilai total Praktikan\n[5] Melihat Data Praktikan\n[6] Untuk Selesai\n\nPerintah: ");
        scanf("%d",&perintah);
        if(perintah==1)
            nambah();
        else if(perintah == 2)
            ubah();
        else if(perintah == 3)
            test_case();
        else if(perintah == 4)
            total();
        else if(perintah == 5)
            Lihat();
        else if(perintah == 6)
            printf("\nTerimakasih Sudah Berkunjung ke Pusat Pangkalan Data Praktikan Praktikum EZ2008\n======================Pemecahan Masalah Yang Tidak Selesai======================\n");
        else
            printf("\nMaaf Perintah Yang Anda masukkan salah!!!\n");
        }
    return 0;
}