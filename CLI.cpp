#include "CLI.h"

CLI::CLI(DefaultIO* dio): dio(dio), detector() {
    vector<AnomalyReport> report; // "shared" by commands 3 and 4
    
    // make the commands vector
    commands.push_back(new Command1(dio));
    commands.push_back(new Command2(dio));
    commands.push_back(new Command3(dio, &report));
    commands.push_back(new Command4(dio, &report));
    commands.push_back(new Command5(dio));
    commands.push_back(new Command6(dio));

    // set the detector for the relevant commands
    commands[1]->setDetector(&detector);
    commands[2]->setDetector(&detector);
}

void CLI::start(){
    string menu = createMenu();
    string option = "";

    while (isRunning) {
        dio->write(menu);
        option = dio->read();
        if (option.compare("5") == 0) {
            exit();
        } else {
            commands[stoi(option) - 1]->execute();
        }
    }
}


CLI::~CLI() {
    for(auto c = commands.begin(); c != commands.end(); c++) {
        delete *c;
    }
}

void CLI::exit() {
	isRunning = false;
}

// creating the text for the menu
string CLI::createMenu() {
    string menu = "";
    menu += "Welcome to the Anomaly Detection Server.\n";
    menu += "Please choose an option:\n";
    menu += "1.upload a time series csv file\n2.algorithm settings";
    menu += "\n3.detect anomalies\n4.display results\n";
    menu += "5.upload anomalies and analyze results\n6.exit\n";
    return menu;
}
