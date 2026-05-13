# Program 2

Name: Claude Dufleurand  
Class: CMPS 2143  
Assignment: Program 2  
Date: April 2026  

This program is a command line argument parser for an image tool.

The program reads the input file, output file, and any filter options typed on the command line.

---

# What the Program Checks

The program checks for:

- an input image file
- an output image file
- valid filter flags
- valid integer values for brighten and rotate
- invalid or unknown options
- missing values for options
- valid image file extensions

---

# Supported Options

- `--grayscale`
- `--blur`
- `--flipH`
- `--flipV`
- `--brighten <number>`
- `--rotate <degrees>`

Short options can also be used:

- `-g`
- `-l`
- `-h`
- `-v`
- `-b <number>`
- `-r <degrees>`

The program also supports:

```bash
--brighten=20
--rotate=90
