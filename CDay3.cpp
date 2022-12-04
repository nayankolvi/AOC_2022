/*
 * CDay3.cpp
 *
 *  Created on: 04-Dec-2022
 *      Author: nayan
 */

#include "CDay3.h"

#include <iostream>
#include <algorithm>


#include "CFileRead.h"
#include "CProcessData.h"

using namespace std;


CDay3::CDay3()
{
    CFileRead dataRead("day3.txt");
    dataRead.readFromFile();

    CProcessData processData(dataRead.getMData());
    processData.getLineWithSeperator('\n');

    getData(processData.getMResultstr());
    m_origData = processData.getMResultstr();

}

void CDay3::getData(std::vector<std::string> data)
{

	for(const auto& val: data)
	{
		auto size = val.size();
		unsigned int pos = (unsigned int)size / 2;
		m_container1.push_back(val.substr(0, pos));
		m_container2.push_back(val.substr(pos, pos));
	}
}

void CDay3::task1()
{

	auto iter1 = m_container1.begin();
	//auto iter2 = m_containerIntersection.begin();

	unsigned int idx = 0;
	unsigned int prioritySum = 0;

	for(auto& val : m_container2)
	{
		findIntersection( val , *std::next(iter1, idx));
		//cout << *std::next(iter1, idx) << " " << val << endl;
		// << " " << *std::next(iter2, idx) <<
		idx = idx + 1;
	}

	for(auto& val : m_containerIntersection)
	{
		prioritySum = prioritySum + getPriorityValue(val);
	}


	cout << "The sum of priorities is: " << prioritySum << endl;
}

void CDay3::findIntersection(std::string data1, std::string data2)
{
	for(auto& str1: data1)
	{
		for(auto& str2: data2)
		{
			if(str1 == str2)
			{
				m_containerIntersection.push_back(str1);
				return;
			}
		}
	}
}


unsigned int CDay3::getPriorityValue(char data)
{
	unsigned int val = 0;


	if((('A' <= data) && ('Z' >= data)))
	{
		val = data + 27 - 'A';
	}
	else if(('a' <= data) && ('z' >= data))
	{
		val = data + 1 - 'a';
	}
	return val;
}

void CDay3::task2()
{
	m_containerIntersection.clear();

	bool found = false;
	unsigned int prioritySum = 0;


	for(auto iter1 = m_origData.begin(); iter1!= m_origData.end() ; iter1 = std::next(iter1, 3) )
	{
		for(auto& str1: *iter1)
		{
			for(auto& str2: *std::next(iter1, 1))
			{
				if(str1 == str2)
				{
					for(auto& str3: *std::next(iter1, 2))
					{
						if(str2 == str3)
						{
							m_containerIntersection.push_back(str1);
							found = true;
							break;
						}
					}

					if(found == true)
					{
						break;
					}
				}
				else
				{
					continue;
				}
			}
			if(found == true)
			{
				found = false;
				break;
			}
		}
	}



	for(auto& val : m_containerIntersection)
	{
		prioritySum = prioritySum + getPriorityValue(val);
	}


	cout << "The sum of priorities of all groups is : " << prioritySum << endl;


}

CDay3::~CDay3()
{
	// TODO Auto-generated destructor stub
}

