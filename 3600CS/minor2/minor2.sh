#!/bin/bash

if [[ "$1" == "--debug" ]]; then
    set -x
fi

LOG="script.log"

function logAction() {
    local message="$1"
    echo "$(date) - $message" >> "$LOG"
}


function printOptions() {
    echo "Choose an option: "
    echo "1) Organize files"
    echo "2) Add Reminder"
    echo "3) View Reminders"
    echo "4) Delete Reminder"
    echo "5) Health Check"
    echo "6) Exit"
}

function greeting() {
    echo "Good morning, $USER"

    echo -n "Date and Time: "
    date

    #I know this isn't on the cell machine but it is supposed to be
    if command -v cal &>/dev/null; then
        cal
    else
        echo "(cal not available)"
    fi
    #this shows all of the processes and counts the lines without the heading
    echo -n "Running Processes: "
    ps aux --no-heading | wc -l

    logAction "$USER was greeted"
}

function organizeFiles() {
    read -p "Enter directory to organize: " directory

    if [[ ! -d "$directory" ]]; then
	echo "Directory does not exist."
	return 1
    fi

    echo -n "Files in $directory:  "
    ls "$directory"

    logAction "$directory was 'organized'"
}

function addReminder() {
    echo ""
    read -p "Enter reminder: " reminder
    reminders+=("$reminder")

    logAction "$reminder was added"
}

function viewReminders() {
    echo ""

    if [ ${#reminders[@]} -eq 0 ]; then
	echo "No reminders available."
    else
	echo "Your reminders:"
	for i in "${!reminders[@]}"; do
	    echo "$((i + 1)). ${reminders[$i]}"
	done
    fi

    logAction "viewed reminders"
}

function removeReminder() {
    echo ""
    if [ ${#reminders[@]} -eq 0 ]; then
	echo "No reminders available to remove"
	return
    fi
    viewReminders
    read -p "Enter reminder number to delete  " number

    if [[ $number -ge 1 && $number -le ${#reminders[@]} ]]; then
        unset 'reminders[$((num - 1))]'
        reminders=("${reminders[@]}")
        echo "Reminder deleted."
    else
	echo "Invalid Number"
    fi

    logAction "$number reminder was removed"
}

function healthCheck() {
    read -p "Enter heart rate:  " heartRate

    if [ "$heartRate" -lt 60 ]; then
	echo "Heart rate is low"
    elif [ "$heartRate" -le 100 ]; then
	echo "Heart rate is normal"
    else
	echo "Heart rate is high"
    fi

    echo ""
    logAction "health was checked"
}

function catch() {
    echo ""
    echo "Use menu to exit safely"
    logAction "script interrupted by a trap (SIGINT/SIGTERM)"
    return
}

#functions are over


#variables declared
reminders=()
option=0

trap catch SIGINT SIGTERM


#where meat of bash script happens
greeting
echo ""
while [ "$option" -ne 6 ]; do
    printOptions

    read -p "Enter choice: " option

    case "$option" in
	1)
	    organizeFiles
	    ;;
	2)
	    addReminder
	    ;;
        3)
	    viewReminders
            ;;
        4)
	    removeReminder
            ;;
        5)
	    healthCheck
            ;;
        6)
            echo "Exiting..."
	    logAction "Exiting ..."
            ;;
        *)
            echo "Invalid option. Please try again."
            ;;
    esac
done
