#!/bin/bash

echo "Prime Numbers"
read -p "From: " n1
read -p "To: " n2

for (( i=$n1; i<=$n2; i++ ))
do
	if [ $i -ge 2 ]
	then
		flag=0
		for (( j=2; j<$i; j++ ))
		do
			if [ $(( $i%$j )) -eq 0 ]
			then
				flag=1
				break
			fi
		done
		if [ $flag -eq 0 ]
		then
			echo -n "$i "
		fi
	fi
done
				
