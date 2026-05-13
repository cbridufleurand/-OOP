# Program 4

Name: Claude Dufleurand  
Class: CMPS 2143  
Assignment: Program 4  
Date: May 2026  

This program extends the image filter pipeline from Program 3 by adding a `Color` class, convolution kernels, and kernel-based image effects.

The program can load an image, apply filters in the order typed on the command line, and save the edited image.

---

# What This Program Does

This program supports:

- Color objects instead of raw pixel structs
- Operator overloading for color math
- Named color constructors
- Kernel-based filters
- Convolution effects
- Program 3 filters such as grayscale, flip, rotate, and brighten

---

# Color Class

The `Color` class stores red, green, and blue values.

It supports operators such as:

- `+` for adding colors
- `*` for scaling colors
- `==` for comparing colors
- `!=` for checking if colors are different
- `<<` for printing colors
- `>>` for reading colors

It also supports named constructors:

- `fromRGB`
- `fromHex`
- `fromHSL`

---

# HSL Algorithm

For `Color::fromHSL`, I used the standard HSL to RGB conversion algorithm.

This algorithm converts hue, saturation, and lightness into red, green, and blue channel values.

One test case I verified:

```text
HSL(0, 1, 0.5) = RGB(255, 0, 0)
