#!/bin/bash

read -p "Enter number>> " num
temp=$num

s=0

rev=""

while [ $num -gt 0 ]
do
	s=$(( $num%10 ))
	num=$(( $num/10 ))
	rev=$rev$s
done

if [ $temp == $rev ]
then
	echo "$temp is a palindrome"
else
	echo "It is not a palindrome"
fi
