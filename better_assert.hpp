#ifndef BETTER_ASSERT_INCLUDED_
#define BETTER_ASSERT_INCLUDED_

static_assert( __cplusplus >= 201703L, "C++17 is a must for this library, please update your compiler!" );

#include <iostream>
#include <cstdlib>
#include <iomanip>

namespace better_assert_private_space
{
    #ifdef NDEBUG
        constexpr std::uint_least64_t debug_mode = 0;
    #else
        constexpr std::uint_least64_t debug_mode = 1;
    #endif

    template< typename... Args >
    void print_assertion(std::ostream& out, Args&&... args)
    {
        out.precision( 20 );
        if constexpr( debug_mode )
        {
            (out << ... << args) << std::endl;
            abort();
        }
    }
}

#ifdef better_assert
    #undef better_assert
#endif

#define better_assert(EXPRESSION, ... ) ((EXPRESSION) ? (void)0 : better_assert_private_space::print_assertion(std::cerr, "Assertion failure: ",  #EXPRESSION, " in File: ", __FILE__, " in Line: ",  __LINE__ __VA_OPT__(,) __VA_ARGS__))

#endif

