/*

Features:
- Select Country for time conversion
- Select Country to convert into
- All Officially recogonized country's standard time zone will be taken as the measure

- Scope for Live Time???


Implementation:
- A zones.txt file will be created which stores the time std time zone of all countries with an
    index number
- A countries.txt will be created containing the country names in alphabetic order

###begin:
- Display prompt to enter country names and time.
- When a country name is entered, search in country.txt using binary search
- if found, return index
- use index to find the time zone.
- convert the time input in the form HH:mm to minutes or seconds since midnight.
- the add or subtract the time-offset in the same format(i.e., seconds or minutes since midnight)
- convert to HH:mm format.
- Wait for keyboard input then repeat from begin.

*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #include "ZaWarudo"


int cSearch(char*country){
    char line[1024];
    int i=0;
    FILE *filePtr=fopen("/home/mage/TimeZone/countries.txt","r");
    if(filePtr!=NULL){
        while(fgets(line,sizeof(line),filePtr)){
        line[strcspn(line, "\n")] = '\0';
        if (strcmp(line, country) == 0) {
            fclose(filePtr);
            return i; // Found the country
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
    // world();
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
        country1[strcspn(country1, "\n")] = '\0';
        Offset[0]=cSearch(country1);
        printf("Enter Country2\n");
        fgets(country2,30,stdin);
        country2[strcspn(country2, "\n")] = '\0';
        Offset[1]=cSearch(country2);
        i1=tSearch(Offset[0]);
        i2=tSearch(Offset[1]);


        printf("offset0= %d\n",i1);
        printf("offset1= %d\n",i2);


 //   }while(option!=0);




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