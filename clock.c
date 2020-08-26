#include<stdio.h>
#include <Windows.h>
#include <unistd.h>
struct time {
    int hour;
    int minute;
    int second;
};
typedef struct time time;
time tick(time currenttime) {
 if (currenttime.second < 59) {
     currenttime.second += 1;
     return currenttime;
 } else if (currenttime.second == 59) {
     currenttime.second = 0;
     if (currenttime.minute < 59) {
         currenttime.minute += 1;
         return currenttime;
     } else if (currenttime.minute == 59) {
         currenttime.minute = 0;
         if (currenttime.hour < 12) {
             currenttime.hour += 1;
             return currenttime;
         } else if (currenttime.hour == 12) {
             currenttime.hour = 0;
             return currenttime;
         }
     }
 }
}
void main() {
 time currenttime;
 currenttime.hour = 0;
 currenttime.minute = 0;
 currenttime.second = 0;
 time alarmtime;
 alarmtime.hour = 0;
 alarmtime.minute = 0;
 alarmtime.second = 10;
int i = 0;
 int rang = 0;
 while (rang == 0) {

    i++;
    if (i == 15) {
        return;
    }
     Sleep(1000);

    currenttime = tick(currenttime);
    if (currenttime.second == alarmtime.second && alarmtime.second == currenttime.second && alarmtime.hour == currenttime.hour) {
        printf("ring");
        rang = 1;
     return;
    } else {
        printf("tick \n");
    }
 }}

