#include "robot.h"

#include <iostream>

using namespace std;

int main() {
   RobotDirector director;

   OldRobotBuilder orb;
   /*
    * Director takes builder and calls all the builder methods
    * and returns the final robot.
    */
   auto& oldRobot = director.RobotMaker(&orb);
   cout<<oldRobot;

   NewRobotBuilder newrb;
   auto& newRobot = director.RobotMaker(&newrb);
   cout<<newRobot;

   NextGenRobotBuilder nxtrb;
   auto& nextRobot = director.RobotMaker(&nxtrb);
   cout<<nextRobot;

   return 0;
}


