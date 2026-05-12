# Program 1

Name: Claude Dufleurand  
Class: CMPS 2143  
Assignment: Program 1  
Date: March 2026  

## Description

This program loads an image, converts it to grayscale, saves the new image, and then automatically attempts to open the output image using the system’s default image viewer.

The program also uses colored terminal output with the `termcolor` library.

---

## What the Program Does

The program performs these main tasks:

- loads an image from the command line
- converts the image to grayscale
- saves the output image as a PNG
- automatically opens the saved image

It supports both JPG and PNG image formats.

---

## Grayscale Formula

The program uses the luminance grayscale formula:

```text
gray = 0.299*r + 0.587*g + 0.114*b
