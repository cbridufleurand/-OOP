#include "Rotate.h"

#include <vector>

Rotate::Rotate(int deg)
    : degrees(deg) {
}

void Rotate::apply(Grid& pixels) {

    if (degrees == 0) {
        return;
    }

    size_t height = pixels.size();
    size_t width = pixels[0].size();

    Grid result;

    // 90 degrees clockwise
    if (degrees == 90) {

        result = Grid(width, std::vector<Pixel>(height));

        for (size_t row = 0; row < height; ++row) {

            for (size_t col = 0; col < width; ++col) {

                result[col][height - 1 - row] =
                    pixels[row][col];
            }
        }
    }

    // 180 degrees
    else if (degrees == 180) {

        result = Grid(height, std::vector<Pixel>(width));

        for (size_t row = 0; row < height; ++row) {

            for (size_t col = 0; col < width; ++col) {

                result[height - 1 - row][width - 1 - col] =
                    pixels[row][col];
            }
        }
    }

    // 270 degrees clockwise
    else if (degrees == 270) {

        result = Grid(width, std::vector<Pixel>(height));

        for (size_t row = 0; row < height; ++row) {

            for (size_t col = 0; col < width; ++col) {

                result[width - 1 - col][row] =
                    pixels[row][col];
            }
        }
    }

    pixels = result;
}

std::string Rotate::name() const {

    return "rotate(" + std::to_string(degrees) + ")";
}
