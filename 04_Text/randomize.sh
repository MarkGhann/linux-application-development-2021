#!/bin/bash

if [[ ${#} -gt 1 ]]
then
    echo "Wrong number of arguments: it is to be zero or one."
    echo "Usage:"
    echo " ${0} <emptiness or a real number — delay>"
    exit -1
fi

STUMBLE=0.005

if [[ ${#} -gt 0 ]]
then
    STUMBLE=${1}
fi

readarray carrs

elnum=0
elnums=()
for icarr in ${!carrs[@]}
do
    carr=${carrs[${icarr}]}
    elnum=$(( ${elnum} + ${#carr} ))
    elnums+=(${#carr})
done

randoms=$( shuf -i0-$(( ${elnum} - 1)) )

tput clear

for ind in ${randoms}
do
    bound=0
    r=-1
    for ilen in ${!elnums[@]}
    do
        len=${elnums[${ilen}]}
        r=$(( ${r} + 1 ))
        bound=$(( ${bound} + ${len} ))
        if [[ ${bound} -gt ${ind} ]]
        then
            bound=$(( ${bound} - ${len} ))
            break
        fi
    done
    c=$(( ${ind} - ${bound} ))

    row=${carrs[${r}]}
    tput cup ${r} ${c} && echo -n ${row:${c}:1}
    sleep ${STUMBLE}
done

tput cup ${#carrs[@]} 0
tput sgr0