/*
 * Filename    tclap.cc
 * Date        5/15/19
 * Author      Patrick Soisson
 * Email       patrick.b.soisson@gmail.com
 * Copyright 2019, All Rights Reserved
 *
 * Description tclap.cc is going to take in all the command line input and parse it. In this file I will fill the map with parsed data   
 * once the map is created it will return to main to fufil the rest. 
 */
#include <iostream>
#include <map>
#include <tclap/CmdLine.h>
#include <string>
#include "head.h"
using namespace std;

map<int, string> tclap_map;

bool tclap(int argc, char** argv) {
  try {
    TCLAP::CmdLine cmd("column adder", ' ', "1.0");
    //TCLAP::SwitchArg dSwitch("d", "daemon", "Run in daemon mode (forks to run as a daemon).", cmd, false);
    TCLAP::UnlabeledValueArg<string> infileArg("input-filename", "The name of the configuration file. Defaults to cs3377dirmond.conf", true, "cs3377dirmond.conf", "config filename", false);
    TCLAP::UnlabeledValueArg<int> columnNumberArg("column-number", "The default number is 0, so it will do nothing", true, 0, "column number", false);

    cmd.add( infileArg );
    cmd.add( columnNumberArg );
    cmd.parse(argc, argv);
    
    //Get the arguments parsed from tclap
    string in = infileArg.getValue();    //get what user entered for input
    //int column = columnNumberArg.getValue();
    tclap_map[file_name] = in;     //sets map value outName to output.txt, unless the user enters a value
    //tclap_map[column_number] = column;
    return true;  //returns true if makes it to this point
  } catch(TCLAP::ArgException &e) {
    cerr << "Error: " << e.error() << " for arg " << e.argId() << endl;
    return false;  //returns false if there is any problem in user input
  }

}
