/*
 * CDay4.cpp
 *
 *  Created on: 04-Dec-2022
 *      Author: nayan
 */

#include "CDay4.h"

#include <iostream>
#include <algorithm>


#include "CFileRead.h"
#include "CProcessData.h"

using namespace std;

CDay4::CDay4()
{
    CFileRead dataRead("day4.txt");
    dataRead.readFromFile();

    CProcessData processData(dataRead.getMData());
    processData.getLineWithSeperator('\n');

    getData(processData.getMResultstr());
    //m_origData = processData.getMResultstr();

}

void CDay4::getData(std::vector<std::string> data)
{
	for(const auto& str : data)
	{
		std::string str1 = str.substr(0, str.find(','));
		std::string str2 = str.substr(str.find(',')+1, (str.size() - str.find('-')));

		m_group1.push_back(getSetValues(str1));
		m_group2.push_back(getSetValues(str2));
	}



//	for(auto& val: m_group2)
//	{
//		for(auto& idx: val)
//		{
//			cout << idx << " ";
//		}
//
//		cout << endl;
//	}
}

std::set<int> CDay4::getSetValues(std::string data)
{
	std::set<int> val;

	std::string str1 = data.substr(0, data.find('-'));
	std::string str2 = data.substr(data.find('-')+1, (data.size() - data.find('-')));

	for(int idx = std::stoi(str1) ; idx<= std::stoi(str2) ;idx++)
	{
		val.insert(idx);
	}

	return val;
}

void CDay4::tasks()
{

	unsigned int count = 0;
	unsigned int overallOverlap = 0;

	auto iter2 = m_group2.begin();

	unsigned int idx = 0;
	for(auto& iter1 : m_group1)
	{
		std::vector<int> intersectedData;
		std::set_intersection(iter1.begin(), iter1.end(), (*std::next(iter2, idx)).begin(), (*std::next(iter2, idx)).end(), std::back_inserter(intersectedData));

//		cout << "the size is; " << intersectedData.size() << endl;


		if(intersectedData.size() == iter1.size() || intersectedData.size() == (*std::next(iter2, idx)).size())
		{
//			for(const auto& val : intersectedData)
//			{
//				cout << val << " ";
//			}
//			cout << endl;
			count = count + 1;
		}

		if(intersectedData.size() > 0)
		{
			overallOverlap = overallOverlap + 1;
		}

		idx = idx + 1;
	}

	cout << "The total values which have common values is: " << count << endl;
	cout << "The total no of overlaps is: " << overallOverlap << endl;
}

CDay4::~CDay4()
{
	// TODO Auto-generated destructor stub
}

