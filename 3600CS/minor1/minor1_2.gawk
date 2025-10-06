#Igor Leeck
#idl0015

BEGIN {
    FS = "\t"
    OFS = "\t"
}

NR > 2 {
    last = $1
    first = $2
    n_scores = NF - 2

    missing = 3 - n_scores
    sum = 0
    average = 0

    for(i=3; i <= NF; i++) {
	sum += $i
    }
    average = sum / n_scores

    if(average < 70)
	grade = "F"
    else if(average < 80)
	grade = "C"
    else if(average < 90)
	grade = "B"
    else
	grade = "A"

    #saw this ternary operator and wanted to use it 
    grade1 = (NF >= 3) ? $3 : "--"
    grade2 = (NF >= 4) ? $4 : "--"
    grade3 = (NF >= 5) ? $5 : "--"

    note = "(missing scores)"
    if(missing == 0)
	printf "%-12s %-10s %-6s %-6s %-4s =>    %-6s\n", last, first, grade1, grade2, grade3, grade
    else
	printf "%-12s %-10s %-6s %-6s %-4s =>    %-6s %-15s\n", last, first, grade1, grade2, grade3, grade, note
}
