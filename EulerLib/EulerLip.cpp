//This is a library of useful functions created help solve the Project Euler problems
#include "stdafx.h"
#include "EulerLib.h"

namespace EulerLib
{
	bool Primes::isPrime(int n)
	{
		for (int i = 2; i < n; i++)
		{
			if ((n % i) == 0)
			{
				return false;
			}
		}
		return true;
	}
}