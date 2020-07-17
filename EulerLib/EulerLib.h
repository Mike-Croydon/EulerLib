#pragma once
#include <string>

namespace EulerLib
{
	class Primes {
	public:
		static bool isPrime(int n);
		static int nextHighestPrime(int p);
	};

	class Misc {
	public:
		static std::string reverseString(std::string s);
		static bool isPalindrome(int p);
	};
}