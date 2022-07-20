#!/bin/bash
declare -a arr

read -p "Enter n>> " n

for (( i=0; i<n; i++ ))
do
	read -p "" num
	arr[$i]=$num
done

big=${arr[0]}

for (( i=1; i<n; i++ ))
do
	if [ ${arr[$i]} -gt $big ]
	then
		big=${arr[$i]}
	fi
done

echo "Largest number is : $big"
