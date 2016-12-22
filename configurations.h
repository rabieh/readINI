#ifndef CONFIGURATIONS_H
#define CONFIGURAIONS_H
#include <iostream>
#include <fstream>
#include <string>
#include<array>
#include<typeinfo.h>
#include<tchar.h>
#include<algorithm>
#include <windows.h> 
#include<stdio.h>

using namespace std;

class Configurations {

public:

	Configurations();
	~Configurations();
	void readConfigFile(char *, char *, char [100], char *);
	void readConfigFile();

};

#endif // !

