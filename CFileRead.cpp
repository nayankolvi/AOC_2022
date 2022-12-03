/*
 * CFileRead.cpp
 *
 *  Created on: 16-Nov-2022
 *      Author: nayan
 */

#include "CFileRead.h"

using namespace std;

CFileRead::CFileRead(std::string path)
{
//	initialize the member attributes
	m_path = path;
	m_data = "";

}

void CFileRead::readFromFile()
{
//   declare ifstream and open the file
	ifstream ifs;
	ifs.open(m_path, ifstream::in);

//  use string stream to read the data from the readbuffer rdBuf of the ifstream
	stringstream ss;
	ss << ifs.rdbuf();

//	store data into the attribute of the class
	m_data = ss.str();
}

void CFileRead::print()
{
	cout << m_data << endl;
}

const std::string& CFileRead::getMData() const
{
	return m_data;
}

CFileRead::~CFileRead()
{

}

