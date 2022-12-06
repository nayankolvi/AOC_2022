/*
 * CDay5.cpp
 *
 *  Created on: 06-Dec-2022
 *      Author: nayan
 */

#include "CDay5.h"

#include <iostream>
#include <algorithm>


#include "CFileRead.h"
#include "CProcessData.h"

using namespace std;

CDay5::CDay5()
{
    CFileRead dataRead("day5.txt");
    dataRead.readFromFile();

    CProcessData processData(dataRead.getMData());
    processData.getLineWithSeperator('\n');

    getData(processData.getMResultstr());
    //m_origData = processData.getMResultstr();

}


void CDay5::getData(std::vector<std::string> data)
{

	enum parse { parse1, parse2 };
	parse p_t = parse1;

	for(const auto& str : data)
	{

		if(p_t == parse2)
		{
			if(str != "")
			{
				unsigned int pos1 = str.find("ve");
				unsigned int pos2 = str.find("fr");

				std::string str1 = str.substr(pos1 + 3, pos2 - pos1 - 3);

				pos1 = str.find("om");
				pos2 = str.find("to");
				std::string str2 = str.substr(pos1 + 3, pos2 - pos1 - 3);

				std::string str3 = str.substr(pos2 + 3, str.size() - pos2 - 3);

				//cout << str1 << str2 << str3 << endl;
				m_moves.push_back(Move(std::stoul(str1) , std::stoul(str2)  , std::stoul(str3)));


			}
		}

		if(p_t == parse1)
		{
			int count = 1;

			if(str != "")
			{
				for(size_t pos = 0; pos < str.size() ;pos = pos + 4)
				{
					std::string str1 = str.substr(pos, 3);
					if(str1 != "   ")
					{
						m_containerData[count].addElementToStackBack(str1.at(1));
						//cout << count << " " <<  str1.at(1) << endl;
					}
					count = count + 1;
				}
			}
			else
			{
	//			for(auto& val: m_containerData)
	//			{
	//				for(auto& data: val.second.getMStack())
	//				{
	//					cout << data << " ";
	//				}
	//				cout << endl;
	//			}
	//
	//			break ;
				p_t = parse2;
				continue;
			}
		}





	}


}

void CDay5::task1()
{
	// task 1
	for(auto& move : m_moves)
	{
		for(unsigned int i = 0; i < move.getNoOfMoves() ; i++)
		{
			m_containerData[move.getToStack()].addElementToStackFront(m_containerData[move.getFromStack()].transferElementfromStack());
		}
	}

	std::string output = "";

	for(auto& move : m_containerData)
	{
		output = output + move.second.getMStack().front();
	}

	cout << "Output fo first Task is: " << output << endl;
}


void CDay5::task2()
{

	for(auto& move : m_moves)
	{
		std::vector<char> data;
		for(unsigned int i = 0; i < move.getNoOfMoves() ; i++)
		{
			data.push_back(m_containerData[move.getFromStack()].transferElementfromStack());
		}

		while(data.size() != 0)
		{
			m_containerData[move.getToStack()].addElementToStackFront(data.back());
			data.pop_back();
		}
	}

	std::string output = "";

	for(auto& move : m_containerData)
	{
		output = output + move.second.getMStack().front();
	}

	cout << "Output of second Task is: " << output;
}


CDay5::~CDay5()
{
	// TODO Auto-generated destructor stub
}

Stack::Stack(unsigned int filled)
{
	m_filled_level = filled;

}

void Stack::addElementToStackBack(char val)
{
	m_stack.push_back(val);
	m_filled_level++;
}

void Stack::addElementToStackFront(char val)
{
	m_stack.push_front(val);
	m_filled_level++;
}

const std::list<char>& Stack::getMStack() const
{
return m_stack;
}

char Stack::transferElementfromStack()
{
	if(m_filled_level > 0)
	{
		char retVal = m_stack.front();
		m_stack.pop_front();
		m_filled_level--;
		return retVal;
	}

	return '\0';
}

unsigned int Move::getFromStack() const
{
	return fromStack;
}

unsigned int Move::getNoOfMoves() const
{
	return noOfMoves;
}

Move::Move(unsigned int noOfMoves, unsigned int fromStack, unsigned int toStack)
{
	this->noOfMoves = noOfMoves;
	this->fromStack = fromStack;
	this->toStack = toStack;
}

unsigned int Move::getToStack() const
{
	return toStack;
}
