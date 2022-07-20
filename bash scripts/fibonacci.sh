#!/bin/bash

read -p "Enter n>> " n
a=0
b=1

for (( i=0; i<n; i++ ))
do
	echo -n "$a "
	fn=$(( $a + $b ))
	a=$b
	b=$fn
done
