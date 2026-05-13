//
// args_ex1.cpp
//
// Example of what NOT to do.
// This version hardcodes argv indexes and does not safely
// check argument counts before using them.
//

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {

    // BAD:
    // Accessing argv without checking argc first.

    string input  = argv[1];
    string output = argv[2];

    cout << "Input File  : " << input << "\n";
    cout << "Output File : " << output << "\n";

    // BAD:
    // Hardcoded option positions.

    if (string(argv[3]) == "--grayscale") {
        cout << "Applying grayscale\n";
    }

    // This can crash if arguments are missing.

    return 0;
}
