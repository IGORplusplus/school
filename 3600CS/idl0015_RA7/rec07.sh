#!/bin/bash

#idl0015
#Igor Leeck
if [ "$#" -ne 1 ]; then
    echo "Need one argument for this to work"
    exit 1
fi

curve_amount="$1"

function curve() {
    incr="$1"
    shift
    arr=("$@")

    sum=0
    index=0
    for x in "${arr[@]}"; do
	let grades[index]=x+incr
	((index++))
    done

}

grades=()

for (( i=1 ; i<=5; i=i+1 )) do
    read -p "Enter your grades for quiz #$i  " grade
    grades[$((i-1))]="$grade"
done

curve "$curve_amount" "${grades[@]}"

echo ""
echo "Curved Grades: "
for (( i=0 ; $i<${#grades[*]}; i=$i+1 )) do
    echo "Curved grade for quiz #$((i+1)): ${grades[i]}"
done
