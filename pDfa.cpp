#include "pDfa.h"

using namespace std;

pDfa::pDfa()
{
	
}

bool pDfa::scanPeriod(const string &period)
{
	if(period == ".")
	{
		return(true);
	}
	else
	{
		return(false); 
	}
}
