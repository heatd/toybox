#!/bin/sh
instlist=$(./generated/instlist)
for i in $instlist; do echo "\"usr/bin/$i\","; done
