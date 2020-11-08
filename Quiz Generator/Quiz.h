#ifndef QUIZ_H
#define QUIZ_H

#include"Question.h"

class Quiz
{
	Question** quizList;
	int noOfQuestions;
public:
	Quiz(int questions = 5);
	void printQuiz()const;
	Question* getQuizList(int index);
	~Quiz();
};

#endif // !QUIZ_H

