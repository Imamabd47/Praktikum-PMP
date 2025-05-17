/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 4 - Dynamic Structures
 *   Hari dan Tanggal    : Kamis, 22 Mei 2025
 *   Nama (NIM)          : Imam Ahmad Abdullah (13223050)
 *   Nama File           : soal 2 Tugas Pendahuluan Bagian Soal Pemrograman
 *   Deskripsi           : Membuat program untuk reverse word dari input dengan stack/queue(Pada program ini digunakan Stack)
 *  
 */

 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>

 struct node
 {
    char val;
    struct node *next;
 };
 
struct node *head = NULL;

void push(char Arr[20]){
    int i = 0;
    while(Arr[i]!='\0'){
        struct node *newnode = malloc(sizeof(struct node));
        newnode -> val = Arr[i];
        newnode -> next = head;
        head = newnode;
        i++;
    }
}

void pop(){
    struct node *temp = head;
    printf("Reversed string: ");
    while(temp != NULL){
        printf("%c",temp->val);
        temp = temp->next;
    }
}

void remove_n(char Arr[20]){
    int i;
    for ( i = 0; i < 20; i++){
        if (Arr[i]=='\n'){
            Arr[i]='\0';
            break;
        }
    }  
 }
int main(){
    char kata[20];
    printf("Enter a string: ");
    fgets(kata, 20,stdin);
    remove_n(kata);
    push(kata);
    pop(kata);
    return(0);
 }