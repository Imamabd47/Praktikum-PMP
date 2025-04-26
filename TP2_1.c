#include <stdio.h>
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