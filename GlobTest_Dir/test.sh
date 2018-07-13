#!/bin/sh
S_FILES=$(ls -1 ./s_files/*.s)

rm ./cor_zaz_files/*.cor
rm ./cor_files/*.cor
i=1
current_file=$(echo $S_FILES | cut -d ' ' -f 1)
echo $current_file
while [ $current_file ]
do
		./asm_zaz $current_file
		let i++
		echo $current_file
		current_file=$(echo $S_FILES | cut -d ' ' -f $i)
done
mv ./s_files/*.cor ./cor_zaz_files/

i=1
sec_file=$(echo $S_FILES | cut -d ' ' -f 1)
while [ $sec_file ]
do
		../asm_dir/asm $sec_file
		let i++
		echo $sec_file
		sec_file=$(echo $S_FILES | cut -d ' ' -f $i)
done
mv ./*.cor ./cor_files/
