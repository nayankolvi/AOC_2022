
#include "CDay1.h"
#include <iostream>


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
    CFileRead dataRead("D:\\nayan\\docs\\AOC\\AOC2022\\day1.txt");
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
    auto iter = totalCalories.end();
    unsigned int sum = 0;
    do
    {
        if(sum == 0)
        {
            cout << "Highest calories is: " <<  *iter << endl;
        }
        
        iter = iter -3;
    }while(iter != totalCalories.end())
    

    return 0;
}

CDay1::~CDay1()
{

}



