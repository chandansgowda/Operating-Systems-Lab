#!/bin/bash

read -p "Enter length of array>> " n
echo "Enter Array Elements"
for((i=0;i<$n;i++))
do
	read a[$i]
done
read -p "Enter key >> " key

j=0
while [[ $j -lt $n && $key -ne ${a[$j]} ]]
do	
	j=$($j+1)
done
if [ $key -eq ${a[$j]} ]
	then 
		echo "$key is present at location $j"
	else
		echo "$key not found"
fi
