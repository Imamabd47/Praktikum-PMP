/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 5 - Foundation Of Algorithm
 *   Hari dan Tanggal    : Rabu, 28 Mei 2025
 *   Nama (NIM)          : Imam Ahmad Abdullah (13223050)
 *   Nama File           : soal1.c
 *   Deskripsi           : Mencari jumlah candy minimum yang akan diberikan kepada siswa dengan aturan yang diberikan
 * 
 */


 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
  
 struct candy {
    int jumlah_candy;
    int kepandaian;
    struct candy *next;
    struct candy *before;
 };

 void terakhir_null(char *arr){
    int i;
    while (1){
        if (*(arr+i)=='\n'){
            *(arr+i)='\0';
            break;
        }
        i++;
    }
 }

 struct candy *list_siswa = NULL;
 struct candy *first = NULL;

 //Fungsi untuk membuat link list dari masukan integer yang diberikan fungsi list
 void nambah(int c){
    struct candy *temp = malloc(sizeof(struct candy));
    temp -> jumlah_candy = 1;
    temp -> kepandaian = c;
    temp -> next = NULL;
    if (list_siswa == NULL){
        temp -> before = NULL;
        first = temp;
    }
    else{
        temp->before = list_siswa;
        list_siswa -> next =  temp;
    }
    list_siswa = temp;
 }

//Fungsi untuk memisah kan string menjadi integer dan diberikan ke fungsi nambah
 void list(char nama[20]){
    int  i ;
    char *token = strtok(nama," ");
    while (token!= NULL){
        sscanf(token,"%d",&i);
        nambah(i);
        token = strtok(NULL," ");
    }
 }

 //Fungsi yang digunakan hanya untuk mengecek apakah fungsi list dan nambah sudah benar|Tidak digunakan pada main, hanya digunakan dalam proses debug
 void printlist(){
    struct candy *temp = first;
    while (temp !=NULL){
        printf("%d ",temp->kepandaian);
        temp = temp->next;
    }
 }

 //Fungsi untuk menambah permen bila dirinya lebih pandai dari tetangga kanannya
 void penambahan_candy_kanan(){
    struct candy *temp = first;
    struct candy *temp_next = temp->next;
    while (temp!=list_siswa){
        if (((temp->kepandaian) > (temp_next ->kepandaian))&&(temp->jumlah_candy==temp_next->jumlah_candy)){
            temp->jumlah_candy = (temp->jumlah_candy)+1;
        }
        temp = temp->next;
        temp_next = temp->next;      
    }
 }

 //Fungsi untuk menambahkan permen bila dirinya lebih pandai dari tetangga kirinya
 void penambahan_candy_kiri(){
    struct candy *temp = list_siswa;
    struct candy *temp_before = temp->before;
    while (temp!=first){
        if (((temp->kepandaian) > (temp_before ->kepandaian))&&(temp->jumlah_candy==temp_before->jumlah_candy)){
            temp->jumlah_candy = (temp->jumlah_candy)+1;
        }
        temp = temp->before;
        temp_before = temp->before;      
    }
 }
 
 //Fungsi integrasi Penambahan candy kanan dan kiri, serta berguna untuk mengecek apakah permen yang diberi sudah sesuai dengan aturan
 void penambahan_candy(){
    int a = 0;
    //menambah candy dilihat dari dia ke sisi kanannya
    penambahan_candy_kanan();
    struct candy *temp = first;
    struct candy *temp_next = temp->next;
    //cek apakah masih ada yg blm sesuai aturan dilihat dari kiri ke kanan
    while (temp != list_siswa){
         if (((temp->kepandaian) > (temp_next ->kepandaian))&&(temp->jumlah_candy==temp_next->jumlah_candy)){
            a = 1;
            break;
        }
        temp = temp->next;
        temp_next = temp->next;    
    }

    //Menambah candy dilihat dari dia ke tetangga kirinya
    penambahan_candy_kiri();
    temp = list_siswa;
    struct candy *temp_before = temp->before;
    //Mengecek  apakah sudah sesuai  aturan dilihat dari kanan ke kiri
    while (temp!=first){
        if (((temp->kepandaian) > (temp_before ->kepandaian))&&(temp->jumlah_candy==temp_before->jumlah_candy)){
            a = 1;
            break;
        }
        temp = temp->before;
        temp_before = temp->before;      
    }
    if (a){
        penambahan_candy();
    }
 }

 //Fungsi untuk mengecek jumlah candy tiap siswa apakah sudah sesuai dengan aturan|Tidak digunakan pada main, hanya digunakan dalam proses debug
void printf_candy(){
    struct candy *temp_print = first;
    while (temp_print !=NULL){
        printf("%d ",temp_print->jumlah_candy);
        temp_print = temp_print->next;
    }
}

 //Fungsi yang digunakan untuk menghitung jumlah permen minimum dilihat dari fungsi penambahan candy
void Hitung(){
    penambahan_candy();
    struct candy *temp = first;
    int min = 0;
    while (temp!=NULL){
        min += temp->jumlah_candy;
        temp = temp->next;
    }
    printf("Output : %d candy",min);
}

//Main Program
 int main() {
    char siswa[30];
    char nama_file[20];
    fgets(nama_file,20,stdin);terakhir_null(nama_file);
    FILE *fptr;
    fptr = fopen(nama_file,"r");
    fgets(siswa,30,fptr);
    list(siswa);
    Hitung();
    return 0;
 }
 
