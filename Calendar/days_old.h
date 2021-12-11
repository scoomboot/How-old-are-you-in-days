#pragma once

class Days_old
{

	bool leap_year(int year);
	int next_leap(int year);
	int number_of_leap_years(int currentYear, int birthYear);
	//int days_in_month(int month, int year);
	int birth_year_days_old(int year, int month, int day);
	int remaining_days_in_current_month(int month, int day, int year);

private:

	static const int days_in_leap_year{ 366 };
	static const int days_in_nonleap_year{ 365 };
	int birth_year{ 0 };
	int birth_month{ 0 };
	int birth_day{ 0 };
	int current_year{ 0 };
	int current_month{ 0 };
	int current_day{ 0 };
	static const int month_days[13]{ 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	static const int month_days_leap[13]{ 0,31,29,31,30,31,30,31,31,30,31,30,31 };
};