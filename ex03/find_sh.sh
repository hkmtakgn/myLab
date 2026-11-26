#!/bin/sh
find . -name '*.sh' | sed 's/.*\///' | sed 's/\.sh$//' | cat -e