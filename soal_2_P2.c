/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 2 - Data Manipulation and External Files 
 *   Hari dan Tanggal    : Senin, 28 April 2025
 *   Nama (NIM)          : Imam Ahmad Abdullah (13223050)
 *   Nama File           : soal2.c
 *   Deskripsi           : Mencari kode tersembunyi dari  manuskrip string berdasarkan kelipatan
 * 
 */
 #include <stdio.h>
 #include <string.h>
  
 void Pencarian_Kode(char *Arr,int Kelipatan){
    int i,index;
    index=0;
    for(i=1;*(Arr+i-1)!='\0';i++){
        if (i%Kelipatan==0){
            *(Arr+index)=*(Arr+i-1);
            index++;
        }
    }
    *(Arr+index)='\0';
    for ( i = 0; *(Arr+i)!='\0'; i++){
        if (*(Arr+i+1)=='\0')
            printf("%c",*(Arr+i));
        else
            printf("%c ",*(Arr+i));
    }
}

 int main() {
    char Manuskrip[50];
    int a,i;
    fgets(Manuskrip, 50, stdin);
    for (i = 0; i < 50; i++)
    {if(Manuskrip[i]=='\n')
        Manuskrip[i]='\0';
    }
    
    scanf("%d",&a);
    Pencarian_Kode(Manuskrip,a);
 }
 
