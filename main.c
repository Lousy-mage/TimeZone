#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ZaWarudo.h"

int cSearch(char*country){
    char line[1024];
    int i=0;
    FILE *filePtr=fopen("/home/mage/TimeZone/countries.txt","r");
    if(filePtr!=NULL){

        unsigned char bom[3];
        if (fread(bom, 1, 3, filePtr) != 3 ||
            bom[0] != 0xEF || bom[1] != 0xBB || bom[2] != 0xBF) {
            
            rewind(filePtr);
        }
        while(fgets(line,sizeof(line),filePtr)){
        line[strcspn(line, "\r")] = '\0';
        if (strcmp(line, country) == 0) {
            fclose(filePtr);
            return i-1; // Found the country
        }
            i++;
        }
        fclose(filePtr);
        return -1;
    }

}

int tSearch(int index){
    char line[1024];
    int t,i=0;
    FILE *filePtr=fopen("/home/mage/TimeZone/timeoffset.txt","r");
    if(filePtr!=NULL){
        while(fgets(line,sizeof(line),filePtr)){
        if (i==index) {
            fscanf(filePtr,"%d",&t);
            //fseek(filePtr,t,index);
            fclose(filePtr);
            return t; // Found the country
        }
            i++;
        }
    fclose(filePtr);
    return -1;
    }
}

int main(){
    world();
    printf("\n");
    char country1[30],country2[30];
    int option;
    int Hour,Minute;
    int Offset[2];
    int off;
    int i1,i2;
 //   do{
        printf("Welcome to World clock\n");
        printf("---------------------------\n");
        printf("Enter country 1\n");
        fgets(country1,30,stdin);
        country1[strcspn(country1,"\n")]='\0';
        Offset[0]=cSearch(country1);
        printf("Enter Country2\n");
        fgets(country2,30,stdin);
        country2[strcspn(country2,"\n")]='\0';
        Offset[1]=cSearch(country2);
        i1=tSearch(Offset[0]);
        i2=tSearch(Offset[1]);


        printf("offset0= %d\n",i1);
        printf("offset1= %d\n",i2);


    printf("Enter The time of first country\n");
    scanf("%d:%d",&Hour,&Minute);
    
    off=Hour*60+Minute;
    if(i1>0)
        off-=i1;
    else
        off+=i1;

    if(i2>0)
        off+=i2;
    else
        off-=i2;

    Hour=off/60;
    Minute=off%60;
    if(Minute<0){
        Minute+=60;
        Hour-=1;
    }
    if(Hour<0){
        Hour+=24;
    }
    printf("%02d:%02d \n",Hour,Minute);

    return 0;
}