awk '
{
    for (i = 1; i <= NF; i++) {
        a[i, NR] = $i
        if (max < NF) max = NF
    }
}
END {
    for (i = 1; i <= max; i++) {
        line = ""
        for (j = 1; j <= NR; j++) {
            line = line a[i, j] (j == NR ? "" : " ")
        }
        print line
    }
}
' file.txt