# CNumbers
Generic numbers classes with some extra functionality compared to primitive number types.

### How To Use? ###
Just include header file and define required types:
- for BSInteger.h
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
- for BSFloating.h
````
using f32 = basic_floating_point<float>;
using f64 = basic_floating_point<double>;
````

#### Also... ####
Before include *BSInteger.h* header file, define `BS_INT_USE_STRINGS` to work with string constructors.
```
#define BS_INT_USE_STRINGS
#include "BSInteger.h"
```
...And the same for *BSFloatring.h* header file, define `BS_FP_USE_STRINGS`
```
#define BS_FP_USE_STRINGS
#include "BSFloating.h"
```
