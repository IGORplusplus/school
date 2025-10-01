#!/bin/bash
echo "Enter Y to see all the files including hidden files"
echo "Enter N to see all non-hidden files"
echo "Enter q to quit"

read -p "Enter your choice: " reply

case $reply in
    Y) echo "Displaying all files"
	ls -a;;
    N) echo "Displaying non-hidden files"
	ls ;;
    *) echo "Invalid, quitting"; exit 1;;
esac
