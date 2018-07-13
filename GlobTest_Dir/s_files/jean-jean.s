.name "Real_Killah"
.comment "some moves
and more"

load:		ld %3, r3 ##int de 3 utilisable
			ld %4, r13 ##int de 4 utilisable
o1:			live %-1
			sti r1, %:o1, %1
			sti r1, %:o3, %1
			ld %1, r16
##o2:		fork %:o1
o3:			live %-1
			or r16, r15, r16
			zjmp %:attack
			ld %0, r16
##			zjmp %:o2
recharge:	ld %44, r4 ##size of attack, descend jusqu a 0 --> 28
			ld %86, r11 ##next_pos, descend jusqu a size of attack -->28
attack:		sti r1, %7, %1
			live %-1
			live %-1
			ldi %65520, r4, r10
			sti r10, r11, %0
			sub r4, r13, r4
			sub r11, r13, r11
			ld %0, r8
			zjmp %65489
