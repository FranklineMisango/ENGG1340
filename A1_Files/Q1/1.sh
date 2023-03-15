#!/bin/bash

# check if timestamp argument is provided
if [ -z "$1" ]; then
  echo "Please provide a timestamp argument"
  exit 1
fi

# initialize associative array
declare -A name_counts
declare -A exit

# loop through all log files and count occurrences of gateway names
for logfile in Log_*.log; do
  while read line; do
    timestamp=$(echo "$line" | cut -d, -f1)
    name=$(echo "$line" | cut -d, -f3)
    event=$(echo "$line" | cut -d, -f4)
    
    # check if the timestamp matches the prefix
    if [[ $timestamp == $1* ]]; then
      # increment the count for the gateway name
      ((name_counts["$name"]++))
    fi
  done < <(grep -E "^$1.*,(Enter|Exit)" "$logfile")
done

# check if any gateway names were found
if [ ${#name_counts[@]} -eq 0 ]; then
  echo "No records found"
  exit 0
fi

# find the maximum count
max_count=$(printf '%s\n' "${name_counts[@]}" | sort -rn | head -n1)

# loop through the gateway names with the maximum count and sort them lexicographically
while IFS= read -r line; do
  if [[ $(echo "$line" | awk '{print $1}') -eq $max_count ]]; then
    echo "$line"
    exit 0
  fi
done < <(for name in "${!name_counts[@]}"; do echo "${name_counts["$name"]} $name"; done | sort -rn -k1,1 -k2,2)

# if no gateway names have maximum count, then print the first entry
echo "${name_counts[$(echo "${!name_counts[@]}" | head -n1)]} $(echo "${!name_counts[@]}" | head -n1)"
