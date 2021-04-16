#pragma once
#include<stdio.h>
#include<string>
#include<sstream>
using namespace std;

enum Severity{
	INFO = 0,
	WARNING = 1,
	ERROR = 2,
	FATAL = 3,
	NUM_SEV = 4,
};

const std::string SeverityName[NUM_SEV]  = {"INFO","WARNING","ERROR","FATAL"};


#define CHECK_OP(val1,op,val2)\
        if (!(val1 op val2)) LogMessageFatal( __FUNCTION__ , __FILE__, __LINE__).flush() <<"Operation failed: "<< #val1 <<"  "<< #op << "  " << #val2<<" "

#define CHECK_EQUAL(val1,val2) CHECK_OP(val1, == , val2)
#define CHECK_LESS(val1,val2)  CHECK_OP(val1, < ,val2)
#define CHECK_GREATER(val1,val2) CHECK_OP(val1, > ,val2)

#define LOG_INFO(message) LogMessage(message, INFO, __FUNCTION__ , __FILE__, __LINE__).flush()
#define LOG_FATAL() LogMessageFatal(FATAL, __FUNCTION__ , __FILE__, __LINE__).flush()
#define LOG_WARNING(message) LogMessage(message, WARNING, __FUNCTION__ , __FILE__, __LINE__).flush()
#define LOG_ERROR() LogMessage(ERROR, __FUNCTION__ , __FILE__, __LINE__).flush()

#define LOG(severity) LOG##severity

class LogMessage: public std::ostringstream
{
public:
	LogMessage();
	LogMessage(Severity);
	LogMessage(Severity,  std::string);
	LogMessage(Severity, const char*, const char*, int);
	LogMessage(const char*, const char*, int);
	LogMessage(std::string, Severity, const char*, const char*, int);
	~LogMessage();
protected:
	void PrintLogMessage();

//info that we want to print in the logs
private:
	Severity severity_;
	int line_;
	const char* fileName_;
	const char* funcName_;
	std::string message_;
};


class LogMessageFatal:public LogMessage{
public:
	LogMessageFatal();
	LogMessageFatal(const char*, const char*, int);
	LogMessageFatal(Severity, const char*, const char*, int);
	~LogMessageFatal();
};





/////////


