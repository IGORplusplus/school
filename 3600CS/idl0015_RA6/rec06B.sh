#!/bin/bash
#idl0015
#Igor Leeck

read -p "Enter in the linux command you want to run  " input_command

echo "Your command: '$input_command'    Executing Now"

eval "$input_command"
