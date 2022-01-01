

#ifndef COMMANDS_H_
#define COMMANDS_H_

#include<iostream>
#include <string.h>

#include <fstream>
#include <vector>
#include "HybridAnomalyDetector.h"

using namespace std;

class DefaultIO{
public:
	virtual string read()=0;
	virtual void write(string text)=0;
	virtual void write(float f)=0;
	virtual void read(float* f)=0;
	virtual ~DefaultIO(){}

	// you may add additional methods here
};

class StandardIO  : public DefaultIO{

    // reads from the user
    virtual string read(){
        string input;
        cin >> input;
        return input;
    }

    // writes to screen
    virtual void write(string text){
        cout << text;
    }

    // writes to screen
    virtual void write(float f){
        cout << f;
    }

    // reads from the user
    virtual void read(float* f){
        cin >> *f;
    }
};


// you may edit this class
class Command{
	DefaultIO* dio;
    string description;
public:
	Command(DefaultIO* dio, string des):dio(dio){
        description = des;
    }
	virtual void execute()=0;
	virtual ~Command(){}
};

//      Command Classes

// For command 1: used to upload a time series csv file
class Command1 : public Command{
public:
    Command1(DefaultIO* dio) : Command(dio,  "upload a time series csv file"){}

    virtual void execute(){

    }
};

// For command 2: used to set algorithm settings
class Command2 : public Command{
    Command2(DefaultIO* dio) : Command(dio,  "algorithm settings"){}

    virtual void execute(){}
};

// For command 3: used to detect anomalies
class Command3 : public Command{
    Command3(DefaultIO* dio) : Command(dio,  "detect anomalies"){}

    virtual void execute(){}
};

// For command 4: used to display results
class Command4 : public Command{
    Command4(DefaultIO* dio) : Command(dio,  "display results"){}

    virtual void execute(){}
};

// For command 5: used to upload anomalies and analyze results
class Command5 : public Command{
    Command5(DefaultIO* dio) : Command(dio,  "upload anomalies and analyze results"){}

    virtual void execute(){}
};

// For command 6: used to exit
class Command6 : public Command{
    Command6(DefaultIO* dio) : Command(dio,  "exit"){}

    virtual void execute(){}
};


#endif /* COMMANDS_H_ */
