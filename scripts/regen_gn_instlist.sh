#!/bin/sh
instlist=$(./generated/unstripped/instlist)
for i in $instlist; do echo "\"usr/bin/$i\","; done
