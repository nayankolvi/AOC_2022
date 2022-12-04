/*
 * CProcessData.h
 *
 *  Created on: 16-Nov-2022
 *      Author: nayan
 */

#ifndef INTCODE_CPROCESSDATA_H_
#define INTCODE_CPROCESSDATA_H_

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>


class CProcessData
{
private:
	std::string m_data;
	std::vector<int> m_result;
	std::vector<std::string> m_resultstr;

public:
	CProcessData(std::string data = "");
	void getLineWithSeperator(char sep);
	void print();
	virtual ~CProcessData();
	const std::string& getMData() const;
	const std::vector<int>& getMResult() const;
	const std::vector<std::string>& getMResultstr() const;
};

#endif /* INTCODE_CPROCESSDATA_H_ */
