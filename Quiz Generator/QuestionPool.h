#ifndef QUESTIONPOOL_H
#define QUESTIONPOOL_H

#include "Quiz.h"
#include "Question.h"

class QuestionPool
{
	Question** pool;
	int noOfQuestions = 0;
	int capacity;
public:
	QuestionPool();
	void addQuestion(CString question, CString answer, float mark, int difficulty);
	void printQuestions()const;
	bool isPoolFull()const;
	void reSizePool(int size);
	Quiz createQuiz(int noOfQs)const;
	~QuestionPool();
};

#endif // !QUESTIONPOOL_H


