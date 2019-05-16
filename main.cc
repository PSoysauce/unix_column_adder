/* Name - Patrick Soisson
 * Email - patrick.b.soisson@gmail.com
 * Date - 5/15/19
 *
 * Description - main.cc will hold all the main functionality of this program
 *
 */
 
 #include "head.h"

 int main(int argc, char** argv) {
    tclap(argc, argv);
    int sum = column_addition();
    cout << sum << endl;
    return 0;
 }
