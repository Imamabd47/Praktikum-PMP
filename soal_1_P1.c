#include <stdio.h>
#include <string.h>

int main(){
    //Deklarasi Array of char
    char Kode[10];
    int i,Index;
    int sum_huruf=0;
    int sum_angka=0;
    int Arr_huruf[26] = {0};
    int Arr_angka[10] = {0};

    //Masukkan Kode
    scanf("%s",&Kode);

    //Validasi Kode terdiri dari 10 Karakter
    if (strlen(Kode)!=10){
        printf("Kode tidak valid ");
        return 0;}

    for (i=0;i<10;i++){
        Index = Kode[i];
        
        if ((Index<48)||(57<Index&&Index<65)||(Index>90)){ //Validasi hanya berisi Huruf Besar(A-Z) dan Angka(0-9)
            printf("Kode tidak valid ");
            return 0;}
        if (47<Index&&Index<58){
            sum_angka += 1;
            Arr_angka[Index-48] += 1;
            if (Arr_angka[Index-48]>1){
                printf("Kode tidak valid ");
                return 0;
                }
            }
        else {
            sum_huruf += 1;
            Arr_huruf[Index-65] += 1;
            if (Arr_huruf[Index-65]>1){
                printf("Kode tidak valid ");
                return 0;
            }
        }
    }
    if ((sum_angka<2)||(sum_huruf<2)){//Validasi minimal 2 huruf dan angka
        printf("Kode tidak valid ");
        return 0;
    }
    //Lulus Aturan Validasi - Kode Valid
    printf("Kode valid");
    return 0;
}