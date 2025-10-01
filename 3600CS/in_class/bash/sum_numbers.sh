#!/bin/bash

read -p "Enter a number n: " input

sum=0

#this is messed up
for n in $input 
do
    sum=$((sum + n))
done
echo "the sum is $sum"
