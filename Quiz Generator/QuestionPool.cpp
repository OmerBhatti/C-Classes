#include "QuestionPool.h"
#include "Question.h"
#include "Quiz.h"
#include <ctime>
#include <iostream>
using namespace std;

QuestionPool::QuestionPool() :pool(nullptr), noOfQuestions(0), capacity(10)
{
	pool = new Question * [capacity];
}
void QuestionPool::addQuestion(CString question, CString ans, float mark, int diff)
{
	if (isPoolFull())
	{
		reSizePool(capacity + 1);
	}
	pool[noOfQuestions] = new Question(question, ans, mark, diff);
	noOfQuestions++;
}
bool QuestionPool::isPoolFull()const
{
	if (noOfQuestions == capacity)
	{
		return true;
	}
	return false;
}

void QuestionPool::printQuestions()const
{
	for (int i = 0, count = 1; i < noOfQuestions; i++, count++)
	{
		cout << "\n-------------Question # " << i + 1 << "-------------\n";
		pool[i]->printQuestion();
		if (count % 10 == 0 && i != 0)
		{
			cout << "\n------------------------------------\n"
				"->Press Enter to load 10 more questions!!\n";
			cin.get();
		}
	}
	cout << "\n<<<<<<<<<<<<Questions Ended>>>>>>>>>>>>>\n";
}
void QuestionPool::reSizePool(int s)
{
	capacity = s;
	Question** poolCopy = new Question * [capacity];
	for (int i = 0; i < noOfQuestions; i++)
	{
		poolCopy[i] = new Question(pool[i]->getStatement(), pool[i]->getAnswer(), 
			pool[i]->getMarks(), pool[i]->getDifficulty());
	}
	pool = poolCopy;
}
Quiz QuestionPool::createQuiz(int noOfQs)const
{
	if (noOfQs > noOfQuestions || noOfQs < 0)
	{
		cout << "\nSorry! Not Enough Question Found for quiz in pool\nExitting......\n";
		exit(0);
	}
	//array of bools to save which number is generated before!
	bool* isAlready = new bool[noOfQuestions];
	for (int i = 0; i < noOfQuestions; i++)
		isAlready[i] = false;
	srand(time(0));
	Quiz q(noOfQs);
	for (int i = 0; i < noOfQs; i++)
	{
		int number = rand() % noOfQuestions;
		while (isAlready[number])
		{
			number = rand() % noOfQuestions;
		}
		isAlready[number] = true;

		*q.getQuizList(i) = *pool[number];
	}
	return q;
}

QuestionPool::~QuestionPool()
{
	if (pool == nullptr || noOfQuestions == 0)
	{
		pool == nullptr;
		noOfQuestions = 0;
		capacity = 0;
		return;
	}
	for (int i = 0; i < noOfQuestions; i++)
	{
		pool[i]->~Question();
	}
	delete[]pool;
	noOfQuestions = 0;
	capacity = 0;
}