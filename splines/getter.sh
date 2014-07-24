#!/bin/sh

filelist='coh_carbon_splines_RS280.xml coh_carbon_splines_RSDEV4141.xml coh_carbon_splines_BSDEV4141.xml'


for filenam in $filelist
do
  scp perdue@minervagpvm02.fnal.gov:/minerva/app/users/perdue/GENIE/runs/${filenam} .
done

scp perdue@minervagpvm02.fnal.gov:/minerva/app/users/perdue/GENIE/runs/gntp.berger_sehgal.gst.root ./ana/data
