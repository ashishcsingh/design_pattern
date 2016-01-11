#include "logger.h"

#include <thread>
#include <vector>

using namespace std;

void Log() {
   Logger* log = Logger::GetLogger();
   log->Log(Logger::INFO, string("Logging from thread "));
}
   

int main() {
  vector<thread> threads;
   for(int i=0; i<10; ++i) {
      threads.push_back(thread(Log));
   }
   for(int i=0; i<10; ++i) {
      threads[i].join();
   }
}
