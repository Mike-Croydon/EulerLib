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

	//This function uses the Sieve of Eratosthenes algorithm to calculate all primes < a max
	std::vector<int>  Primes::sieveE(int max)
	{
		std::vector<int> nums, marked, primes;
		int p = 2;
		for (int i = 1; i <= max; i++)
		{
			nums.push_back(i);
			marked.push_back(0);
		}

		//This is the main loop. Numbers that are non-prime are marked that way by placing a 1 at their corresponding index
		for (int i = 0; i < max; i++)
		{
			while (p < max)
			{
				int marker = p * p;
				if (marker > max) { break; }	//once the marker is initially greater than the max all future markers will be greater than the max
				//non-primes are marked in this while loop
				while (marker < max)
				{
					marked[marker - 1] = 1;
					marker += p;
				}
				//This loop finds the next number which hasn't been marked
				while (p < max)
				{
					p++;
					if (marked[p - 1] == 0) { break; }
				}
			}
		}
		//This loops copies all the marked numbers to a new vector containing only primes
		for (int i = 0; i < max; i++)
		{
			if (marked[i] == 0)
			{
				primes.push_back(i + 1);
			}
		}

		primes.erase(primes.begin()); //removes 1
		primes.erase(primes.end() - 1); //removes max

		return primes;
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

	//Checks a given 2d vector of ints and returns the largest horizontal product of n elements. Assumes gridVec is more than n elements wide
	long int Misc::calcMaxHorizProduct(const std::vector <std::vector<int>> & gridVec, int n)
	{
		long int max = 0;
		long int product = 1;
		for (int i = 0; i < gridVec.size(); i++)
		{
			for (int j = 0; j < gridVec[0].size() - n + 1; j++)
			{
				for(int k = 0; k < n; k++)
				{
					product *= gridVec[i][j + k];
				}
				product > max ? max = product : product;
				product = 1;
			}
		}
		return max;
	}

	//Checks a given 2d vector of ints and returns the largest vertical product of n elements. Assumes gridVec is more than n elements tall
	long int Misc::calcMaxVertProduct(const std::vector <std::vector<int>> & gridVec, int n)
	{
		long int max = 0;
		long int product = 1;
		for (int i = 0; i < gridVec.size() - n + 1; i++)
		{
			for (int j = 0; j < gridVec[0].size(); j++)
			{
				for (int k = 0; k < n; k++)
				{
					product *= gridVec[i+k][j];
				}
				product > max ? max = product : product;
				product = 1;
			}
		}
		return max;
	}

	//Checks a given 2d vector of ints and returns the largest right diagonal product of n elements.
	long int Misc::calcMaxRDiagProduct(const std::vector <std::vector<int>> & gridVec, int n)
	{
		long int max = 0;
		long int product = 1;
		for (int i = 0; i < gridVec.size() - n + 1; i++)
		{
			for (int j = 0; j < gridVec[0].size() - n + 1; j++)
			{
				for (int k = 0; k < n; k++)
				{
					product *= gridVec[i + k][j + k];
				}
				product > max ? max = product : product;
				product = 1;
			}
		}
		return max;
	}

	//Checks a given 2d vector of ints and returns the largest left diagonal product of n elements.
	long int Misc::calcMaxLDiagProduct(const std::vector <std::vector<int>> & gridVec, int n)
	{
		long int max = 0;
		long int product = 1;
		for (int i = 0; i < gridVec.size() - n + 1; i++)
		{
			for (int j = n-1; j < gridVec[0].size(); j++)
			{
				for (int k = 0; k < n; k++)
				{
					product *= gridVec[i + k][j - k];
				}
				product > max ? max = product : product;
				product = 1;
			}
		}
		return max;
	}

	//Calculates the divisors of a given long long int and returns the divisor in a vector
	std::vector<long long int> Misc::getDivisors(long long int num)
	{
		long long int i = 1;
		std::vector<long long int> divisors;
		while (i <= sqrt(num))
		{
			if (num % i == 0)
			{
				divisors.push_back(i);
				divisors.push_back(num / i);
			}
			++i;
		}
		return divisors;
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

#pragma endreion PythTriple
}