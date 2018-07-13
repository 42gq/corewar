.name "new"
.comment "some moves"

o1:		live %1
o2:		live %1
o3:		live %1
o4:		live %1
o5:		live %1
		live %2863311530
		live %2863311530
		live %2863311530
		live %2863311530
		live %-1
o6:		fork %-5
op:		ld %:o6, r2
		ld %-1, r3
		ld %50, r4
		ld %-50, r5
		ld 0, r6
		ld 1, r7
		ld 2, r8
		ld 2048, r9
		ld 100000, r10
		sti r1, %:o1, %1
		sti r2, %:o2, %1
		sti r3, %:o3, %1
		sti r4, %:o4, %1
		sti r5, %:o5, %1
		ld %0, r11
		zjmp %:o1
