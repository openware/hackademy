#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "Usage: $0 pattern" >&2
    exit 1
fi

pattern=$1

find . -type f | while read -r file; do
    
    grep -Hn "$pattern" "$file"
done

exit 0
