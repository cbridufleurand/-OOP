# Program 3

Name: Claude Dufleurand  
Class: CMPS 2143  
Assignment: Program 3  
Date: April 2026  

This program builds an image filter pipeline using the Strategy pattern.

The program loads an image, applies filters in the order given on the command line, and saves the modified image.

Each filter is implemented as its own class that inherits from the Filter interface.

---

# Filters Implemented

- Grayscale
- FlipH
- FlipV
- Rotate

The program also supports provided filters:

- Brighten
- Blur

---

# Grayscale Formula

I used the luminance grayscale formula:

```text
gray = 0.299*r + 0.587*g + 0.114*b
