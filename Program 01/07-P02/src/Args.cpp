#include "Args.h"

#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

bool startsWith(const std::string& s, const std::string& prefix) {
    return s.rfind(prefix, 0) == 0;
}

std::pair<std::string, std::string> splitEq(const std::string& token) {
    size_t pos = token.find('=');

    if (pos == std::string::npos) {
        return {token, ""};
    }

    return {token.substr(0, pos), token.substr(pos + 1)};
}

std::string lowerString(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c) {
                       return static_cast<char>(std::tolower(c));
                   });
    return s;
}

bool isImageFile(const std::string& filename) {
    std::string lower = lowerString(filename);

    std::vector<std::string> extensions = {
        ".png", ".jpg", ".jpeg", ".bmp", ".ppm"
    };

    for (const std::string& ext : extensions) {
        if (lower.size() >= ext.size() &&
            lower.substr(lower.size() - ext.size()) == ext) {
            return true;
        }
    }

    return false;
}

void usage() {
    std::cerr << "Usage: ./imgtool <input_image> <output_image> [options]\n";
}

void fail(const std::string& message) {
    std::cerr << "Error: " << message << "\n";
    usage();
    std::exit(1);
}

bool looksLikeOption(const std::string& token) {
    return startsWith(token, "-");
}

int parseInteger(const std::string& value, const std::string& optionName) {
    try {
        size_t index = 0;
        int number = std::stoi(value, &index);

        if (index != value.size()) {
            fail("invalid integer for '" + optionName + "': '" + value + "'");
        }

        return number;
    } catch (const std::invalid_argument&) {
        fail("invalid integer for '" + optionName + "': '" + value + "'");
    } catch (const std::out_of_range&) {
        fail("invalid integer for '" + optionName + "': '" + value + "'");
    }

    return 0;
}

std::string getValue(int& i, int argc, char* argv[], const std::string& optionName) {
    if (i + 1 >= argc) {
        fail("'" + optionName + "' requires an integer value");
    }

    std::string value = argv[i + 1];

    if (looksLikeOption(value)) {
        fail("'" + optionName + "' expected a value but got option '" + value + "'");
    }

    ++i;
    return value;
}

void setFlag(Args& args, char option) {
    if (option == 'g') {
        args.grayscale = true;
    } else if (option == 'l') {
        args.blur = true;
    } else if (option == 'h') {
        args.flipH = true;
    } else if (option == 'v') {
        args.flipV = true;
    } else {
        fail("unknown option '-" + std::string(1, option) + "'");
    }
}

Args Args::parse(int argc, char* argv[]) {
    Args args;

    if (argc < 2) {
        fail("input file is required");
    }

    if (argc < 3) {
        fail("output file is required");
    }

    args.input = argv[1];
    args.output = argv[2];

    if (!isImageFile(args.input)) {
        fail("input file must be a recognized image extension");
    }

    if (!isImageFile(args.output)) {
        fail("output file must be a recognized image extension");
    }

    for (int i = 3; i < argc; ++i) {
        std::string token = argv[i];
        auto parts = splitEq(token);
        std::string option = parts.first;
        std::string value = parts.second;

        if (option == "--grayscale") {
            args.grayscale = true;
        } else if (option == "--blur") {
            args.blur = true;
        } else if (option == "--flipH") {
            args.flipH = true;
        } else if (option == "--flipV") {
            args.flipV = true;
        } else if (option == "--brighten") {
            if (value.empty()) {
                value = getValue(i, argc, argv, option);
            }

            int number = parseInteger(value, option);

            if (number < -255 || number > 255) {
                fail("'--brighten' must be in [-255, 255]");
            }

            args.use_brighten = true;
            args.brighten = number;
        } else if (option == "--rotate") {
            if (value.empty()) {
                value = getValue(i, argc, argv, option);
            }

            int number = parseInteger(value, option);

            if (!(number == 0 || number == 90 || number == 180 || number == 270)) {
                fail("'--rotate' must be one of {0, 90, 180, 270}");
            }

            args.use_rotate = true;
            args.rotate = number;
        } else if (token == "-g") {
            args.grayscale = true;
        } else if (token == "-l") {
            args.blur = true;
        } else if (token == "-h") {
            args.flipH = true;
        } else if (token == "-v") {
            args.flipV = true;
        } else if (token == "-b") {
            std::string numberText = getValue(i, argc, argv, token);
            int number = parseInteger(numberText, token);

            if (number < -255 || number > 255) {
                fail("'-b' must be in [-255, 255]");
            }

            args.use_brighten = true;
            args.brighten = number;
        } else if (token == "-r") {
            std::string numberText = getValue(i, argc, argv, token);
            int number = parseInteger(numberText, token);

            if (!(number == 0 || number == 90 || number == 180 || number == 270)) {
                fail("'-r' must be one of {0, 90, 180, 270}");
            }

            args.use_rotate = true;
            args.rotate = number;
        } else if (startsWith(token, "-") && !startsWith(token, "--") && token.size() > 2) {
            for (size_t j = 1; j < token.size(); ++j) {
                char optionChar = token[j];

                if (optionChar == 'b' || optionChar == 'r') {
                    fail("grouped short flags cannot include options that require values");
                }

                setFlag(args, optionChar);
            }
        } else {
            fail("unknown option '" + token + "'");
        }
    }

    return args;
}

void Args::print() const {
    std::cout << "INPUT  : " << input << "\n";
    std::cout << "OUTPUT : " << output << "\n";

    std::cout << "FLAGS  :";

    if (grayscale) {
        std::cout << " grayscale";
    }

    if (blur) {
        std::cout << " blur";
    }

    if (flipH) {
        std::cout << " flipH";
    }

    if (flipV) {
        std::cout << " flipV";
    }

    std::cout << "\n";

    std::cout << "PARAMS :";

    if (use_brighten) {
        std::cout << " brighten=" << brighten;
    }

    if (use_rotate) {
        std::cout << " rotate=" << rotate;
    }

    std::cout << "\n";
}
