 #!/bin/bash

map() {
    if [ "$#" -lt 2 ]; then
        echo "Usage: map command arg1 arg2 ..."
        return 1
    fi

    command=$1
    shift

    for arg in "$@"; do
        $command "$arg"
    done
}


