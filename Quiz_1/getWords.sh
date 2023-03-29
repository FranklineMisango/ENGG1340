#!/bin/bash

if [ $# -lt 1 ]; then
    echo "Usage: $0 <input-file>"
    exit 1
fi

input_file="$1"

if [ ! -f "$input_file" ]; then
    exit 1
fi

words=$(grep -wo '\w*' "$input_file")

unique_words=""
for word in $words; do
    if ! echo "$unique_words" | grep -qw "$word"; then
        unique_words="$unique_words $word"
        echo "$word"
    fi
done

exit 0
