#!/bin/bash

read -p "Enter starting number>>" num1
echo 
read -p "Enter ending number>>" num2

while [ $num1 -lt $num2 ]
	do
		flag=0
		num3=2
		if [ $num1 -gt 1 ]
		then
			while [ $num3 -lt $num1 ]
				do
 					if [ $(($num1%$num3)) -eq 0 ]
					then
						flag=1
						break
					else
						((num3++))
					fi
				done
			if [ $flag -eq 0 ]
			then 
				echo $num1
			fi
		fi
		((num1++))
		
	done
