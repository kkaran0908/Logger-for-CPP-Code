#include<iostream>
#include "logging.h"
#include<string>
using namespace std;

int main()
{
    LOG_INFO("Operation greater then");
    LOG_FATAL();
	CHECK_GREATER(10,11);
	return 0;
}