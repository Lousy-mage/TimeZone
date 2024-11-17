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
// struct Time{
// int Hour 5;
// int Minute;
// };
int main(){
    int Hour,Minute;
    int Offset[2];
    int off;

    printf("Enter The time of first country\n");
    scanf("%d:%d",&Hour,&Minute);
    off=Hour*60+Minute;
    if(Offset[0]>0)
        off-=Offset[0];
    else
        off+=Offset[0];

    if(Offset[1]>0)
        off+=Offset[1];
    else
        off-=Offset[1];

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