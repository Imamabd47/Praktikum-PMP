/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 1 - Overview of C language
 *   Hari dan Tanggal    : Rabu, 23 April 2025
 *   Nama (NIM)          : Imam Ahmad Abdullah(13223050)
 *   Nama File           : soal2.c
 *   Deskripsi           : Membuat Program untuk mencari angka yang dapat mendapatkan target dari kombinasi dua angka dari deret  masukan
 * 
 */


#include <stdio.h>
#include <string.h>
 
void Valid(char Deret[100],int Target){
   int i,j;
   int a,b;
   char Arr_angka[10][4];
   a = 0;b=0;
   for ( i = 0; Deret[i]!='\0'; i++){
   if(Deret[i]!=' '){
        Arr_angka[a][b]=Deret[i];
        b+=1;
        }
    else{
        Arr_angka[a][b]='\0';
        a +=1;
        b=0;
    }
   }
   int n= sizeof(Arr_angka)/sizeof(Arr_angka[0]);
   int Angka[10]={0};
   Arr_angka[a][b]='\0';
   for ( i = 0; i<n; i++){
        sscanf(Arr_angka[i],"%d",&Angka[i]);
        if(Angka[i]==0)
            break;
   }

   int Arr_valid[10]={0};
   int val = 0;
   for(i=0;i<9;i++){
        for ( j = i+1; j<10 ;j++){
           if(Angka[i]+Angka[j]==Target){
            Arr_valid[i]=1;
            Arr_valid[j]=1;
            val = 1;
           }
        }        
   }
   if (val){
    printf("Kombinasi valid ditemukan:");
    for(i=0;i<10;i++){
        if(Arr_valid[i]){
            printf(" %d",Angka[i]);
        }
    }
   }
   else
    printf("Tidak ada kombinasi yang valid");
}   

int main() {
    int Target;
    char Deret[100];
    fgets(Deret, sizeof(Deret),stdin);
    scanf("%d", &Target);
    Valid(Deret,Target);
    return 0;
}
