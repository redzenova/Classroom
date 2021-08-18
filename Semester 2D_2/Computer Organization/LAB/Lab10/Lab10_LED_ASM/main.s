#----------------------------------------------------
# DATA Segment
#----------------------------------------------------
            .data
            .balign 4
intro:      .asciz "LED Blinking by wiringPi\n"
errMsg:     .asciz "Setting up problem ... Abort!\n"
pin:        .int 7
i:          .int 0
duration:   .int 500
OUTPUT = 1

#----------------------------------------------------
# TEXT Segment
#----------------------------------------------------
            .text
            .global main
            .extern printf
            .extern wiringPiSetup
            .extern delay
            .extern digitalWrite
            .extern pinMode
main:   PUSH {ip,lr}
        LDR R0,=intro
        BL  printf
        BL  wiringPiSetup
        MOV R1,#-1
        CMP R0,R1
        BNE init
        LDR R0,=errMsg
        BL  printf
        B   done

init:   LDR R0, =pin
        LDR R0, [R0]
        MOV R1,#OUTPUT
        BL pinMode
        LDR R4, =i
        LDR R4, [R4]
        MOV R5,#10

forLoop:
        CMP R4,R5
        BGT done
        LDR R0,=pin
        LDR R0,[R0]
        MOV R1,#1
        BL digitalWrite
        LDR R0,=duration
        LDR R0,[R0]
        BL delay
        LDR R0,=pin
        LDR R0,[R0]
        MOV R1,#0
        BL digitalWrite
        LDR R0,=duration
        LDR R0,[R0]
        BL delay
        ADD R4,#1
        B forLoop

done:
        POP {ip,pc};
