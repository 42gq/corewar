.name"Assassin_Zork"
.comment "One_hit_One_Death"

ld %655359, r10
st r10, -50
ld %1, r5
ld %1, r3
st r1, 11
alive:
and r5, r3, r4
alive2: live %0
zjmp %:alive2
ld %191365691, r2
st r8, r5
st r8, r3
fork %:alive
fork %5
st r1, 3
live %0
st r2, 458
