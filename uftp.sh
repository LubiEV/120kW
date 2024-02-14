#!/bin/bash
HOST=${1}
USER=${2}
PASSWORD=${3}
PATH1=${4}
FNAME=${5}
#FNAME="ARAIV"

ftp -inv $HOST <<EOF
user $USER $PASSWORD
binary
cd $PATH1
get $FNAME
bye
EOF
exit 0;
#echo $?
#full_string=$(readelf -d $FNAME)

#substring="There is no dynamic"

#if [ -z "${full_string##*$substring*}" ]; then
#        echo "Found substring!"
#	exit 1;
#else
#        echo "Substring is MIA!"
#	exit 0;
#fi
