#!/bin/sh

bername=berger_sehgal_4141_list.txt

rm -f $bername

ls -1 *ber*4141*gst* > $bername

cp $bername ../list
