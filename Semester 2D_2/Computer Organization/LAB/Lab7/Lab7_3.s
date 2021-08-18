	.data
primes:
	.word 2
	.word 3
	.word 5
	.word 7

	.text
	.global main
main:
	LDR R3, =primes     @ Load address for data in R3
	LDR R0, [R3, #4]    @ get item in list
end:
	BX LR
