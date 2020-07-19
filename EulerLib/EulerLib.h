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
		static std::vector<int> sieveE(int max);
	};

	class Misc {
	public:
		static std::string reverseString(std::string s);
		static bool isPalindrome(int p);
		static bool divCheck(long long int num, std::vector<int> testVals);
		static long int calcMaxHorizProduct(const std::vector<std::vector<int>> & gridVec, int n);
		static long int calcMaxVertProduct(const std::vector<std::vector<int>> & gridVec, int n);
		static long int calcMaxRDiagProduct(const std::vector<std::vector<int>> & gridVec, int n);
		static long int calcMaxLDiagProduct(const std::vector<std::vector<int>> & gridVec, int n);
		static std::vector<long long int> getDivisors( long long int num);
		
	};

	//This class is used to store a Pythagorean triple and has some useful functions to perform necessary calculations
	class PythTriple {
	private:
		long int side[2];
		long int hypotenuse;
	public:
		PythTriple(long int a, long int b, long int c);
		long int * getABC();
		bool isPythTriple();
		int getSum();
		long int getProduct();

	};
}