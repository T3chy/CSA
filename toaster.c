#include <stdio.h>
#include <Windows.h>
#include <unistd.h>
struct toast
{
    int burnt;
    int cookedness;
    char* breadtype;
};
typedef struct toast toast;
toast toaster(toast slice,int power_setting) {
    printf("toaster noises...\n");
    toast temp;
    temp.breadtype = slice.breadtype;
    temp.cookedness = (slice.cookedness + power_setting) % 10;
    for (int i=0; i < power_setting; i++ ) {
        printf("tick \n");
        Sleep(1000);
    }
        if (slice.cookedness + power_setting >= 10) {
        temp.burnt = 1;
        printf("oops! you burned your toast :( \n");
    } else {
        temp.burnt = 0;
    }
    printf("ding!");
    return temp;
}
int main() {
    toast elamstoast = {0,0,"sourdough"};
    int selection;
    printf("how much would you like to toast your bread? \n");
    scanf("%d",&selection);
    printf("ok! toasting for %d seconds \n",selection);
    toaster(elamstoast,selection);
    return 0;
}
