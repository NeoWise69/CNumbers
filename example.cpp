#include "BSEntry.h"

#define BS_INT_USE_STRINGS // used for constructors which takes strings as a parameter
#include "BSInteger.hpp"

#include <iostream>

using i32 = basic_integer<int>;
using i8 = basic_integer<char>;

void test(int a) {}

void testp32(i32* a) { *a = 12; }
void testp8(i8* a) { *a = 12; }

void BSStart(const BSEntryArgs& args) noexcept
{
	{
		i32 i = 142;
		int q = i.as<int>();
		i = i + 1;
		i = i + i;
		i32 i2;
		auto res = i == i2;
		i2 = i;
		res = i == i2;
		res = i < i2;
		res = i != -286;
		res = i < 21;
		i2 += 1;
		i2 += i2;
		i2 += i + 21;
		i2 /= 2;
		i2 = "213";
		test(i);
		testp32(&i);
		i++;
		++i;
		std::cout << i;
		std::cout << i2;
	}
	{
		i8 i = 127;
		char q = i.as<char>();
		i = i + 1;
		i = i + i;
		i8 i2;
		auto res = i == i2;
		i2 = i;
		res = i == i2;
		res = i < i2;
		res = i != -286;
		res = i < 21;
		i2 += 1;
		i2 += i2;
		i2 /= 2;
		i2 = "22";
		test(i);
		testp8(&i);
		i++;
		++i;
		std::cout << i;
		std::cout << i2;
	}
}

void BSExit(int& code) noexcept
{
	
}

BSEntryDecl()
