#!/bin/sh
TOYFILES="$(sed -n 's/^CONFIG_\([^=]*\)=.*/\1/p' .config | xargs | tr ' [A-Z]' '|[a-z]')"
TOYFILES="$(grep -E -l "TOY[(]($TOYFILES)[ ,]" toys/*/*.c)"
for i in $TOYFILES; do echo "\"$i\","; done
