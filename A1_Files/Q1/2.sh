#!/bin/bash

# Read the timestamp prefix from the first command line argument
timestamp_prefix=$1

# Extract the log entries matching the timestamp prefix, and extract the GatewayName and SmartcardID fields from each entry
# We use awk to extract the GatewayName and SmartcardID fields from each log entry, and sort and count them using sort and uniq
# The resulting output has one line per GatewayName, with the count of distinct SmartcardIDs that entered via that gateway
gateway_counts=$(grep "${timestamp_prefix}" Log_* | awk -F',' '{ if ($4 == "Enter") print $3 "," $2 }' | sort -u | awk -F',' '{seen[$1]++} END {for (i in seen) {print seen[i], i}}')

# If there were no matching records, print a message and exit
if [ -z "${gateway_counts}" ]; then
  echo "No records found"
  exit 0
fi

# Extract the maximum count from the gateway_counts output, and extract the lines that have that count
max_count=$(echo "${gateway_counts}" | awk '{ print $1 }' | sort -n | tail -n1)
max_gateway_lines=$(echo "${gateway_counts}" | awk -v max_count="${max_count}" '{ if ($1 == max_count) print }')

# Sort the max_gateway_lines output in descending lexicographical order of gateway names
sorted_max_gateway_lines=$(echo "${max_gateway_lines}" | sort -r -k2)

# Output the gateway counts and names, with the count first
echo "${sorted_max_gateway_lines}" | awk '{ print $1 " " $2 " "$3 }'

exit 0
