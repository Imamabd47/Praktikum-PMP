/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 2 - Data Manipulation and External Files
 *   Hari dan Tanggal    : Senin, 28 April 2025
 *   Nama (NIM)          : Imam Ahmad Abdullah (13223050)
 *   Nama File           : soal1.c
 *   Deskripsi           : Membuat kalimat yang terbalik per katanya
 * 
 */


 #include <stdio.h>
 #include <string.h>
void balik(char *Arr){
    int Banyak_kata,i,j;
    int panjang_kata[10]={0};
    int indeks=0;
    char temp;
    Banyak_kata = 1;
    for (i = 0; *(Arr+i)!='\0'; i++){
        if (*(Arr+i)!=' '){
            panjang_kata[Banyak_kata-1]+=1;
        }
        else {
            Banyak_kata+=1;
        }
    }
    for(i=0;i<Banyak_kata;i++){
        if (panjang_kata[i]%2==0){
            for (j=indeks;j< panjang_kata[i]+indeks; j++){
                if (j<(panjang_kata[i]/2)+indeks){
                    temp =*(Arr+j);
                    *(Arr+j) = *(Arr+panjang_kata[i]+indeks+indeks-j-1);
                    *(Arr+panjang_kata[i]+indeks+indeks-j-1) = temp;
                    printf("%c",*(Arr+j));
                }
                else{
                    if ((j==panjang_kata[i]+indeks-1)&&(i!=Banyak_kata-1))
                        printf("%c ",*(Arr+j));
                    else
                        printf("%c",*(Arr+j));
                }
            } 
            indeks += panjang_kata[i]+1;
        }
        else{
            for (j=indeks;j< panjang_kata[i]+indeks; j++){
                if (j<((panjang_kata[i]-1)/2)+indeks){
                    temp =*(Arr+j);
                    *(Arr+j) = *(Arr+panjang_kata[i]+indeks+indeks-j-1);
                    *(Arr+panjang_kata[i]+indeks+indeks-j-1) = temp;
                    printf("%c",*(Arr+j));
                }
                else{
                    if ((j==panjang_kata[i]+indeks-1)&&(i!=Banyak_kata-1))
                        printf("%c ",*(Arr+j));
                    else
                        printf("%c",*(Arr+j));
                }
            } 
            indeks += panjang_kata[i]+1;
        }    
    }
}
int main() {
    char Kata[50];
    int i;
    fgets(Kata,50,stdin);
    for (i = 0; i < 50; i++){
        if (Kata[i]=='\n'){
            Kata[i]='\0';break;
        }
    }
    balik(Kata);
}
 
