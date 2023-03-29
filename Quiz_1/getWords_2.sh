#!/bin/bash

if [ $# -eq 0 ]; then
  exit 1
fi

# check if input file exists
if [ ! -f "$1" ]; then
  echo "File $1 not found."
  exit 1
fi

# read the file contents and convert to lowercase
content=$(tr '[:upper:]' '[:lower:]' < "$1")

# split the content into words and count their occurrences
word_counts=$(echo "$content" | tr -s '[:space:]' '\n' | sort | uniq -c | sort -rn)

# get the highest frequency
highest_freq=$(echo "$word_counts" | head -n1 | awk '{print $1}')

# filter out the most frequent words
most_frequent=$(echo "$word_counts" | awk -v max=$highest_freq '{if ($1 == max) print $2}' | sort)

# print out the most frequent words and their frequency
while read -r word; do
  echo "$word $highest_freq"
done <<< "$most_frequent"
