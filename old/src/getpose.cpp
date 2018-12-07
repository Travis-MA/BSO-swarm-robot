
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <libplayerc++/playerc++.h>
#include <vector>
#include <chrono>
#include <ctime>
#include <math.h>
#include <float.h>
#include <fstream>
#include "stdlib.h"
#include <algorithm>


#define SWARM_SIZE 42 // number of robots

struct location
{
     double X;
     double Y;
     double YAW;
}
typedef robot_loc_t;
using namespace PlayerCc;
using namespace std;

double originPos[SWARM_SIZE][2] = {0};

int main(int argc, char *argv[])
{	
      
      //argv[0] = loopnum
      /*need to do this line in c++ only*/
      using namespace PlayerCc;
//===================================INITIALIZATION==================================================//
      PlayerClient    robot0("localhost", 7000);
      Position2dProxy p2dProxy_robot0(&robot0,0);
      originPos[0][0] = 3.000;
      originPos[0][1] = -1.843;
      
      PlayerClient    robot1("localhost", 7001);
      Position2dProxy p2dProxy_robot1(&robot1,0);
      originPos[1][0] = 3.000;
      originPos[1][1] = -1.129;

      PlayerClient    robot2("localhost", 7002);
      Position2dProxy p2dProxy_robot2(&robot2,0);
      originPos[2][0] = 3.000;
      originPos[2][1] = -0.414;
      
      PlayerClient    robot3("localhost", 7003);
      Position2dProxy p2dProxy_robot3(&robot3,0);
      originPos[3][0] = 3.000;
      originPos[3][1] = 0.300;
      
      PlayerClient    robot4("localhost", 7004);
      Position2dProxy p2dProxy_robot4(&robot4,0);
      originPos[4][0] = 3.000;
      originPos[4][1] = 1.014;
      
      PlayerClient    robot5("localhost", 7005);
      Position2dProxy p2dProxy_robot5(&robot5,0);
      originPos[5][0] = 3.000;
      originPos[5][1] = 1.729;
      
      PlayerClient    robot6("localhost", 7006);
      Position2dProxy p2dProxy_robot6(&robot6,0);
      originPos[6][0] = 2.286;
      originPos[6][1] = -1.843;
      
      PlayerClient    robot7("localhost", 7007);
      Position2dProxy p2dProxy_robot7(&robot7,0);
      originPos[7][0] = 2.286;
      originPos[7][1] = -1.129;
      
      PlayerClient    robot8("localhost", 7008);
      Position2dProxy p2dProxy_robot8(&robot8,0);
      originPos[8][0] = 2.286;
      originPos[8][1] = -0.414;
      
      PlayerClient    robot9("localhost", 7009);
      Position2dProxy p2dProxy_robot9(&robot9,0);
      originPos[9][0] = 2.286;
      originPos[9][1] = 0.300;
      
      PlayerClient    robot10("localhost", 7010);
      Position2dProxy p2dProxy_robot10(&robot10,0);
      originPos[10][0] = 2.286;
      originPos[10][1] = 1.014;
      
      PlayerClient    robot11("localhost", 7011);
      Position2dProxy p2dProxy_robot11(&robot11,0);
      originPos[11][0] = 2.286;
      originPos[11][1] = 1.729;
      
      PlayerClient    robot12("localhost", 7012);
      Position2dProxy p2dProxy_robot12(&robot12,0);
      originPos[12][0] = 1.572;
      originPos[12][1] = -1.843;
      
      PlayerClient    robot13("localhost", 7013);
      Position2dProxy p2dProxy_robot13(&robot13,0);
      originPos[13][0] = 1.572;
      originPos[13][1] = -1.129;
      
      PlayerClient    robot14("localhost", 7014);
      Position2dProxy p2dProxy_robot14(&robot14,0);
      originPos[14][0] = 1.572;
      originPos[14][1] = -0.414;

      PlayerClient    robot15("localhost", 7015);
      Position2dProxy p2dProxy_robot15(&robot15,0);
      originPos[15][0] = 1.572;
      originPos[15][1] = 0.300;
      
      PlayerClient    robot16("localhost", 7016);
      Position2dProxy p2dProxy_robot16(&robot16,0);
      originPos[16][0] = 1.572;
      originPos[16][1] = 1.014;
      
      PlayerClient    robot17("localhost", 7017);
      Position2dProxy p2dProxy_robot17(&robot17,0);
      originPos[17][0] = 1.572;
      originPos[17][1] = 1.729;
      
      PlayerClient    robot18("localhost", 7018);
      Position2dProxy p2dProxy_robot18(&robot18,0);
      originPos[18][0] = 0.858;
      originPos[18][1] = -1.843;

      PlayerClient    robot19("localhost", 7019);
      Position2dProxy p2dProxy_robot19(&robot19,0);
      originPos[19][0] = 0.858;
      originPos[19][1] = -1.129;
      
      PlayerClient    robot20("localhost", 7020);
      Position2dProxy p2dProxy_robot20(&robot20,0);
      originPos[20][0] = 0.858;
      originPos[20][1] = -0.414;
      
      PlayerClient    robot21("localhost", 7021);
      Position2dProxy p2dProxy_robot21(&robot21,0);
      originPos[21][0] = 0.858;
      originPos[21][1] = 0.300;

      PlayerClient    robot22("localhost", 7022);
      Position2dProxy p2dProxy_robot22(&robot22,0);
      originPos[22][0] = 0.858;
      originPos[22][1] = 1.014;

      PlayerClient    robot23("localhost", 7023);
      Position2dProxy p2dProxy_robot23(&robot23,0);
      originPos[23][0] = 0.858;
      originPos[23][1] = 1.729;

      PlayerClient    robot24("localhost", 7024);
      Position2dProxy p2dProxy_robot24(&robot24,0);
      originPos[24][0] = 0.143;
      originPos[24][1] = -1.843;
      
      PlayerClient    robot25("localhost", 7025);
      Position2dProxy p2dProxy_robot25(&robot25,0);
      originPos[25][0] = 0.143;
      originPos[25][1] = -1.129;
      
      PlayerClient    robot26("localhost", 7026);
      Position2dProxy p2dProxy_robot26(&robot26,0);
      originPos[26][0] = 0.143;
      originPos[26][1] = -0.414;
      
      PlayerClient    robot27("localhost", 7027);
      Position2dProxy p2dProxy_robot27(&robot27,0);
      originPos[27][0] = 0.143;
      originPos[27][1] = 0.300;
      
      PlayerClient    robot28("localhost", 7028);
      Position2dProxy p2dProxy_robot28(&robot28,0);
      originPos[28][0] = 0.143;
      originPos[28][1] = 1.014;
      
      PlayerClient    robot29("localhost", 7029);
      Position2dProxy p2dProxy_robot29(&robot29,0);
      originPos[29][0] = 0.143;
      originPos[29][1] = 1.729;

      PlayerClient    robot30("localhost", 7030);
      Position2dProxy p2dProxy_robot30(&robot30,0);
      originPos[30][0] = -0.571;
      originPos[30][1] = -1.843;
      
      PlayerClient    robot31("localhost", 7031);
      Position2dProxy p2dProxy_robot31(&robot31,0);
      originPos[31][0] = -0.571;
      originPos[31][1] = -1.129;
      
      PlayerClient    robot32("localhost", 7032);
      Position2dProxy p2dProxy_robot32(&robot32,0);
      originPos[32][0] = -0.571;
      originPos[32][1] = -0.414;
      
      PlayerClient    robot33("localhost", 7033);
      Position2dProxy p2dProxy_robot33(&robot33,0);
      originPos[33][0] = -0.571;
      originPos[33][1] = 0.300;
      
      PlayerClient    robot34("localhost", 7034);
      Position2dProxy p2dProxy_robot34(&robot34,0);
      originPos[34][0] = -0.571;
      originPos[34][1] = 1.014;
      
      PlayerClient    robot35("localhost", 7035);
      Position2dProxy p2dProxy_robot35(&robot35,0);
      originPos[35][0] = -0.571;
      originPos[35][1] = 1.729;
      
      PlayerClient    robot36("localhost", 7036);
      Position2dProxy p2dProxy_robot36(&robot36,0);
      originPos[36][0] = -1.286;
      originPos[36][1] = -1.843;
       
      PlayerClient    robot37("localhost", 7037);
      Position2dProxy p2dProxy_robot37(&robot37,0);
      originPos[37][0] = -1.286;
      originPos[37][1] = -1.129;
      
      PlayerClient    robot38("localhost", 7038);
      Position2dProxy p2dProxy_robot38(&robot38,0);
      originPos[38][0] = -1.286;
      originPos[38][1] = -0.414;
      
      PlayerClient    robot39("localhost", 7039);
      Position2dProxy p2dProxy_robot39(&robot39,0);
      originPos[39][0] = -1.286;
      originPos[39][1] = 0.300;
      
      PlayerClient    robot40("localhost", 7040);
      Position2dProxy p2dProxy_robot40(&robot40,0);
      originPos[40][0] = -1.286;
      originPos[40][1] = 1.014;
      
      PlayerClient    robot41("localhost", 7041);
      Position2dProxy p2dProxy_robot41(&robot41,0);
      originPos[41][0] = -1.286;
      originPos[41][1] = 1.729;
      
      double originPos_copy[SWARM_SIZE][2] = {0};
      for(int i = 0;i<SWARM_SIZE;i++){
            originPos_copy[i][0] = originPos[i][0];
            originPos_copy[i][1] = originPos[i][1];
            
      }

      PlayerClient plyclnts[SWARM_SIZE] ={robot0, robot1, robot2, robot3, robot4, robot5, robot6, robot7, robot8, robot9, robot10, robot11, robot12, robot13, robot14, robot15, robot16, robot17, robot18, robot19, robot20, robot21, robot22, robot23, robot24, robot25, robot26, robot27, robot28, robot29, robot30, robot31, robot32, robot33, robot34, robot35, robot36, robot37, robot38, robot39, robot40, robot41};
      Position2dProxy p2dProxys[SWARM_SIZE] = {p2dProxy_robot0, p2dProxy_robot1, p2dProxy_robot2, p2dProxy_robot3, p2dProxy_robot4, p2dProxy_robot5, p2dProxy_robot6, p2dProxy_robot7, p2dProxy_robot8, p2dProxy_robot9, p2dProxy_robot10, p2dProxy_robot11, p2dProxy_robot12, p2dProxy_robot13, p2dProxy_robot14, p2dProxy_robot15, p2dProxy_robot16, p2dProxy_robot17, p2dProxy_robot18, p2dProxy_robot19, p2dProxy_robot20, p2dProxy_robot21, p2dProxy_robot22, p2dProxy_robot23, p2dProxy_robot24, p2dProxy_robot25, p2dProxy_robot26, p2dProxy_robot27, p2dProxy_robot28, p2dProxy_robot29, p2dProxy_robot30, p2dProxy_robot31, p2dProxy_robot32, p2dProxy_robot33, p2dProxy_robot34, p2dProxy_robot35, p2dProxy_robot36, p2dProxy_robot37, p2dProxy_robot38, p2dProxy_robot39, p2dProxy_robot40, p2dProxy_robot41};
      //RangerProxy rngProxys[SWARM_SIZE] = {laserProxy_robot0, laserProxy_robot1, laserProxy_robot2, laserProxy_robot3, laserProxy_robot4, laserProxy_robot5, laserProxy_robot6, laserProxy_robot7, laserProxy_robot8, laserProxy_robot9, laserProxy_robot10, laserProxy_robot11, laserProxy_robot12, laserProxy_robot13, laserProxy_robot14, laserProxy_robot15, laserProxy_robot16, laserProxy_robot17, laserProxy_robot18, laserProxy_robot19, laserProxy_robot20, laserProxy_robot21, laserProxy_robot22, laserProxy_robot23, laserProxy_robot24, laserProxy_robot25, laserProxy_robot26, laserProxy_robot27, laserProxy_robot28, laserProxy_robot29, laserProxy_robot30, laserProxy_robot31, laserProxy_robot32, laserProxy_robot33, laserProxy_robot34, laserProxy_robot35, laserProxy_robot36, laserProxy_robot37, laserProxy_robot38, laserProxy_robot39, laserProxy_robot40, laserProxy_robot41};
      //FiducialProxy fidProxys[SWARM_SIZE]={neighbor_finderProxy_robot0, neighbor_finderProxy_robot1, neighbor_finderProxy_robot2, neighbor_finderProxy_robot3, neighbor_finderProxy_robot4, neighbor_finderProxy_robot5, neighbor_finderProxy_robot6, neighbor_finderProxy_robot7, neighbor_finderProxy_robot8, neighbor_finderProxy_robot9, neighbor_finderProxy_robot10, neighbor_finderProxy_robot11, neighbor_finderProxy_robot12, neighbor_finderProxy_robot13, neighbor_finderProxy_robot14, neighbor_finderProxy_robot15, neighbor_finderProxy_robot16, neighbor_finderProxy_robot17, neighbor_finderProxy_robot18, neighbor_finderProxy_robot19, neighbor_finderProxy_robot20, neighbor_finderProxy_robot21, neighbor_finderProxy_robot22, neighbor_finderProxy_robot23, neighbor_finderProxy_robot24, neighbor_finderProxy_robot25, neighbor_finderProxy_robot26, neighbor_finderProxy_robot27, neighbor_finderProxy_robot28, neighbor_finderProxy_robot29, neighbor_finderProxy_robot30, neighbor_finderProxy_robot31, neighbor_finderProxy_robot32, neighbor_finderProxy_robot33, neighbor_finderProxy_robot34, neighbor_finderProxy_robot35, neighbor_finderProxy_robot36, neighbor_finderProxy_robot37, neighbor_finderProxy_robot38, neighbor_finderProxy_robot39, neighbor_finderProxy_robot40, neighbor_finderProxy_robot41};
      //SimulationProxy simuProxys[SWARM_SIZE]={simProxy_robot1, simProxy_robot2, simProxy_robot3, simProxy_robot4, simProxy_robot5, simProxy_robot6, simProxy_robot7, simProxy_robot8, simProxy_robot9, simProxy_robot10, simProxy_robot11, simProxy_robot12, simProxy_robot13, simProxy_robot14, simProxy_robot15, simProxy_robot16, simProxy_robot17, simProxy_robot18, simProxy_robot19, simProxy_robot20, simProxy_robot21, simProxy_robot22, simProxy_robot23, simProxy_robot24, simProxy_robot25, simProxy_robot26, simProxy_robot27, simProxy_robot28, simProxy_robot29, simProxy_robot30, simProxy_robot31, simProxy_robot32, simProxy_robot33, simProxy_robot34, simProxy_robot35, simProxy_robot36, simProxy_robot37, simProxy_robot38, simProxy_robot39, simProxy_robot40, simProxy_robot41};
      
      cout << atoi(argv[1]) << endl;

      if(atoi(argv[1]) == 1){
            ofstream OutFile("Trade.txt");
            for(int i = 0;i<SWARM_SIZE;i++){
                  std::string pose =  std::to_string(i) + "\n"  + std::to_string(originPos[i][0]) + "\n" + std::to_string(originPos[i][1]) +"\n";
                  //cout << pose << endl;
                  OutFile << pose;  
            
            }
            OutFile.close(); 
      }

      ifstream readFile("Trade.txt");
      
	for(int j = 0;j<SWARM_SIZE;j++){
            
            plyclnts[j].Read();
            
            char id[1024] = {0};
            readFile >> id; 
            //cout << "id " << id << endl;

            char x[1024] = {0};
            readFile >> x; 
            //cout << "x " << atof(x)  << endl;

            char y[1024] = {0};
            readFile >> y; 
            //cout << "y " << atof(y) << endl;
            
            double delta_x = p2dProxys[j].GetXPos();
            double delta_y = p2dProxys[j].GetYPos();
            
            originPos[j][0] = atof(x) + delta_x;
            originPos[j][1] = atof(y) + delta_y;  

            fstream file("Trade.txt", ios::out);

            ofstream OutFile("Trade.txt");
            for(int i = 0;i<SWARM_SIZE;i++){
                  std::string pose =  std::to_string(i) + "\n"  + std::to_string(originPos[i][0]) + "\n" + std::to_string(originPos[i][1]) +"\n";
                  //cout << pose << endl;
                  OutFile << pose;  
            }
            OutFile.close();  
      }
      
      if(atoi(argv[1]) == 10){
            fstream file("Trade.txt", ios::out);
            double x;
            double y;
            double xmax;
            double ymax;
            double ymin;
            double xval[SWARM_SIZE] = {0};
            double yval[SWARM_SIZE] = {0};
            ofstream outFile;
	      outFile.open("reach.csv", ios::out);
            for(int i = 0;i<SWARM_SIZE;i++){
                  //cout << "x :" << originPos[i][0] << " y: " << originPos[i][1] <<endl;
                  double delta_x = p2dProxys[i].GetXPos();
                  double delta_y = p2dProxys[i].GetYPos();
                  x = originPos_copy[i][0] + delta_x;
                  y = originPos_copy[i][1] + delta_y;
                  xval[i] = x;
                  yval[i] = y;
                  //cout << "id: " << i <<" delta x :" << delta_x << " delta y: " << delta_y <<endl;
                  //cout << "id: " << i <<" x :" << x << " y: " << y <<endl;
                  
                  outFile  << x << ',' << y <<endl;   
            }
            /*
            sort(xval,xval+SWARM_SIZE);
            sort(yval,yval+SWARM_SIZE);
            xmax = xval[SWARM_SIZE-1];
            ymax = yval[SWARM_SIZE-1];
            ymin = yval[0];
            
            cout << "x max : " << xmax << endl;
            cout << "y max : " << ymax << endl;
            cout << "y min : " << -ymin << endl;
            /*
            //ifstream readFile("reach.csv");
            char content[1024] = {0};
            readFile >> content; 
            ofstream OutFile("reach.csv");
            OutFile << content << xmax << ',' << ymax << ',' << ymin << "\n";
            */

      }
         
     
      return 0;

}     
