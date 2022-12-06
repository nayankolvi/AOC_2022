/*
 * CDay5.h
 *
 *  Created on: 06-Dec-2022
 *      Author: nayan
 */

#ifndef CDAY5_H_
#define CDAY5_H_


#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>

class Stack
{
private:
	std::list<char> m_stack;
	unsigned int m_filled_level;

public:
	Stack(unsigned int filled = 0);
	void addElementToStackBack(char val);
	void addElementToStackFront(char val);
	char transferElementfromStack();
	const std::list<char>& getMStack() const;
};

class Move
{
private:
	unsigned int noOfMoves;
	unsigned int fromStack;
	unsigned int toStack;

public:
	Move(unsigned int noOfMoves = 0, unsigned int fromStack = 0, unsigned int toStack = 0);
	unsigned int getFromStack() const;
	unsigned int getNoOfMoves() const;
	unsigned int getToStack() const;
};


class CDay5
{
private:
	std::map<unsigned int, Stack> m_containerData;
	std::vector<Move> m_moves;

public:
	CDay5();
	void getData(std::vector<std::string> data);
	void task1();
	void task2();
	virtual ~CDay5();
};

#endif /* CDAY5_H_ */
