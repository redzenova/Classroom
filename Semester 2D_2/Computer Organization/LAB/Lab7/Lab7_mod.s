    .data
    .balign 4
message:    .asciz "[Input] Num1 mod Num2 = [Output]\n"
    .balign 4
get_num_1:  .asciz "Number 1 : "
    .balign 4
get_num_2:  .asciz "Number 2 : "

    .balign 4
pattern:    .asciz "%d"

    .balign 4
num_1: .word 0
    .balign 4
num_2: .word 0

    .balign 4
output: .asciz "%d mod %d = %d\n"

    .balign 4
lr_bu: .word 0
    .balign 4
lr_bu_2:    .word 0


    .text
@ Modulo Process
mod_func:
    LDR R2, =lr_bu_2
    STR lr,[R2]

mod_loop:
    CMP R0,R1
    BLT end_mod
    SUB R0, R0, R1
    BL mod_loop

end_mod:
    LDR lr,=lr_bu_2
    LDR lr,[lr]

    BX lr

    .global main
main:
    @ Backup Link Register
    LDR R1, =lr_bu
    STR lr,[R1]

    @ Print message
    LDR R0,=message
    BL printf

    @ Get num 1
    LDR R0,=get_num_1
    BL printf
    LDR R0, =pattern
    LDR R1, =num_1
    BL scanf

    @ Get num 2
    LDR R0, =get_num_2
    BL printf
    LDR R0, =pattern
    LDR R1, =num_2
    BL scanf

    @ Passing value and call modulo function
    LDR R0, =num_1
    LDR R0, [R0]
    LDR R1, =num_2
    LDR R1,[R1]
    BL mod_func

    MOV R3, R0

    @ Print Output
    LDR R0, =output
    LDR R1, =num_1
    LDR R1, [R1]
    LDR R2, =num_2
    LDR R2, [R2]
    BL printf

    LDR lr, =lr_bu
    LDR lr,[lr]
    BX lr


.global printf
.global scanf
