# CNumbers
Generic integer class with some extra functionality compared to primitive number types.

### How To Use? ###
Just include header file and define required types:
````
using i64 = basic_integer<long long>;
using i32 = basic_integer<int>;
using i16 = basic_integer<short>;
using i8  = basic_integer<char>;

using u64 = basic_integer<unsigned long long>;
using u32 = basic_integer<unsigned int>;
using u16 = basic_integer<unsigned short>;
using u8  = basic_integer<unsigned char>;

````

#### Also... ####
Before include header file, define `BS_INT_USE_STRINGS` to work with string constructors.
```
#define BS_INT_USE_STRINGS
#include "BSInteger.h"
```
