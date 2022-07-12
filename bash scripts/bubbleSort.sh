#!/bin/bash

read -p "Enter length of array>> " n
echo "Enter Array Elements"
for((i=0;i<$n;i++))
do
	read a[$i]
done
for ((i=1;i<$n;i++))
do
	for((j=0;j<$(($n-i));j++))
	do
		if [ ${a[$j]} -gt ${a[$(($j+1))]} ]
		then
			t=${a[$j]}
			a[$j]=${a[$(($j+1))]}
			a[$j+1]=$t
		fi
	done
done
echo -ne "Sorted Array is: "
for((i=0;i<$n;i++))
do
	echo -ne "${a[$i]}  "
done
echo


