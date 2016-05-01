#!/bin/bash


echo "PRIMER TEST!"
../sources/3D_Dock_2/progs/ftdock -static ../inputs/2pka.parsed -mobile ../inputs/5pti.parsed > output.test1

echo "SEGON TEST!"
../sources/3D_Dock/progs/ftdock -static ../inputs/1hba.parsed -mobile ../inputs/5pti.parsed > output.test2

echo "TERCER TEST!"
../sources/3D_Dock/progs/ftdock -static ../inputs/4hhb.parsed -mobile ../inputs/5pti.parsed > output.test3

echo "ULTIM TEST!"
../sources/3D_Dock/progs/ftdock -static ../inputs/1ACB_rec.parsed -mobile ../inputs/1ACB_lig.parsed > output.test4
