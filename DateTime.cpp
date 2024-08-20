#define _CRT_SECURE_NO_WARNINGS
#include "DateTime.h"
#include <iostream>
#include <string>
#include <ctime>

using std::string;

struct UDateTime::DateTime {
	unsigned int year;
	unsigned int month;
	unsigned int day;
	unsigned int hour;
	int minutes;
	int seconds;
};

string FormatDigits(unsigned int value);

UDateTime::DateTime* UDateTime::Now() {
	time_t currentTime = time(NULL);
	tm* formatTm = localtime(&currentTime);

	return CreateDateTime(formatTm->tm_year + 1900, formatTm->tm_mon + 1, formatTm->tm_mday, formatTm->tm_hour, formatTm->tm_min, formatTm->tm_sec);
}

UDateTime::DateTime* UDateTime::CreateDateTime(unsigned int year , unsigned int month, unsigned int day, unsigned int hour, int minutes, int seconds) {
	if (month < 1 || month > 12 || day < 1 || day > 31 || hour > 23 || minutes > 59 || seconds > 59) {
		return NULL;
	}
	DateTime* newDateTime = new DateTime;
	newDateTime->year = year;
	newDateTime->month = month;
	newDateTime->day = day;
	newDateTime->hour = hour;
	newDateTime->minutes = minutes;
	newDateTime->seconds = seconds;

	return newDateTime;
}

unsigned int UDateTime::GetYear(const DateTime* dateTime) {
	return dateTime->year;
}

unsigned int UDateTime::GetMonth(const DateTime* dateTime) {
	return dateTime->month;
}

unsigned int UDateTime::GetDay(const DateTime* dateTime) {
	return dateTime->day;
}

unsigned int UDateTime::GetHour(const DateTime* dateTime) {
	return dateTime->hour;
}

unsigned int UDateTime::GetMinutes(const DateTime* dateTime) {
	return dateTime->minutes;
}

unsigned int UDateTime::GetSeconds(const DateTime* dateTime) {
	return dateTime->seconds;
}

string UDateTime::ToFormat(const DateTime* dateTime, DateTimeFormat format) {
	string formattedDateTime;

	unsigned int year = GetYear(dateTime);
	unsigned int month =GetMonth(dateTime);
	unsigned int day = GetDay(dateTime);
	unsigned int hour = GetHour(dateTime);
	int minutes = GetMinutes(dateTime);
	int seconds = GetSeconds(dateTime);

	switch (format) {
		case YYYYMMDD_HHmmss:
			formattedDateTime = std::to_string(year) + "-" + FormatDigits(month) + "-" + FormatDigits(day) + " " +
				FormatDigits(hour) + ":" + FormatDigits(minutes) + ":" + FormatDigits(seconds);
			break;

		case YYYYMMDD_hhmmss:
			formattedDateTime = std::to_string(year) + "-" + FormatDigits(month) + "-" + FormatDigits(day) + " " +
				FormatDigits((hour % 12 == 0 ? 12 : hour % 12)) + ":" + FormatDigits(minutes) + ":" + FormatDigits(seconds) +
				" " + (hour < 12 ? "a.m." : "p.m.");
			break;

		case DDMMYYYY_hhmmss:
			formattedDateTime = FormatDigits(day) + "-" + FormatDigits(month) + "-" + std::to_string(year) + " " +
				FormatDigits((hour % 12 == 0 ? 12 : hour % 12)) + ":" + FormatDigits(minutes) + ":" + FormatDigits(seconds) +
				" " + (hour < 12 ? "a.m." : "p.m.");
			break;

		case DDMMYYYY_HHmmss:
			formattedDateTime = FormatDigits(day) + "-" + FormatDigits(month) + "-" + std::to_string(year) + " " +
				FormatDigits(hour) + ":" + FormatDigits(minutes) + ":" + FormatDigits(seconds);
			break;

		case YYYYMMDDHHmmss:
			formattedDateTime = std::to_string(year) + FormatDigits(month) + FormatDigits(day) +
				FormatDigits(hour) + FormatDigits(minutes) + FormatDigits(seconds);
			break;

		case YYMD_Hms:
			formattedDateTime = FormatDigits(year % 100) + "-" + std::to_string(month) + "-" + std::to_string(day) + " " +
				std::to_string(hour) + ":" + std::to_string(minutes) + ":" + std::to_string(seconds);
			break;

		case YYMD_hms:
			formattedDateTime = FormatDigits(year % 100) + "-" + std::to_string(month) + "-" + std::to_string(day) + " " +
				FormatDigits((hour % 12 == 0 ? 12 : hour % 12)) + ":" + FormatDigits(minutes) + ":" + FormatDigits(seconds) +
				" " + (hour < 12 ? "a.m." : "p.m.");
			break;

		case DMYY_hms:
			formattedDateTime = std::to_string(day) + "-" + std::to_string(month) + "-" + FormatDigits(year % 100) + " " +
				FormatDigits((hour % 12 == 0 ? 12 : hour % 12)) + ":" + FormatDigits(minutes) + ":" + FormatDigits(seconds) +
				" " + (hour < 12 ? "a.m." : "p.m.");
			break;

		case DMYY_Hms:
			formattedDateTime = std::to_string(day) + "-" + std::to_string(month) + "-" + FormatDigits(year % 100) + " " +
				FormatDigits(hour) + ":" + FormatDigits(minutes) + ":" + FormatDigits(seconds);
			break;

		default:
			break;
	}
	return formattedDateTime;
}

void UDateTime::DestroyDateTime(DateTime* dateTime) {
	delete dateTime;
}

string FormatDigits(unsigned int value) {
	if (value < 10) {
		return "0" + std::to_string(value);
	}
	else {
		return std::to_string(value);
	}
}