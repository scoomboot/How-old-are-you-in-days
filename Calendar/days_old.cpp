#include "days_old.h"

Days_old::Days_old(int birth_year, int birth_month, int birth_day, int current_year, int current_month, int current_day)
{
	m_birth_year = birth_year;
	m_birth_month = birth_month;
	m_birth_day = birth_year;
	m_current_year = current_year;
	m_current_month = current_month;
	m_current_day = current_day;

}

bool Days_old::is_leap_year(int year)
{
	if (year % 4 == 0 && year % 100 != 0) { return true; }
	else { return false; }
}

int Days_old::next_leap(int year)
{
	while (!is_leap_year(year)) { year++; } return year;
}

int Days_old::total_leap_years()
{
	if (is_leap_year(m_birth_year)) {
		return (m_current_year - m_birth_year) / 4;
	}
	else {
		//int nextLeap = next_leap(m_birth_year);
		return (m_current_year - next_leap(m_birth_year)) / 4;
	}
}

int Days_old::birth_year_days_old()
{
	if (is_leap_year(m_birth_year)) {

		int days{ 0 };

		for (int i = m_birth_month + 1; i < 13; ++i)
		{
			days += month_days_leap[i];
		}

		return days + (month_days_leap[m_birth_month] - m_birth_day);
	}
	else {
		int days{ 0 };

		for (int i = m_birth_month + 1; i < 13; ++i)
		{
			days += month_days[i];
		}

		return days + (month_days[m_birth_month] - m_birth_day);
	}
}

int Days_old::remaining_days_in_current_month()
{
	if (is_leap_year(m_birth_year)) { return month_days_leap[m_birth_month] - m_birth_day; }
	else { return month_days[m_birth_month] - m_birth_day; }
}
