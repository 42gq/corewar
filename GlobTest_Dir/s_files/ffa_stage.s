.name "zork2"
.comment "I'M ALIIIIVE"

		ld %31000, r2
l2:		sti r1, %:live, %1
		sti r2, %:l2, %100
		ld %4294966773, r3
		sti r3, %0, r3
		and r1, %0, r1

live:	live %1
		zjmp %:live
