/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 2 - Data Manipulation and External Files
 *   Hari dan Tanggal    : Senin, 28 April 2025
 *   Nama (NIM)          : Imam Ahmad Abdullah (13223050)
 *   Nama File           : Tp2_Soal2.c
 *   Deskripsi           : Membaca file eksternal dan mengeluarkan output tiap baris beserta panjangnya
 * 
 */
#include <stdio.h>
#include <string.h>
int main(){
    int i;
    FILE *Buah;
    Buah = fopen("input.txt","r");
    char Fruit[4][10];
    for(i=0;i<4;i++){
        fgets(Fruit[i],10,Buah);
    }

    for ( i = 0; i < 4; i++){
        printf("string%5c: %s",' ',Fruit[i]);
        printf("Panjang%4c: %d\n\n",' ',strlen(Fruit[i])-1);
    }
    
}