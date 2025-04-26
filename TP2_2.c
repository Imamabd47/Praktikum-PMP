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