#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "Usage: $0 'pattern'"
    exit 1
fi

pattern=$1

find . -type d | while read -r dir; do
    # Get the relative path
    rel_path=${dir#./}
    
    if echo "$rel_path" | grep -w -q "$pattern"; then
        echo "$rel_path"
    fi
done
