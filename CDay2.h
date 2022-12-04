/*
 * CDay2.h
 *
 *  Created on: 03-Dec-2022
 *      Author: nayan
 */

#ifndef CDAY2_H_
#define CDAY2_H_

#include <string>
#include <vector>
#include <map>

class CDay2
{
private:
	unsigned int score;
	std::vector<char> m_day2Opp;
	std::vector<char> m_day2Own;
	std::map<char, int> ownM;
	enum result {lose = 0, draw = 3, win = 6};

public:
	CDay2();
	enum puzzlePart{ part1, part2};
	void getData(std::vector<std::string> gameData);
	unsigned int myRoundResult(char opp, char own, CDay2::puzzlePart part);
	void calculateScore(CDay2::puzzlePart part);
	virtual ~CDay2();
};

#endif /* CDAY2_H_ */
