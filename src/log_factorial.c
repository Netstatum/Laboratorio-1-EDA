#include <math.h>
#include "log_factorial.h"



double log_factorial(unsigned int n)
{
	double factorial=0;
	unsigned int i;

	for(i=2;i<=n;i++)
	{
		factorial=factorial+log(i);
	}

	return factorial;
}
