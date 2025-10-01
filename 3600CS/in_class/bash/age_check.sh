#!/bin/bash

read -p "Enter your age: " age
ChildRate=3
AdultRate=10
SeniorRate=7

case $age in
    [1-9]|1[0-2])
	echo "Your rate is" '$' "$ChildRate.00" ;;
    [1][3-9]|[2-5][0-9])
	echo "Your rate is" '$' "$AdultRate.00" ;;
    [5][9]|[6-9][0-9]|[1][0-9][0-9])
	echo "Your rate is" '$' "$SeniorRate.00" ;;
esac
