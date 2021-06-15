#include <stdio.h>
#include <stdint.h>
#include <wiringPi.h>
int myDelay = 1000;

#define BUTTON_PIN 0
volatile int whenPush = 0;
void myInterrupt2(void) {
        whenPush++; // the event counter
        if (myDelay > 250){
            myDelay=myDelay/2;
        } else myDelay = 1000;
}

int main(void)
{
    int pin[3] = {3,2,7};
    printf("LED Counting 0-7\n");

    if(wiringPiSetup()==-1){
        printf("Setting up problem ... Abort!");
        return 1;
    }

    if (wiringPiISR (BUTTON_PIN, INT_EDGE_FALLING, &myInterrupt2) < 0){
        return 2; // error code = 2
    }

    for(int i=0;i<3;i++){
        pinMode(pin[i],OUTPUT);
    }

    uint8_t i = 0;
    while(1)
    {
        printf("%d\n", whenPush);
        if(whenPush > 3){
            whenPush = 0;
        };

        digitalWrite(pin[0],i&0x01);
        digitalWrite(pin[1],(i&0x02)>>1);
        digitalWrite(pin[2],(i&0x04)>>2);
        delay(myDelay);

        if (i<8){i++;}
        else i = 0;
    }

    return 0;
}
