/*
 * Filename    tclap.cc
 * Date        4/8/19
 * Author      Patrick Soisson
 * Email       pbs170030@utdallas.edu
 * Course CS 3377.501 Spring 2019
 * Version 1.0
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

map<int, string> m;

bool tclap(int argc, char** argv) {
  try {
    TCLAP::CmdLine cmd("cs3377dirmond Directory Monitor Daemon", ' ', "1.0");
    TCLAP::SwitchArg dSwitch("d", "daemon", "Run in daemon mode (forks to run as a daemon).", cmd, false);
    TCLAP::UnlabeledValueArg<string> infileArg("config-filename", "The name of the configuration file. Defaults to cs3377dirmond.conf", true, "cs3377dirmond.conf", "config filename", false);
    cmd.add( infileArg );
    cmd.parse(argc, argv);
    
    //Get the arguments parsed from tclap
    bool daemon = dSwitch.getValue();
    string in = infileArg.getValue();    //get what user entered for input
      
    m[configV] = in;     //sets map value outName to output.txt, unless the user enters a value
    if(daemon)
      m[daemonV] = "T";
    else
      m[daemonV] = "F";
    return true;  //returns true if makes it to this point
  } catch(TCLAP::ArgException &e) {
    cerr << "Error: " << e.error() << " for arg " << e.argId() << endl;
    return false;  //returns false if there is any problem in user input
  }

}
