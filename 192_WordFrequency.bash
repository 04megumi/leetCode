# Read from the file words.txt and output the word frequency list to stdout.
cat 192.bash | tr -s ' ' '\n' | sort | uniq -c | sort -r | awk '{ print $2, $1}'