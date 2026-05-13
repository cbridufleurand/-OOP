#ifndef ROTATE_H
#define ROTATE_H

#include "Filter.h"

class Rotate : public Filter {
private:
    int degrees;

public:
    Rotate(int deg);

    void apply(Grid& pixels) override;

    std::string name() const override;
};

#endif
