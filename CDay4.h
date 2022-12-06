/*
 * CDay4.h
 *
 *  Created on: 04-Dec-2022
 *      Author: nayan
 */

#ifndef CDAY4_H_
#define CDAY4_H_

#include <string>
#include <vector>
#include <set>

class CDay4
{
	std::vector<std::set<int>> m_group1;
	std::vector<std::set<int>> m_group2;

public:
	CDay4();
	void getData(std::vector<std::string> data);
	std::set<int> getSetValues(std::string data);
	void tasks();
	virtual ~CDay4();
};

#endif /* CDAY4_H_ */
