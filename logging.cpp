#include "logging.h"

//extern ostream cout;

LogMessage:: LogMessage(Severity severity): LogMessage(severity, __FUNCTION__ , __FILE__, __LINE__)
{
	fprintf(stderr,"Base class constructor called\n");

}

LogMessage:: LogMessage(): LogMessage(__FUNCTION__ , __FILE__, __LINE__)
{
	fprintf(stderr,"Base class constructor called\n");

}

LogMessage:: LogMessage(Severity severity,std::string message): LogMessage(message, severity, __FUNCTION__ , __FILE__, __LINE__)
{
	fprintf(stderr,"Base class constructor called\n");

}


LogMessage::LogMessage(Severity severity, const char* funcName,const char* fileName, int line)
{
	fprintf(stderr,"Initializing 4 parameter using parameterized constructor\n");
	severity_ = severity;
	funcName_ = funcName;
	line_ = line;
	fileName_ = fileName; 
}

LogMessage::LogMessage(const char* funcName,const char* fileName, int line)
{
	fprintf(stderr,"Initializing all the parameter using parameterized constructor\n");
	funcName_ = funcName;
	line_ = line;
	fileName_ = fileName; 
}

LogMessage::LogMessage(std::string message, Severity severity, const char* funcName,const char* fileName, int line)
{
	fprintf(stderr,"Initializing 5 parameters using parameterized constructor\n");
	severity_ = severity;
	funcName_ = funcName;
	line_ = line;
	fileName_ = fileName; 
	message_ =  message;
}

LogMessage:: ~LogMessage()
{
	PrintLogMessage();
}

void LogMessage::PrintLogMessage()
{
	if (!str().empty())
	{
	fprintf(stderr,"%s | %s | %s  |  %d |  %s | %s \n", SeverityName[severity_].c_str(), fileName_, funcName_, line_, str().c_str(),message_.c_str());
	}
    else
	{
    fprintf(stderr,"%s | %s | %s  |  %d | %s \n", SeverityName[severity_].c_str(), fileName_, funcName_, line_ ,message_.c_str());
	}
}

LogMessageFatal::LogMessageFatal():LogMessage()
{

fprintf(stderr,"Inside default Constructor!\n");

}

LogMessageFatal::LogMessageFatal(const char* funcName,const char* fileName, int line):LogMessage(funcName,fileName,line)
{
	fprintf(stderr, "Inside parameterized cons!\n" );
}

LogMessageFatal::LogMessageFatal(Severity severity, const char* funcName,const char* fileName, int line):LogMessage(severity,funcName,fileName,line)
{
}


LogMessageFatal::~LogMessageFatal()
{
	PrintLogMessage();
	abort();
}


