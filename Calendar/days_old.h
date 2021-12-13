#pragma once

class Days_old
{

public:
	Days_old(int birth_year, int birth_month, int birth_day, int current_year, int current_month, int current_day);
	bool is_leap_year(int year);
	int next_leap(int year);
	int total_leap_years();
	int birth_year_days_old();
	int years_old() { return m_current_year - m_birth_year; };
	int total_non_leap_years() { return years_old() - total_leap_years(); };
	int total_leap_days() { return total_leap_years() * m_days_in_leap_year; };
	int total_non_leap_days() { return total_non_leap_years() * m_days_in_non_leap_year; };
	int total_days_old();

private:
	static const int m_days_in_leap_year{ 366 };
	static const int m_days_in_non_leap_year{ 365 };
	int m_birth_year{ 0 };
	int m_birth_month{ 0 };
	int m_birth_day{ 0 };
	int m_current_year{ 0 };
	int m_current_month{ 0 };
	int m_current_day{ 0 };
	int m_days{ 0 };
	int m_total_days_old{ 0 };
	const int month_days[13]{ 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	const int month_days_leap[13]{ 0,31,29,31,30,31,30,31,31,30,31,30,31 };
};