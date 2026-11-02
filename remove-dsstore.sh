#!/bin/bash
# remove-dsstore.sh — delete all .DS_Store files in the current folder and all subfolders

count=$(find . -name ".DS_Store" -type f -print | wc -l | tr -d ' ')

if [ "$count" -eq 0 ]; then
  echo "No .DS_Store files found."
  exit 0
fi

find . -name ".DS_Store" -type f -print -delete
echo "Deleted $count .DS_Store file(s)."