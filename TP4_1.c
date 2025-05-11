/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 4 - Dynamic Structures
 *   Hari dan Tanggal    : Kamis, 22 Mei 2025
 *   Nama (NIM)          : Imam Ahmad Abdullah (13223050)
 *   Nama File           : soal 1 Tugas Pendahuluan Bagian Soal Pemrograman
 *   Deskripsi           : Membuat program untuk menyimpan data prajurit, memperlihatkan seluruh data, serta menghapus data tertentu
 * 
 */


#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct prajurit
{
    char nama[100];
    int nomor;
    float IPK;
    struct prajurit *before;
    struct prajurit *next;
};

struct prajurit *data = NULL;

void terakhir_null(char *kalimat){
    int i = 0;
    while(1){
        if(*(kalimat+i)=='\n'){
            *(kalimat+i) = '\0';
            break;
        }
        i++;
    }
}

void nambah(){
    char nama[100];int nomor;float ipk;;fgets(nama,100,stdin);
    printf("\nMasukkan Nama Prajurit: ");fgets(nama,100,stdin);terakhir_null(nama);
    printf("Masukkan Nomor Kode Prajurit: ");scanf("%d",&nomor);
    printf("Masukkan Nilai IPK Prajurit: ");scanf("%f",&ipk);
    struct prajurit *temp = malloc(sizeof(struct prajurit));
    strcpy(temp->nama,nama);
    temp -> nomor = nomor;
    temp -> IPK = ipk;
    if (data == NULL){
        temp -> before = NULL; }
    else {
        temp -> before = data;
        data -> next = temp;
        }
    temp -> next = NULL;
    data = temp;

    printf("Selamat Data Prajurit Bernama %s dengan Kode %d ber-IPK %.2f telah ditambahkan!!!\n",temp->nama,temp->nomor,temp->IPK);
}
    

void hapus(){
    struct prajurit *temp;
    struct prajurit *temp_before;
    struct prajurit *temp_next;
    int Id;
    int a = 1;
    if (data != NULL){
        printf("\nMasukkan Kode Prajurit Yang Ingin Dihilangkan< ");
        scanf("%d",&Id);
        temp = data;
        while(temp != NULL){
            if((temp->nomor)==Id){
                temp_next = temp->next;
                temp_before = temp -> before;
                if((temp_before == NULL)&&(temp_next==NULL)){
                    data = temp_before;
                }
                else if(temp_before == NULL){
                    temp_next -> before = temp_before;
                }
                else if(temp_next == NULL){
                    temp_before -> next = temp_next;
                    data = temp_before;
                }
                else {
                    temp_before -> next = temp_next;
                    temp_next -> before = temp_before;
                }
                printf("Selamat Data Prajurit Bernama %s Dengan Kode Prajurit %d yang memiliki nilai IPK %.2f Telah dihapus\n",temp->nama,temp->nomor,temp->IPK);
                free(temp);
                a = 0;
                break;
            }
            temp = temp->before;
        }
        if(a){
            printf("Maaf Kode Prajurit yang dicari tidak ditemukan!!!\n");
        }
    }
    else {
        printf("\nMaaf Belum ada data Prajurit yang dimasukkan!!!\n");
    }
}


void tampil(){
    struct prajurit *temp;
    temp = data;
    if(temp != NULL){
        int a = 1;
        printf("\nno ||%13s%s%13s||%5s%s%5s ||%5s%s%5s\n"," ","Nama"," "," ","Kode Prajurit"," "," ","IPK Prajurit"," ");
        while(temp!=NULL){
            printf("%-3d||",a);
            printf("%-25s%5s||",temp->nama," ");
            printf("%8s%d%8s||"," ",temp->nomor," ");
            printf("%12.2f\n",temp->IPK);
            temp = temp->before;
            a++;
            }
    }
    else {
        printf("\nMaaf Belum ada data Prajurit yang dimasukkan!!!\n");
    }
}

int main(){
    int perintah,Id;
    printf("Silahkan Pilih Perintah Berikut:\n[1]Menambah Data Prajurit\n[2]Menghapus Data Prajurit\n[3]Menampilkan Seluruh Data Prajurit\n[4]Keluar Dari Program\n\nPerintah: ");
    scanf("%d",&perintah);
    while(perintah!= 4){
        switch (perintah)
        {
            case 1:
                nambah();
                break;
            case 2:
                hapus();
                break;
            case 3:
                tampil();
                break;
            case 4:
                break;
            default:
                printf("\nMaaf Perintah yang anda masukkan salah!!!\n");
                break;
        }
        printf("\nSilahkan Pilih Perintah Berikut:\n[1]Menambah Data Prajurit\n[2]Menghapus Data Prajurit\n[3]Menampilkan Seluruh Data Prajurit\n[4]Keluar Dari Program\n\nPerintah: ");
        scanf("%d",&perintah);
    }
    return (0);
}
