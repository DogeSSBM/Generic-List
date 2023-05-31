#!/bin/sh
git add .
if [ "$#" -eq 1 ]; then
    git commit -m "$1"
else
    git commit -m "Automatic commit."
fi
git push
