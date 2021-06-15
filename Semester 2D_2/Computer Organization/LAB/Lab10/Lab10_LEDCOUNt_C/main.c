#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

int main()
{
    int pin[3] = {3,2,7};

    printf("LED Counting 0-7\n");

    if(wiringPiSetup()==-1){
        printf("Setting up problem ... Abort!");
        exit(1);
    }

    for(int i=0;i<3;i++){
        pinMode(pin[i],OUTPUT);
    }

    for(u_int8_t i=0;i<8;i++){
        digitalWrite(pin[0],i&0x01);
        digitalWrite(pin[1],(i&0x02)>>1);
        digitalWrite(pin[2],(i&0x04)>>2);
        delay(1000);
    }

    return 0;
}
