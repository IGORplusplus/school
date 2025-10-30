#!/bin/bash
#idl0015
#Igor Leeck

random=$(((RANDOM % 10 + 1)))
read -p "Enter a number between 1 and 10: " guess

while [ "$guess" -ne "$random" ]; do
    echo "Sorry, you are not correct. Try again!"
    echo ""
    read -p "Enter a number between 1 and 10: " guess
done

echo "Congratulations the number is $guess"
