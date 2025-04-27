
/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 2 - Data Manipulation and External Files
 *   Hari dan Tanggal    : Senin, 28 April 2025
 *   Nama (NIM)          : Imam Ahmad Abdullah (13223050)
 *   Nama File           : Tp2_Soal1.c
 *   Deskripsi           : Membuat  fungsi perkalian dari tiap elemen indeks array of pointer
 * 
 */
#include <stdio.h>
#include <string.h>
void Perkalian(int *Arr){
    int hasil = 1;
    int i;
    for(i=0;i<5;i++){
        hasil *= Arr[i];
    }
    printf("\nHasil perkaliannya :\n");
    printf("%d",hasil);
}
int main(){
    int Arr_angka[5];
    int i;
    printf("Masukkan 5 angka: \n");
    for(i=0;i<5;i++){
        scanf("%d",&Arr_angka[i]);
    }
    Perkalian(Arr_angka);
}