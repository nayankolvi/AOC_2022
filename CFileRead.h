/*
 * CFileRead.h
 *
 *  Created on: 16-Nov-2022
 *      Author: nayan
 */

#ifndef FILEOPERATION_CFILEREAD_H_
#define FILEOPERATION_CFILEREAD_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class CFileRead
{

private:
	std::string m_data;
	std::string m_path;

public:
	CFileRead(std::string path = "");
	void readFromFile();
	void print();
	virtual ~CFileRead();
	const std::string& getMData() const;
};

#endif /* FILEOPERATION_CFILEREAD_H_ */
