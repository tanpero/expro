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

Please make sure that `Git` is already installed on your computer.

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

## Examples

### basic

```c++
#include <expro.h>
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    Expro expr1("1 + 2");
    std::cout << "1 + 2 =" << expr1.parse().value() << "\n";
    std::cout << "2 * 8 + 3 = " << Expro("2 * 8 + 3").parse().value() << "\n"
        << "7 * (4 - 5 * (6 + 2)) / (2 + 3) = "
        << Expro("7 * (4 - 5 * (6 + 2)) / (2 + 3)").parse().value() << "\n";
    double x = 10, y = 20;
    std::cout << "x = 10, y = 20,\n  x + y * 2 = "
        << Expro("x + y * 2").parse({{"x", &x}, {"y", &y}}).value() << "\n";
    std::cout << "my_func :: a -> a * 2 + 1,\n  my_func(10) = "
        << Expro("my_func(10)").bind("my_func", [](double a) { return a * 2 + 1; }).value() << "\n";
    return 0;
}
```

Then you will get the following outputs:

```
1 + 2 = 3
2 * 8 + 3 = 21
7 * (4 - 5 * (6 + 2)) / (2 + 3) = -50
x = 10, y = 20,
  x + y * 2 = 41
my_func :: a -> a * 2 + 1,
  my_func(10) = 21
```

## Built With

- [tinyexpr](https://github.com/codeplea/tinyexpr/) - Tiny recursive descent parser and evaluation engine in C.

## Versioning

0.1.0

## Authors

- **[Tanpero](https://github.com/tanpero/)**

## License

This project is licensed under the MIT License.
