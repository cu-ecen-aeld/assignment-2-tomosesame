#!/bin/sh

if [ $# -ne 2 ]; then
    echo "Usage: $0 <file_path> <string_to_write>"
    exit 1
fi

writefile=$1
writestr=$2

mkdir -p "$(dirname "$writefile")"
echo "$writestr" > "$writefile"

if [ $? -ne 0 ]; then
    echo "Error: Could not write to file $writefile"
    exit 1
fi
