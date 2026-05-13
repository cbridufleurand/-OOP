#include "Args.h"
#include "Image.h"
#include "Pipeline.h"

#include "Grayscale.h"
#include "Brighten.h"
#include "Blur.h"
#include "FlipH.h"
#include "FlipV.h"
#include "Rotate.h"

#include <iostream>

int main(int argc, char* argv[]) {

    Args args = Args::parse(argc, argv);

    args.print();

    Image img(args.input);

    std::cout << "\nLoaded: ";
    img.printInfo();

    Pipeline pipeline;

    for (const auto& step : args.order) {

        if (step == "grayscale") {
            pipeline.add(new Grayscale());
        }

        else if (step == "blur") {
            pipeline.add(new Blur());
        }

        else if (step == "flipH") {
            pipeline.add(new FlipH());
        }

        else if (step == "flipV") {
            pipeline.add(new FlipV());
        }

        else if (step == "brighten") {
            pipeline.add(new Brighten(args.brighten));
        }

        else if (step == "rotate") {
            pipeline.add(new Rotate(args.rotate));
        }
    }

    pipeline.printSteps();

    pipeline.run(img.pixels());

    img.save(args.output);

    std::cout << "Saved: " << args.output << "\n";

    return 0;
}
