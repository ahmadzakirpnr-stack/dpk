#include <stdio.h>
#include <stdlib.h>

int maks(int a, int b) {// past by value 
if (a > b)
return a;
if (a < b)
return b;
}

int main() {
        int nilaia, nilaib;
        nilaia = 75;
        nilaib = 100;
        printf("niali yagn lebih besar adalah %d\n",maks(nilaia,nilaib));
        int nilaimaks = maks(267,106);
        printf("nilai maksimum dari 267 dan 106 adalah %d\n", nilaimaks);
        return 0;
}