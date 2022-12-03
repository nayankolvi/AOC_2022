
#include "CDay1.h"
#include <iostream>
#include <algorithm>


#include "CFileRead.h"
#include "CProcessData.h"

using namespace std;

CCalorie::CCalorie()
{

}

void CCalorie::addCalorie(unsigned int data)
{
    calories.push_back(data);
}

unsigned int CCalorie::totalSumCalorie()
{
    unsigned int sum = 0;

    for(auto const& param : calories)
    {
        sum = sum + param;
    }
    
    return sum;
}

CCalorie::~CCalorie()
{

}

CDay1::CDay1()
{
    CFileRead dataRead("day1.txt");
    dataRead.readFromFile();

    CProcessData processData(dataRead.getMData());
    processData.getLineWithSeperator('\n');

    addElf(processData.getMResultstr());
    

}

void CDay1::addElf(std::vector<std::string> elfCalorieData)
{
    unsigned int elfindex = 1;
    CCalorie calorie;

    for(auto const& elfCalorie : elfCalorieData)
	{
        if(elfCalorie !=  "")
        {
            calorie.addCalorie(stoul(elfCalorie));
        }
        else
        {
            elfData.emplace(std::pair<unsigned int, CCalorie>(elfindex, calorie));
            elfindex = elfindex + 1;
            calorie = CCalorie();
        }
	}
}

unsigned int CDay1::calculateHighestCalories()
{
    for(auto& elf : elfData)
    {
        totalCalories.insert(elf.second.totalSumCalorie());
    }

    // task 1 output
    int sum = 0;
    for(int idx = -3 ; idx < 0; idx++)
    {
    	sum = sum + *std::next(totalCalories.end(), idx);

    	if(idx == -1)
    	{
    		cout << "The elf with Highest Calorie is: " << *std::next(totalCalories.end(), idx) << endl;
    	}
    }
    
    cout << "The total calorie of tops 3 elf is: " << sum<< endl;


    return 0;
}

CDay1::~CDay1()
{

}



