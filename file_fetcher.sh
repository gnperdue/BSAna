#!/bin/sh

filelist='coh_carbon_splines_RS280.xml coh_carbon_splines_RSDEV4141.xml coh_carbon_splines_BSDEV4141.xml'

for filenam in $filelist
do
  scp perdue@minervagpvm02.fnal.gov:/minerva/app/users/perdue/GENIE/runs/${filenam} ./splines
done

scp perdue@minervagpvm02.fnal.gov:/minerva/app/users/perdue/GENIE/runs/gntp.berger_sehgal_4141.gst.root ./data
