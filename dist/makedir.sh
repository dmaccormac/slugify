#!/bin/bash

# Takes text file as argument
# Read and slugify each line of file
# Create numbered directories with results

# Check args 
if [ $# -ne 1 ]; then
    echo "Usage: $0 <filename>"
    exit 1
fi

filename=$1

# Check if file exists
if [ ! -f "$filename" ]; then
    echo "File '$filename' not found."
    exit 1
fi


# Read the file line by line
line_number=1
while IFS= read -r line || [ -n "$line" ]; do
    line=`./slugify "\"$line"\"`
    line=$(printf "%02d-%s\n" "$line_number" "$line")
    mkdir $line
    ((line_number++))
done < "$filename"

