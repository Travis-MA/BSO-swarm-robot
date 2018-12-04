#!/bin/bash
csvPath="/home/kurt/桌面/天鹅集群算法/Simulation/"
mainPath="/home/kurt/PlayerStage/stage/Stage-4.1.1/swan/"
echo "Autorun Starts!"
echo "[10%]start"
cd ${mainPath}
./main42a
echo "[10%]completed"
cd ${mainPath}
./getpose 1 ${csvPath}

echo "[20%]start"
cd ${mainPath}
./main42a
echo "[20%]completed"
cd ${mainPath}
./getpose 2 ${csvPath}

echo "[30%]start"
cd ${mainPath}
./main42a
echo "[30%]completed"
cd ${mainPath}
./getpose 3 ${csvPath}

echo "[40%]start"
cd ${mainPath}
./main42a
echo "[40%]completed"
cd ${mainPath}
./getpose 4 ${csvPath}

echo "[50%]start"
cd ${mainPath}
./main42a
echo "[50%]completed"
cd ${mainPath}
./getpose 5 ${csvPath}

echo "[60%]start"
cd ${mainPath}
./main42a
echo "[60%]completed"
cd ${mainPath}
./getpose 6 ${csvPath}

echo "[70%]start"
cd ${mainPath}
./main42a
echo "[70%]completed"
cd ${mainPath}
./getpose 7 ${csvPath}

echo "[80%]start"
cd ${mainPath}
./main42a
echo "[80%]completed"
cd ${mainPath}
./getpose 8 ${csvPath}

echo "[90%]start"
cd ${mainPath}
./main42a
echo "[90%]completed"
cd ${mainPath}
./getpose 9 ${csvPath}

echo "[100%]start"
cd ${mainPath}
./main42a
echo "[100%]completed"
cd ${mainPath}
./getpose 10 ${csvPath}







