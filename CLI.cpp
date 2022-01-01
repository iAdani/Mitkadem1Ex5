#include "CLI.h"

CLI::CLI(DefaultIO* dio): dio(dio) {
    commands = {
            new Command1(dio), new Command2(dio), new Command3(dio),
            new Command4(dio), new Command5(dio), new Command6(dio)
    };
    isRunning = true;
}

void CLI::start(){
    commandNum = commands.
    // creating the text for the menu
    string menu = "";
    menu += "Welcome to the Anomaly Detection Server.\n";
    menu += "Please choose an option:\n";
    for (int i = 0; i < 6; i++) {

    }
    while (isRunning) {

    }

}


CLI::~CLI() {
    for(int i = 0; i < 6; i++) {
        delete commands[i];
    }
}
