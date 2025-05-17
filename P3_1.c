/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 3 - Structures and Dynamic Array
 *   Hari dan Tanggal    : Selasa, 06 Mei 2025
 *   Nama (NIM)          : Imam Ahmad Abdullah (13223050)
 *   Nama File           : soal1.c
 *   Deskripsi           : Membuat Program yang mampu mencari urutan angka menuju 1 ditinjau dari bilangan ganjil atau genap
 * 
 */


 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>

 typedef struct {
    int value,odd,even;
 }misteri;
 
misteri *Kalender = NULL;

 void nambah(int value, int a,int temp_o,int temp_e){
    if(Kalender == NULL){
        Kalender = malloc((a+1)*sizeof(misteri));
        Kalender[a].value = value;
        Kalender[a].odd = 0;
        Kalender[a].even = 0;
    }
    else {
        Kalender = realloc(Kalender, (a+1)*sizeof(misteri));
        Kalender[a].value = value;
        Kalender[a].even = temp_e;
        Kalender[a].odd = temp_o;
    }
 }
 int main() {
    int i = 0;
    int temp_val = 0;
    int temp_odd = 0;
    int temp_even = 0;
    int a;
    scanf("%d",&temp_val);
    nambah(temp_val,i,temp_odd,temp_even);
    while (Kalender[i].value!=1){
        temp_val = Kalender[i].value;
        temp_even = Kalender[i].even;
        temp_odd = Kalender[i].odd;

        if(temp_val % 2 == 1){
            temp_val = (3*temp_val) + 1;
            temp_odd += 1;
        }
        else {
            temp_val /= 2 ;
            temp_even += 1;
        }
        i++;
        nambah(temp_val,i,temp_odd,temp_even);
    }
    printf("Value:");

    for(a=0;a<i+1;a++){
        if (a == i)
            printf("% d\n",Kalender[a].value);
        else
            printf("% d",Kalender[a].value);
    }
    
    printf("Odd:");
    for(a=0;a<i+1;a++){
        if (a == i)
            printf("% d\n",Kalender[a].odd);
        else
            printf("% d",Kalender[a].odd);
    }

    printf("Even:");
    for(a=0;a<i+1;a++){
        printf("% d",Kalender[a].even);
    }
    
   return 0;
 }

