/*  Name - Patrick Soisson
 *  Email - patrick.b.soisson@gmail.com
 *  Date - 5/15/19
 *
 *  Description head.h is used to connect main.cc and tclap.cc so they both can use the enums in the global map variable and to also 
 *  have access to functions in eachother
 */

  #include <map>
  #include <string>
  #include <iostream>
  using namespace std;

  #ifndef head_h 
  #define head_h

  extern map<int, string> tclap_map;
  enum par{column_number, file_name};
  bool tclap(int, char**);

  #endif

