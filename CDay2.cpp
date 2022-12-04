/*
 * CDay2.cpp
 *
 *  Created on: 03-Dec-2022
 *      Author: nayan
 */

#include "CDay2.h"
#include <iostream>
#include <algorithm>


#include "CFileRead.h"
#include "CProcessData.h"

using namespace std;



CDay2::CDay2()
{
    CFileRead dataRead("day2.txt");
    dataRead.readFromFile();

    CProcessData processData(dataRead.getMData());
    processData.getLineWithSeperator('\n');

    score = 0;
    ownM = { {'A', 1}, {'B', 2} , {'C', 3}};
    getData(processData.getMResultstr());

}


void CDay2::getData(std::vector<std::string> gameData)
{
	for(auto const& elem : gameData)
	{
		std::string val = elem ;
		m_day2Own.push_back(val.back());
		m_day2Opp.push_back(val.front());
	}
}

unsigned int CDay2::myRoundResult(char opp, char own, CDay2::puzzlePart part)
{
	int result = 0;
	if (part == CDay2::part1)
	{
		own = own - 23;
	}
	else
	{
		if( own == 'Z' )
		{
			if(opp == 'A' || opp == 'B')
			{
				own = opp + 1;
			}
			else
			{
				own = 'A';
			}
		}
		else if(own == 'X')
		{
			if(opp == 'B' || opp == 'C')
			{
				own = opp - 1;
			}
			else
			{
				own = 'C';
			}
		}
		else
		{
			own = opp;
		}
	}


	if(opp == own)
	{
		result = CDay2::draw + ownM.at(own);
	}
	else if((opp == 'A' && own == 'B') || (opp == 'B' && own == 'C') || (opp == 'C' && own == 'A') )
	{
		result = CDay2::win + ownM.at(own);
	}
	else
	{
		result = CDay2::lose + ownM.at(own);
	}

	return result;
}

void CDay2::calculateScore(CDay2::puzzlePart part)
{
	unsigned int idx = 0;
	auto iter = m_day2Own.begin();
	int sum = 0;
	score = 0;

	for(auto& val : m_day2Opp)
	{
		sum = sum + myRoundResult( val , *std::next(iter, idx), part);
		idx = idx + 1;
	}

	cout << "Score is:" << sum << endl;

										}

CDay2::~CDay2()
{
	// TODO Auto-generated destructor stub
}

