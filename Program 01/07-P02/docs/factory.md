# Constructor vs Factory Method

For this program, I used the static factory method:

```cpp
static Args parse(int argc, char* argv[]);
```

I chose this because parsing can fail. If something is wrong, the parser prints an error message and exits.

Using a factory method keeps the creation of an `Args` object clean. The rest of the program can call:

```cpp
Args args = Args::parse(argc, argv);
```

This makes `main.cpp` short and easy to understand.
