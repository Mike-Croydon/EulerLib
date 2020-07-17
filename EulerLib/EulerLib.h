#pragma once
#include <string>

namespace EulerLib
{
	class Primes {
	public:
		bool isPrime(int n);
		int nextHighestPrime(int p);
	};

	class Misc {
	public:
		std::string reverseString(std::string s);
		bool isPalindrome(int p);
	};
}