#!/bin/bash
# 1. Create ProgressBar function
# 1.1 Input is currentState($1) and totalState($2)
function ProgressBar {
# Process data
    let _progress=(${1}*100/${2}*100)/100
    let _done=(${_progress}*4)/10
    let _left=40-$_done
# Build progressbar string lengths
    _fill=$(printf "%${_done}s")
    _empty=$(printf "%${_left}s")
    _name=$(printf "%-${5}s" "${3}")

# 1.2 Build progressbar strings and print the ProgressBar line
# 1.2.1 Output example:
# 1.2.1.1 Progress : [########################################] 100%
printf "\r\e[36m${4} ${_name}\e[0m \e[93m[${_fill// /#}${_empty// /-}] \e[1m${_progress}%%\e[0m"
}


ProgressBar $1 $2 "$3" "$4" $5
