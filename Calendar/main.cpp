#include <iostream>

static const int month_days[13]{ 0,31,28,31,30,31,30,31,31,30,31,30,31 };
static const int month_days_leap[13]{ 0,31,29,31,30,31,30,31,31,30,31,30,31 };

// true if leap year
bool leap_year(int year) {
	if (year % 4 == 0 && year%100!=0)
	{
		return true;
	}
	else
		return false;
}

// enter a year and calc next leap year.
int next_leap(int year) { while (!leap_year(year)) { year++; } return year; }

int number_of_leap_years(int currentYear, int birthYear){
	// born on leap year ?
	if (leap_year(birthYear)) {
		return (currentYear - birthYear) / 4;
	}
	else {
		int nextLeap = next_leap(birthYear);
		return (currentYear - nextLeap) / 4;
	}
}

int days_in_month(int month, int year) {
	bool isLeap{ false };
	isLeap = leap_year(year);
	

	if (isLeap) {
		return month_days_leap[month];
	}
	else
		return month_days[month];
}

int birth_year_days_old(int year, int month, int day){

	if (leap_year(year)) {
		int days{ 0 };
		
		// i < 13 will go over the end of the array
		for (int i = month + 1; i < 13; ++i)
		{
			days += month_days_leap[i];
		}
		
		return days + (month_days_leap[month] - day);
	}
	else {
		int days{ 0 };

		// i < 13 will go over the end of the array?
		for (int i = month + 1; i < 13; ++i)
		{
			days += month_days[i];
		}

		return days + (month_days[month] - day);
	}
}
int remaining_days_in_current_month(int month, int day, int year) {
	
	if (leap_year(year)) {
		return month_days_leap[month] - day;
	}
	else
		return month_days[month] - day;
}

int main()
{
	static const int days_in_leap_year{ 366 };
	static const int days_in_nonleap_year{ 365 };
	int birth_year{ 0 };
	int birth_month{ 0 };
	int birth_day{ 0 };
	int current_year{ 0 };
	int current_month{ 0 };
	int current_day{ 0 };

	std::cout << "Enter Birth Year: " << std::endl;
	std::cin >> birth_year;
	std::cout << "Enter Birth Day: " << std::endl;
	std::cin >> birth_day;
	std::cout << "Enter Numerical Birth Month: " << std::endl;
	std::cin >> birth_month;

	std::cout << "Enter Current Year: " << std::endl;
	std::cin >> current_year;
	std::cout << "Enter Current Day: " << std::endl;
	std::cin >> current_day;
	std::cout << "Enter Current Numerical Month: " << std::endl;
	std::cin >> current_month;

	int totalLeap = number_of_leap_years(current_year, birth_year);
	int years = current_year - birth_year;
	int totalNonLeap = years - totalLeap;
	
	// days in first year
	int first_year_days = birth_year_days_old(birth_year, birth_month, birth_day); // 317
	// days in leap years
	int totalLeapDays = totalLeap * days_in_leap_year;
	// days in non leap years
	int totalNonleapDays = totalNonLeap * days_in_nonleap_year;
	
	int remaining_days_current_month = remaining_days_in_current_month(current_month, current_day, current_year);
	// days in leap + non leap + first ?
	int total_days_old = totalNonleapDays + totalLeapDays + first_year_days - remaining_days_current_month;
	
	std::cout << total_days_old << std::endl;

	return 0;
}