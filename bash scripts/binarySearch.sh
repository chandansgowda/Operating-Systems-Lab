#!/bin/bash

read -p "Enter length of array>> " n
echo "Enter Array Elements"
for((i=0;i<$n;i++))
do
	read a[$i]
done
read -p "Enter key >> " key

l=0
c=0
u=$(($n-1))
while [ $l -le $u ]
do
	mid=$(((($l+$u))/2))
	if [ $key -eq ${a[$mid]} ]
	then
		c=1
	break
	elif [ $key -lt ${a[$mid]} ]
	then
		u=$(($mid-1))
	else
		l=$(($mid+1))
	fi
done
if [ $c -eq 1 ]
then
	echo "Key Found!"
else
	echo "Key NOT found!"
fi
