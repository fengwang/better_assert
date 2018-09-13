
## Better Assert macro in C++17

Yet another assert macro, enabling additional debug information dump.

Typical usage:

```cpp
double const a = 3.14159265358979;
double const b = 2.0 * std::asin( 1.0 );
better_assert( a==b, " a is supposed to be equal to b, but now a = ", a, " and b = ", b );
// or conventional way
//better_assert( (a==b) && "a is supposed to be equal to b" );
```

and output:

```
Assertion failure: a==b in File: test.cc in Line: 9 a is supposed to be equal to b, but now a = 3.1415926535897900074 and b = 3.141592653589793116
[1]    8414 abort (core dumped)  ./test
```

