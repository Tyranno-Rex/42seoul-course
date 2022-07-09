#!/bin/sh

find . -type f -o -type d | awk  'END{print NR}'
