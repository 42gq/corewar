.name "lldi"
.comment "REG | DIR | IND, DIR | REG, REG"

lldi %0, r1, r2
lldi %5, r2, r3
lldi %-5, r3, r4
lldi %10, r1, r4
sti r1, %100, r1
sti r2, %200, r2
sti r3, %300, r3
sti r4, %400, r4
