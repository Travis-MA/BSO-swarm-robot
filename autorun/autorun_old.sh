#!/bin/bash
csvPath="/home/kurt/桌面/BSO-swarm-robot/simulation/csv"
mainPath="/home/kurt/桌面/BSO-swarm-robot/src"
echo "Autorun Starts!"
cd ${mainPath}
make getpose
make main_old
./main_old









