/* Name - Patrick Soisson
 * Email - patrick.b.soisson@gmail.com
 * Date - 5/15/19
 *
 * Description - column_addition.cc will hold the functions needed to add the columns, it will use the tclap_map to figure out what file and column to add
 *
 */
 #include "head.h"

 int column_addition() {
	try {
		ifstream in;
		in.open(tclap_map[file_name]);
		string line;
		//getline( in , line );
		while(!in.eof()) {
		    getline( in , line );
		    cout << line << endl;
		    //temp = in.nextInt();
		    //cout << temp << endl;
		}
		return 0;
		
	} catch(...) {
		
	}	
	return -1;
 }
