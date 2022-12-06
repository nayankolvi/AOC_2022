/*
 * CDay6.h
 *
 *  Created on: 06-Dec-2022
 *      Author: nayan
 */

#ifndef CDAY6_H_
#define CDAY6_H_

#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>


class CDay6
{
	std::string m_inputData;
	std::string m_sequence;

public:
	CDay6(std::string inputData = "", std::string sequence = "" );
	void getData(std::vector<std::string> data);
	unsigned int task(unsigned int data);
	void task1();
	void task2();
	virtual ~CDay6();
};

#endif /* CDAY6_H_ */
