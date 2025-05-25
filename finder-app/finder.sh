#!/bin/sh
# Finder script for assignment 1 and assignment 2

if [ $# -lt 2 ]; then
  echo "Error: Two arguments required: <filesdir> <searchstr>"
  exit 1
fi

filesdir=$1
matchstr=$2

# Check if the first argument is a valid directory
if [ ! -d "$filesdir" ]; then
  echo "Error: The path '$filesdir' is not a valid directory."
  exit 1
fi

# Search for the string in the directory and count matches
files_count=$(find "$filesdir" -type f | wc -l)
match_count=$(grep -r "$matchstr" "$filesdir" 2>/dev/null | wc -l)

echo "The number of files are $files_count and the number of matching lines are $match_count"
