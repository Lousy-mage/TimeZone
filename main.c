#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ZaWarudo.h"
#include<ctype.h>

int cSearch(char*country){
    char line[1024];
    int i=0;
    FILE *filePtr=fopen("C:\\Users\\HP\\Downloads\\TimeZone-main\\countries.txt","r");
    if(filePtr!=NULL){
        while(fgets(line,sizeof(line),filePtr)){
        line[strcspn(line, "\n")] = '\0';
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
    FILE *filePtr=fopen("C:\\Users\\HP\\Downloads\\TimeZone-main\\timeoffset.txt","r");
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
      //  world();
        printf("\n");
        char country1[30],country2[30];
        int option;
        int Hour,Minute;
        int Offset[2];
        int off;
        int i1,i2;
        printf("                                               WELCOME TO THE WORLD CLOCK\n");
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        printf(" Enter the name of the source country (current time reference): ");
        gets(country1);
        for(int i=0;i<strlen(country1);i++)
        {
            country1[i]=tolower(country1[i]);
        }
        Offset[0]=cSearch(country1);
        printf(" Enter the name of the target country (to calculate respective time): ");
        gets(country2);
        for(int i=0;i<strlen(country2);i++)
        {
            country2[i]=tolower(country2[i]);
        }
        Offset[1]=cSearch(country2);
        i1=tSearch(Offset[0]);
        i2=tSearch(Offset[1]);
        int i1_hours = i1 / 60;
        int i1_minutes = i1 % 60;
        int i2_hours = i2 / 60;
        int i2_minutes = i2 % 60;
        printf("\n Time offset for %s: %d hours and %d minutes\n", country1, i1_hours, i1_minutes);
        printf(" Time offset for %s: %d hours and %d minutes\n", country2, i2_hours, i2_minutes);
        printf("\n Enter the time[24 hour clock] of source country:  ");
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
        printf("\n Time in the target country:  %02d:%02d \n",Hour,Minute);
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        system(" color 70");
        return 0;
    }