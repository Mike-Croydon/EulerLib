//This is a library of useful functions created help solve the Project Euler problems
#include "stdafx.h"
#include "EulerLib.h"
#include <cmath>

namespace EulerLib
{
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
}