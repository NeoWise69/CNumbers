#include "BSEntry.h"

#define BS_FP_USE_STRINGS // used for constructors which takes strings as a parameter
#include "BSFloating.hpp"

#include <iostream>

using f64 = basic_floating_point<double>;
using f32 = basic_floating_point<float>;

void testf(float a) {}

void testpf32(f32* a) { *a = 12.012; }

void BSStart(const BSEntryArgs& args) noexcept
{
	{
		f32 f = 12.3f;
		testpf32(&f);
		double as = f.as(as);
		f = f + 1;
		f = f + f;
		f = 1.0f;
		f64 f2 = 0.5f + 0.5f;
		auto res = f == f2;
		f2 = 0.5 + 0.3 + 0.2f;
		res = f == f2;
		f = f32::epsf();
		std::cout << f << "\n" << f2 << "\n";
	}
}

void BSExit(int& code) noexcept
{
	
}

BSEntryDecl()
