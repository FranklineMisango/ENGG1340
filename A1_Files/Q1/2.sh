#!/bin/bash

# check if timestamp argument is provided
if [ -z "$1" ]; then
  echo "Please provide a timestamp argument"
  exit 1
fi

# initialize associative arrays
declare -A enter_counts
declare -A exit_counts
declare -A name_counts

# loop through all log files and count occurrences of gateway names
for logfile in Log_*.log; do
  while read line; do
    timestamp=$(echo "$line" | cut -d, -f1)
    name=$(echo "$line" | cut -d, -f3)
    event=$(echo "$line" | cut -d, -f4)

    # check if the timestamp matches the prefix
    if [[ $timestamp == $1* && $event == "Enter" ]]; then
      # increment the count for the gateway name
      ((enter_counts["$name"]++))
    elif [[ $timestamp == $1* && $event == "Exit" ]]; then
      ((exit_counts["$name"]++))
    fi

  done < <(grep -E "^$1.*,(Enter|Exit)" "$logfile" | grep "$1")
done

# check if any gateway names were found
if [ ${#enter_counts[@]} -eq 0 ]; then
  echo "No records found"
  exit 0
fi

# compute the net counts for each gateway name
for name in "${!enter_counts[@]}"; do
  enter_count=${enter_counts["$name"]}
  exit_count=${exit_counts["$name"]:="0"} # set default value to 0 if no exit count
  net_count=$((enter_count - exit_count))
  name_counts["$name"]=$net_count
done

# find the maximum count
max_count=$(printf '%s\n' "${name_counts[@]}" | sort -rn | head -n1)

# loop through all gateway names and select the ones with the maximum count
while IFS= read -r line; do
  if [[ $(echo "$line" | awk '{print $1}') -eq $max_count ]]; then
    echo "$line"
  fi
done < <(for name in "${!name_counts[@]}"; do echo "${name_counts["$name"]} $name"; done | sort -rn -k1,1 -k2,2)
