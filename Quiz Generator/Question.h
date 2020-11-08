#ifndef QUESTION_H
#define QUESTION_H

#include "CString.h"

class Question
{
	CString statement;
	CString answer;
	float marks;
	int difficulty;
public:
	Question();
	Question(CString statement, CString answer, float marks, int difficulty);
	void printQuestion()const;
	//setters
	void setStatement(CString question);
	void setAnswer(CString ans);
	void setMarks(float mark);
	void setDifficulty(int diff);
	//getters
	CString getStatement()const;
	CString getAnswer()const;
	float getMarks()const;
	int getDifficulty()const;
	~Question();
};

#endif // !QUESTION_H
