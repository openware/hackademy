#!/bin/bash

usage() {
    echo "Usage: $0 [OPTIONS] FILE"
    echo "Options:"
    echo "  -u, --url      Extract URLs from the file"
    echo "  -e, --email    Extract emails from the file"
    echo "  -h, --help     Display this help and exit"
}

extract_urls() {
    grep -oE 'https?://[^\s/$.?#].[^\s]*' "$1"
}

extract_emails() {
    grep -oE '[\w._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}' "$1"
}

options=$(getopt -o ueh --long url,email,help -- "$@")
if [ $? -ne 0 ]; then
    usage
    exit 1
fi

eval set -- "$options"

url_flag=false
email_flag=false

while true; do
    case "$1" in
        -u | --url)
            url_flag=true
            shift
            ;;
        -e | --email)
            email_flag=true
            shift
            ;;
        -h | --help)
            usage
            exit 0
            ;;
        --)
            shift
            break
            ;;
        *)
            usage
            exit 1
            ;;
    esac
done

 is provided
if ! $url_flag && ! $email_flag; then
    echo "Error: You must specify at least one option (--url or --email)."
    usage
    exit 1
fi


if [ $# -ne 1 ]; then
    echo "Error: You must specify a file."
    usage
    exit 1
fi

 file
file="$1"
if $url_flag; then
    echo "Extracting URLs from $file:"
    extract_urls "$file"
fi

if $email_flag; then
    echo "Extracting emails from $file:"
    extract_emails "$file"
fi
