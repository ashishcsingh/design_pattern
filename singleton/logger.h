#ifndef LOGGER_H
#define LOGGER_H

#include <mutex>
#include <string>
#include <iostream>

class Logger {
   public:
      enum LEVEL {
         ERROR,
         WARNING,
         INFO,
         VERBOSE,
         TRIVIA,
         DEBUG
      };
      void Log(LEVEL level, const std::string& str) {
         std::lock_guard<std::mutex> locker(mutexLog_);
         std::cout<<"["<<CurrentDateTime()<<"] ["<<GetLevel(level)
            <<"] ["<<str<<"] "<<std::endl;
      }
      static Logger* GetLogger() {
         if(logger_!= nullptr) {
            return logger_;
         }
         std::lock_guard<std::mutex> locker(mutexLog_);
         if(logger_!=nullptr) {
            return logger_;
         }
         logger_ = new Logger();
         return logger_;
      }
      const char* GetLevel(LEVEL level) {
         switch(level) {
            case ERROR: return "ERROR";
            case WARNING: return "WARNING";
            case INFO: return "INFO";
            case VERBOSE: return "VERBOSE";
            case TRIVIA: return "TRIVIA";
            case DEBUG: return "DEBUG";
            default: return "UNKNOWN";
         };
      }
      const std::string CurrentDateTime() {
          time_t     now = time(0);
          struct tm  tstruct;
          char       buf[80];
          tstruct = *localtime(&now);
          strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
          return buf;
      }

   protected:
      Logger() {}
      ~Logger() { delete logger_; };
      static Logger* logger_;
      static std::mutex mutexLog_;
};

std::mutex Logger::mutexLog_;
Logger* Logger::logger_ = nullptr;
#endif
