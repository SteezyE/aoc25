#!/bin/bash

YEAR=$(date '+%Y')
DAY=$(date '+%d')
mkdir -p $DAY && cd $DAY
curl --cookie ../cookies.txt https://adventofcode.com/$YEAR/day/$(date '+%-d')/input -o "in"
