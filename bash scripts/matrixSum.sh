#!/bin/bash
declare -a mat1
declare -a mat2

read -p "Enter n>> " n

echo "Enter Matrix 1"
for (( i=1; i<=n; i++ ))
do
	for (( j=1; j<=n; j++ ))
	do
		read -p "" num
		mat1[$i,$j]=$num
	done
done

echo "Enter Matrix 2"
for (( i=1; i<=n; i++ ))
do
	for (( j=1; j<=n; j++ ))
	do
		read -p "" num
		mat2[$i,$j]=$num
	done
done

echo "Sum of Matrix 1 and Matrix 2 is"
for (( i=1; i<=n; i++ ))
do
	for (( j=1; j<=n; j++ ))
	do
		echo -n "$(( mat1[$i,$j]+mat2[$i,$j] ))  "
	done
	echo ""
done
