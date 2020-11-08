#include "Quiz.h"
#include"Question.h"
#include<iostream>
using namespace std;

Quiz::Quiz(int q) : quizList(nullptr)
{
	if (q >= 0)
	{
		noOfQuestions = q;
	}
	else
	{
		noOfQuestions = 0;
	}
	quizList = new Question * [noOfQuestions];
	for (int i = 0; i < q; i++)
	{
		quizList[i] = new Question;
	}
}
void Quiz::printQuiz()const
{
	if (quizList == nullptr || noOfQuestions == 0)
	{
		cout << "Nothing found in quiz!";
		return;
	}
	int totalMarks = 0;
	for (int i = 0, count = 1; i < noOfQuestions; i++, count++)
	{
		cout << "\n-----------------Question # " << i + 1 << "-----------------\n";
		quizList[i]->printQuestion();
		totalMarks = totalMarks + quizList[i]->getMarks();
	}
	cout << "\nTotal Marks : " << totalMarks << "\n<<<<<<<<<<<<<<<<<<Quiz Ended>>>>>>>>>>>>>>>>>>\n";
}
Question* Quiz::getQuizList(int i)
{
	return quizList[i];
}

Quiz::~Quiz()
{
	//we will not delete quizList due to shallow copy
	if (quizList == nullptr)
	{
		noOfQuestions = 0;
		return;
	}
	quizList = nullptr;
	noOfQuestions = 0;
}