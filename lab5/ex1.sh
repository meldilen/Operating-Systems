#!/bin/bash

gcc channel.c -o channel
gcc subscriber.c -o subscriber
gcc publisher.c -o publisher

n=$1

if [ "$n" -le 0 -o "$n" -ge 4 ]; then
    echo "Invalid number of subscribers. Please enter a value between 1 and 3."
    exit 1
fi

# Create the directory for named pipes
mkdir -p /tmp/ex1

# Run publisher in a separate shell window
./publisher $n &

# Run subscribers in separate shell windows
for i in $(seq 1 $n); do
    ./subscriber $i &
done