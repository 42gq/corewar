#!/bin/sh

COR_FILES=$(ls -1 ./cor_files/*cor)
COR_ZAZ_FILES=$(ls -1 ./cor_zaz_files/*cor)
i=1
current_cor=$(echo $COR_FILES | cut -d ' ' | -f 1)
corrent_zaz_cor=$(echo $COR_ZAZ_FILES | cut -d ' '-f 1)
echo $current_file
