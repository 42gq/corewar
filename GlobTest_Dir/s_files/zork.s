.name "zork"
.comment "I'M ALIIIIVE"

l2:		sti r1, %:live, %1
		and r1, %0, r1
		ld %1111111111111111, r4
		ld %-100000000, r4
		ld %-11111111111111, r4
		live %-11111111111111
live:	live %1
		zjmp %:live
