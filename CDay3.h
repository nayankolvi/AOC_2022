/*
 * CDay3.h
 *
 *  Created on: 04-Dec-2022
 *      Author: nayan
 */

#ifndef CDAY3_H_
#define CDAY3_H_

#include <string>
#include <vector>

class CDay3
{
private:
	std::vector<std::string> m_origData;
	std::vector<std::string> m_container1;
	std::vector<std::string> m_container2;
	std::vector<char> m_containerIntersection;

public:
	CDay3();
	void getData(std::vector<std::string> data);
	void findIntersection(std::string data1, std::string data2);
	unsigned int getPriorityValue(char data);
	void task2();
	void task1();
	virtual ~CDay3();
};

#endif /* CDAY3_H_ */
