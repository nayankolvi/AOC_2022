#include <iostream>
#include <vector>
#include <string>

#include "CDay1.h"
#include "CDay2.h"
#include "CDay3.h"
#include "CDay4.h"
#include "CDay5.h"
#include "CDay6.h"

using namespace std;



int main()
{
	cout << "Day1 output" << endl;
    CDay1 day1;
    day1.calculateHighestCalories();
    cout << endl;

    cout << "Day2 output" << endl;
	CDay2 day2;
	day2.calculateScore(CDay2::part1);
	day2.calculateScore(CDay2::part2);
	cout << endl;

	cout << "Day3 output" << endl;
	CDay3 day3;
	day3.task1();
	day3.task2();
	cout << endl;

	cout << "Day4 output" << endl;
	CDay4 day4;
	day4.tasks();
	cout << endl;

	cout << "Day5 output" << endl;
	CDay5 day5_task1;
	day5_task1.task1();
	CDay5 day5_task2;
	day5_task2.task2();
	cout << endl;

	cout << "Day6 output" << endl;
	CDay6 day6;
	day6.task1();
	day6.task2();
	cout << endl;

}
