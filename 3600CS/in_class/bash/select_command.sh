#!/bin/bash

PS3="Select entry or ^D"
select var in alpha beta gamma sigma
do
    echo $var
done
