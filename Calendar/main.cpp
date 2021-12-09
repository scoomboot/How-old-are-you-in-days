#include <iostream>
#include <string>

// true if leap year
bool leap_year(int year)
{
	if (year % 4 == 0 && year%100!=0)
	{
		return true;
	}
	else
		return false;
}

// enter a year and calc next leap year.
int next_leap(int year)
{
	while (!leap_year(year))
	{
		year++;
	}
	return year;
}

int number_of_leap_years(int currentYear, int birthYear)
{
	// born on leap year ?
	if (leap_year(birthYear))
	{
		return (currentYear - birthYear) / 4;
	}
	else
	{
		int nextLeap = next_leap(birthYear);
		return (currentYear - nextLeap) / 4;
	}
}

int days_in_month(int month, int year)
{
	bool isLeap{ false };
	isLeap = leap_year(year);
	int month_days[13]{ 0,31,28,31,30,31,30,31,31,30,31,30,31};
	int month_days_leap[13]{ 0,31,29,31,30,31,30,31,31,30,31,30,31 };

	if (isLeap)
	{
		return month_days_leap[month];
	}
	else
		return month_days[month];
}

int birth_year_days_old(int year, int month, int day)
{
	int month_days[13]{ 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int month_days_leap[13]{ 0,31,29,31,30,31,30,31,31,30,31,30,31 };
	if (leap_year(year))
	{
		int days{ 0 };
		
		// i < 13 will go over the end of the array
		for (int i = month + 1; i < 13; ++i)
		{
			days += month_days_leap[i];
		}
		
		return days + (month_days_leap[month] - day);
	}
	else
	{
		int days{ 0 };

		// i < 13 will go over the end of the array
		for (int i = month + 1; i < 13; ++i)
		{
			days += month_days[i];
		}

		return days + (month_days[month] - day);
	}
}

int main()
{
	int days_in_leap_year{ 366 };
	int days_in_nonleap_year{ 365 };
	int birth_year{ 1988 };
	int birth_month{ 2 };
	int birth_day{ 18 };
	int current_year{ 2021 };
	int current_month{ 12 };
	int current_day{ 8 };

	//int month_days[13]{ 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	//int month_days_leap[13]{ 0,31,29,31,30,31,30,31,31,30,31,30,31 };



	int totalLeap = number_of_leap_years(current_year, birth_year);
	int years = current_year - birth_year;
	int totalNonLeap = years - totalLeap;
	
	
	

	// days in first year
	int first_year_days = birth_year_days_old(birth_year, birth_month, birth_day); // 317
	// days in leap years
	int totalLeapDays = totalLeap * days_in_leap_year;
	// days in non leap years
	int totalNonleapDays = totalNonLeap * days_in_nonleap_year;
	// days in leap + non leap + first ?
	int total_days_old = totalNonleapDays + totalLeapDays + first_year_days;
	
	// off by 23 days, think it has something to do with days in current month ?
	std::cout << total_days_old << std::endl;



	return 0;
}