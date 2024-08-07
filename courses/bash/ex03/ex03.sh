 #!/bin/bash

if [ "$#" -ne 4 ]; then
    echo "Usage: $0 filename keyword1 keyword2 keyword3" >&2
    exit 1
fi

filename=$1
keyword1=$2
keyword2=$3
keyword3=$4

if [ ! -r "$filename" ]; then
    exit 1
fi

search_keyword() {
    local keyword=$1
    local matches
    matches=$(grep -c "$keyword" "$filename")
    echo "Keyword: $keyword"
    echo "Number of matches: $matches"
    grep "$keyword" "$filename"
    echo ""
}

search_keyword "$keyword1"
search_keyword "$keyword2"
search_keyword "$keyword3"

exit 0
