#include "days_old.h"

bool Days_old::leap_year(int year)
{
	if (year % 4 == 0 && year % 100 != 0) { return true; }
	else { return false; }
}

int Days_old::next_leap(int year)
{
	while (!leap_year(year)) { year++; } return year;
}

int Days_old::number_of_leap_years(int currentYear, int birthYear)
{
	if (leap_year(birthYear)) {
		return (currentYear - birthYear) / 4;
	}
	else {
		int nextLeap = next_leap(birthYear);
		return (currentYear - nextLeap) / 4;
	}
}

int Days_old::birth_year_days_old(int year, int month, int day)
{
	if (leap_year(year)) {

		int days{ 0 };

		for (int i = month + 1; i < 13; ++i)
		{
			days += month_days_leap[i];
		}

		return days + (month_days_leap[month] - day);
	}
	else {
		int days{ 0 };

		for (int i = month + 1; i < 13; ++i)
		{
			days += month_days[i];
		}

		return days + (month_days[month] - day);
	}
}

int Days_old::remaining_days_in_current_month(int month, int day, int year)
{
	if (leap_year(year)) { return month_days_leap[month] - day; }
	else { return month_days[month] - day; }
}
