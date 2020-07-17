#pragma once
#include <string>
#include <cmath>
#include <vector>

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
		static bool divCheck(long long int num, std::vector<int> testVals);
	};
}