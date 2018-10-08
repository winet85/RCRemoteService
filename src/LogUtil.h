/*
 * LogUtil.h
 *
 *  Created on: 2017. 4. 28.
 *      Author: JOON
 */

#ifndef SRC_LOGUTIL_H_
#define SRC_LOGUTIL_H_

#include <string>
#include <sstream>
#define LOG_TYPE 0

typedef enum LogType{
		NON, INFO, ERROR, VERVOSE
};
using namespace std;
static class LogUtil{

public :
	static LogUtil Log()
	{
		return mInstance;
	}
	static void i(string msg,string file,uint32_t line) { printLog(INFO, msg,file,line); }
	static void e(string msg,string file,uint32_t line) { printLog(ERROR, msg,file,line); }
	static void v(string msg,string file,uint32_t line) { printLog(VERVOSE, msg,file,line); }
private :

	static LogUtil mInstance;
	static void printLog(LogType type, string msg, string file, uint32_t line){
		if(LOG_TYPE >= type) {
			stringstream ss;
			string typestring;
			switch(type){
				case INFO:
					typestring = "INFO";
				break;
				case ERROR:
					typestring = "ERROR";
				break;
				case VERVOSE:
					typestring = "VERVOSE";
				break;
				default :
				break;

			}
			std::cout << "["<< typestring << "]" << msg  << ":" << file << line << std::endl;
		}
	}
};

#define LOG_INFO(msg) LogUtil::Log().i(msg,__FILE__, __LINE__)
#define LOG_ERROR(msg) LogUtil::Log().e(msg,__FILE__, __LINE__)
#define LOG_VERVOSE(msg) LogUtil::Log().v(msg,__FILE__, __LINE__)
#endif /* SRC_LOGUTIL_H_ */
