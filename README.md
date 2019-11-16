# Expro

---

**Expro** is a fast and flexible C++ expression parsing library, and it supports embedded user-defined function.

## Getting Started

Using Expro is simple.

###  Prerequisites

 In order to use **Expro**, your computer must already be installed the following tools.

- A C++ Compiler, such as Visual Studio 2017 or GCC.
- CMake.

### Installing

Please make sure that `Git` has been installed in your computer.

```
# Getting Expro from GitHub
$ git clone https://github.com/tanpero/expro.git
# Build it
$ cd expro
$ cmake . -B build && cd build
```

If you use `Visual Studio`, so should be in the build subdirectory see `expro.vcxproj` and `expro.sln`. You can directly add `expro.vcxproj` to your project in the solution, or separately build `expro.sln` and move the `expro.lib` from the output path to your project dependent path.

If you use `GNU Make`, please run

```
$ make && make install
```

and then you can get a static library.

## Running the tests

A default testing file is in path `test/main.cc`. If you completely build **expro**, you will get `expro-test` at the same time. Just run it.