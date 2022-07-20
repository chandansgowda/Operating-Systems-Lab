#!/bin/bash
read -p "a>> " a
read -p "b>> " b

echo "1.Add 2.Subtract 3.Multiply 4.Divide"
read -p "Enter Choice>> " c

case $c in
1)
 echo $(( $a + $b ))
 ;;
2)
 echo $(( $a - $b ))
 ;;
3)
 echo $(( $a * $b ))
 ;;
4)
 echo $(( $a / $b ))
 ;;
esac
