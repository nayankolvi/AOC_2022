/*
 * CDay6.cpp
 *
 *  Created on: 06-Dec-2022
 *      Author: nayan
 */

#include "CDay6.h"

#include <iostream>
#include <algorithm>


#include "CFileRead.h"
#include "CProcessData.h"

using namespace std;

CDay6::CDay6(std::string inputData, std::string sequence)
{
	m_inputData = inputData;
	m_sequence = sequence;

	CFileRead dataRead("day6.txt");
    dataRead.readFromFile();

    CProcessData processData(dataRead.getMData());
    processData.getLineWithSeperator('\n');

    getData(processData.getMResultstr());

}

void CDay6::getData(std::vector<std::string> data)
{
	for(auto& str: data)
	{
		m_inputData = str;
	}
}

void CDay6::task1()
{
	unsigned int pos = task(4);
	cout << "Task1: The Pattern is : " << m_sequence << endl ;
	cout << "Task1: Data pattern Found after position : " << pos<< endl;
}

unsigned int CDay6::task(unsigned int data)
{
	std::set<char> ch;

	for(unsigned int pos = 0; pos < m_inputData.size() ; pos++ )
	{

		m_sequence = m_inputData.substr(pos, data);

		for(auto& val : m_sequence)
		{
			ch.insert(val);
		}


		if(ch.size() < data)
		{
			ch.clear();
			m_sequence.clear();
		}
		else
		{
			return (pos + data);
		}
	}

	return 0;
}

void CDay6::task2()
{
	unsigned int pos = task(14);
	cout << "Task2: The Pattern is : " << m_sequence << endl ;
	cout << "Task2: Data pattern Found after position : " << pos<< endl;
}

CDay6::~CDay6()
{
	// TODO Auto-generated destructor stub
}

