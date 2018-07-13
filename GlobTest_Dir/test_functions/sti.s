.name "sti"
.comment "REG, REG | DIR | IND, DIR | REG"

##ld %190054658, r5
ld %190054722, r5
sti r5, %-7, r1
sti r1, r1, r4
and r2, %1, r3
zjmp %-27
