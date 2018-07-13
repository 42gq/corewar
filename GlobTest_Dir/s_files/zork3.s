.name "zork3"
.comment "111222333"

l2:		sti r1, %:live, %1
		ld %100, r2
		st  r2, r3
		and r1, %0, r1
		add r1, r2, r4

live:	live %1
live2:	live %2
live3:	live %3
live4:	live %4
