#!/bin/bash

# Read the file
DATA=`cat ./june-311-sf.tsv`
# Chop off the first line of just column names
DATA=`echo "$DATA" | tail -n +2`

# Count lines in the data
echo "`echo "$DATA" | wc -l` cases were opened in June of 2020."
echo

# Extract case type
TYPES=`echo "$DATA" | cut -d "	" -f 8 | grep "..*"`
# Sort and count types
TYPES=`echo "$TYPES" | sort | uniq -c | sort -rn | head -n 3`

echo "The most common case types are as follows:"
echo "$TYPES"
echo

# Extract cases in the Mission neighborhood
MISSION=`echo "$DATA" | cut -d "	" -f 14 | grep "^Mission$" | wc -l`

echo "$MISSION cases were reported in the Mission neighborhood."
echo

# Pull report time out of each case
AMPM=`echo "$DATA" | cut -d "	" -f 2 | grep "..*" | cut -d " " -f 3`
# Sort and count each time
AMPM=`echo "$AMPM" | sort | uniq -c | sort -rn`

echo "The most common times of case reports are as follows:"
echo "$AMPM"