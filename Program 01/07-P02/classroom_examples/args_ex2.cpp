//
// args_ex2.cpp
//
// Example of a factory pattern skeleton.
//

#include <iostream>
#include <string>

using namespace std;

class ExampleArgs {
public:

    string input;
    string output;

    static ExampleArgs parse(int argc, char* argv[]) {

        ExampleArgs args;

        if (argc > 1) {
            args.input = argv[1];
        }

        if (argc > 2) {
            args.output = argv[2];
        }

        return args;
    }

    void print() const {
        cout << "Input  : " << input << "\n";
        cout << "Output : " << output << "\n";
    }
};

int main(int argc, char* argv[]) {

    ExampleArgs args = ExampleArgs::parse(argc, argv);

    args.print();

    return 0;
}
