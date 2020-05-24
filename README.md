# Cpp-Ascii-art-generator

## How to use

Basics
```
#include "art.h"
Art art;
```
To print one ascii character:
```
std::cout << art.getAsciiChar('a') << std::endl;

```
To print a ascii string:
```
std::cout << art.getAsciiString("Hello") << std::endl;

```
Both methods return `std::string`.
`getAsciiChar` takes a `char` as argument
`getAsciiString` takes a `std::string` as argument

