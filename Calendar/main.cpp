#include <iostream>
#include "days_old.h"

int main()
{
	Days_old days_old(1988,2,18,2021,12,12);

	std::cout << days_old.total_days_old() << std::endl;

	return 0;
}