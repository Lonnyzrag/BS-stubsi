#!/bin/sh -

CONFDIR="-q -f /home/ronny/Dokumente/Studi_Unterlagen/git/BS-stubsi/bochs/.bochsrc"
if [ $# -eq 1 ]
then
	IMAGE="floppya:1_44=$1,status=inserted"
fi

bochs $CONFDIR $IMAGE
