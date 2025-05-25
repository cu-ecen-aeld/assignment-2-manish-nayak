#!/bin/sh

writefile="$1"
writestr="$2"

if [ $# -lt 2 ]; then
  echo "Error: Two arguments required: <writefile> <writestr>"
  exit 1
fi

# Create the directory path if it doesn't exist
mkdir -p "$(dirname "$writefile")"

# Try to write to the file
if ! echo "$writestr" > "$writefile"; then
  echo "Error: Could not create or write to file '$writefile'"
  exit 1
fi