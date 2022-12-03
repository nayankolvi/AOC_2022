/*
 * CProcessData.cpp
 *
 *  Created on: 16-Nov-2022
 *      Author: nayan
 */

#include "CProcessData.h"

using namespace std;

CProcessData::CProcessData(std::string data)
{
	m_data = data;
}

void CProcessData::getLineWithSeperator(char sep)
{

	std::stringstream ss(m_data);
    std::string token;
    while (std::getline(ss, token, '\n')) {
        m_resultstr.push_back(token);
    }
}

void CProcessData::print()
{
	for(auto const& v : m_resultstr)
	{
		cout << v << endl;
	}
}

CProcessData::~CProcessData()
{
	// TODO Auto-generated destructor stub
}

const std::string& CProcessData::getMData() const
{
	return m_data;
}

const std::vector<int>& CProcessData::getMResult() const
{
	return m_result;
}

const std::vector<std::string>& CProcessData::getMResultstr() const
{
	return m_resultstr;
}
