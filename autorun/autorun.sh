#!/bin/bash
csvPath="/home/kurt/桌面/BSO-swarm-robot/simulation/csv"
mainPath="/home/kurt/PlayerStage/stage/Stage-4.1.1/swan/"
echo "Autorun Starts!"
cd ${mainPath}
make getpose
make main42a
./main42a
echo "Getting position"
cd ${mainPath}
./getpose 10 








