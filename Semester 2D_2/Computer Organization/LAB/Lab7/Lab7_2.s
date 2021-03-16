	.data
	.balign 4             @ Request 4 byte of space
fifteen:	.word    0    @ fifteen = 15
	.balign 4             @ Request 4 byte of space
thirty:		.word    0    @ thirty = 30

	.text
	.global main
main:
	LDR R1, addr_fifteen    @ R1 <- address_fifteen
	MOV R3, #15             @ R3 <- 15
	STR R3, [R1]            @ Mem[address_fifteen] <- R3
	LDR R2, addr_thirty     @ R2 <- address_thirty
	MOV R3, #30             @ R3 <- 30
	STR R3, [R2]            @ Mem[address_thirty] <- R2

	LDR R1, addr_fifteen    @ Load address
	LDR R1, [R1]            @ R1 <= Mem[address_fifteen]
	LDR R2, addr_thirty     @ Load address
	LDR R2, [R2]            @ R2 <- Mem[address_thirty]
	ADD R0, R1, R2
end:
	BX LR

@ label for addresses in data section
addr_fifteen:	.word fifteen
addr_thirty:	.word thirty

