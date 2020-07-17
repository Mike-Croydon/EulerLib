//This is a library of useful functions created help solve the Project Euler problems
#include "stdafx.h"
#include "EulerLib.h"



namespace EulerLib
{
#pragma region Primes
	//Brute force checks every number < sqrt(2*n) to see if n is prime
	bool Primes::isPrime(int n)
	{
		for (int i = 2; i < sqrt(2*n); i++)
		{
			if ((n % i) == 0)
			{
				return false;
			}
		}
		return true;
	}

	//Brute force checks every numberabove input using isPrime() as a check
	int Primes::nextHighestPrime(int p)
	{
		p++;
		while (!isPrime(p))
		{
			p++;
		}
		return p;
	}

#pragma endregion Primes

#pragma region Misc
	std::string Misc::reverseString(std::string s)
	{
		std::string temp;
		for (int i = s.length() - 1; i >= 0; i--)
		{
			temp.push_back(s[i]);
		}
		return temp;
	}

	//checks if a number is a palindrome. Returns true if it is
	bool Misc::isPalindrome(int p)
	{
		std::string str = std::to_string(p);
		std::string rev = reverseString(str);
		if (str == rev)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//Checks if a number is divisible by the ints in testVals[]
	bool Misc::divCheck(long long int num, std::vector<int> testVals)
	{
		bool result = true;
		int numElems = testVals.size();
		for (int i = 0; i < numElems - 1; i++)
		{
			if ((num % testVals[i]) != 0)
			{
				return false;
			}
		}
		return true;
	}
#pragma endregion Misc

#pragma region PythTriple
	PythTriple::PythTriple(long int a, long int b, long int c)
	{
		side[0] = a;
		side[1] = b;
		hypotenuse = c;
	}
	long int * PythTriple::getABC()
	{
		long int temp[3];
		temp[0] = side[0];
		temp[1] = side[1];
		temp[2] = hypotenuse;
		return temp;
	}

	bool PythTriple::isPythTriple()
	{
		if (((side[0] * side[0]) + (side[1] * side[1])) == (hypotenuse * hypotenuse))
		{
			return true;
		}
		else { return false; }
	}

	int PythTriple::getSum()
	{
		long int sum = side[0] + side[1] + hypotenuse;
		return sum;
	}

	long int PythTriple::getProduct()
	{
		long int product = side[0] * side[1] * hypotenuse;
		return product;
	}

}