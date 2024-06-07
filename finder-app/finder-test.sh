#!/bin/sh
# Tester script for assignment 1 and assignment 2
# Author: Siddhant Jajoo

set -e
set -u

NUMFILES=10
WRITESTR=AELD_IS_FUN
WRITEDIR=/tmp/aeld-data
script_dir=$(dirname "$0")
username=$(cat "$script_dir/../conf/username.txt")

if [ $# -lt 3 ]
then
    echo "Using default value ${WRITESTR} for string to write"
    if [ $# -lt 1 ]
    then
        echo "Using default value ${NUMFILES} for number of files to write"
    else
        NUMFILES=$1
    fi    
else
    NUMFILES=$1
    WRITESTR=$2
    WRITEDIR=/tmp/aeld-data/$3
fi

MATCHSTR="The number of files are ${NUMFILES} and the number of matching lines are ${NUMFILES}"

echo "Writing ${NUMFILES} files containing string ${WRITESTR} to ${WRITEDIR}"

rm -rf "${WRITEDIR}"

# create $WRITEDIR if not assignment1
assignment=$(cat "$script_dir/../conf/assignment.txt")

if [ $assignment != 'assignment1' ]
then
    mkdir -p "$WRITEDIR"

    # The WRITEDIR is in quotes because if the directory path consists of spaces, then variable substitution will fail.
    # The quotes signify that the entire string in WRITEDIR is a single string.
    # This issue can also be resolved by using double square brackets i.e [[ ]] instead of using single square bracket in if condition.
    if [ -d "$WRITEDIR" ]
    then
        echo "$WRITEDI
