#ifndef BETTER_ASSERT_INCLUDED_
#define BETTER_ASSERT_INCLUDED_

static_assert( __cplusplus >= 201703L, "C++17 is a must for this library, please update your compiler!" );

#include <iostream>
#include <cstdlib>
#include <iomanip>

namespace better_assert_private_space
{
    template< typename... Args >
    void print_assertion(std::ostream& out, Args&&... args)
    {
        #ifndef NDEBUG
        out.precision( 20 );
        (out << ... << args) << std::endl;
        abort();
        #endif
    }
}

#ifdef better_assert
    #undef better_assert
#endif

#define better_assert(EXPRESSION, ... ) ((EXPRESSION) ? (void)0 : better_assert_private_space::print_assertion(std::cerr, "Assertion failure: `",  #EXPRESSION, "` in File: `", __FILE__, "` in function: `", __func__, "` in Line: ",  __LINE__ __VA_OPT__(,) __VA_ARGS__))

#endif

