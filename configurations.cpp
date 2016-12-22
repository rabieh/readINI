#include "configurations.h"

Configurations::Configurations() {
	//do nothing
}

Configurations::~Configurations() {
	//do nothing
}

void Configurations::readConfigFile(char *sectionName,char * keyName, char value[100], char *fileName) {
	string line;
	ifstream myfile;
	int counter = 0;
	char section[20]="";
	char key[20] = "";
	char chars[] = " ";
	
	myfile.open(fileName);
	bool sectionFound = false;
	bool separator = false;
	bool keyfound = false;
	if (myfile.is_open()) {
		
		while ( getline(myfile, line) ) {
			
			
				line.erase(std::remove_if(line.begin(), line.end(), isspace),line.end());
			
			const char * charline = line.c_str();
			if (charline[0] == ';') continue;

			cout << line << endl;
			memset(section, 0,20);
			
			if (sectionName != NULL && sectionFound==false) {

				if (charline[0] == '[' && charline[strlen(charline) - 1] == ']') {
					//a section is found.....
					for (int i = 1; i < strlen(charline) - 1; i++) {
						section[i - 1] = charline[i];
					}

					if (strcmp(section, sectionName) == 0) {
						sectionFound = true;
					}
				}
			}
			else {

				if (charline[0] == '[' && charline[strlen(charline) - 1] == ']') //beginning of a new Section
					break;
				
				separator = false;
				memset(key, 0, 20);
				memset(value, 0, 100);
				counter = 0;
				
				//cout << key << endl;
				for (int i = 0; i < strlen(charline); i++) {
					
					if (charline[i] == '=') {
						separator = true;
						counter++;
						continue;
					}
					if (!separator) {
						counter++;
						key[i] = charline[i];
					}
					else {
						value[i-counter] = charline[i];
					}
				}

				if (strcmp(key, keyName) == 0){
					keyfound = true;
					break;
				}
			}
			
		}//end while

		if (!keyfound) {
			memset(value, 0, 100);
		}
		
		myfile.close();
	}
	else {
		cout << "error in reading file" << endl;
	}
	
}