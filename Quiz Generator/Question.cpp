#include "Question.h"
#include "CString.h"
#include <iostream>
using namespace std;

Question::Question() :statement(), answer(), marks(0), difficulty(1)
{
}
Question::Question(CString q, CString a, float m, int diff) : Question()
{
	statement = q;
	answer = a;

	if (m >= 0)
	{
		marks = m;
	}
	if (diff <= 0)
	{
		difficulty = 1;
	}
	else if (diff >= 4)
	{
		difficulty = 3;
	}
	else
	{
		difficulty = diff;
	}
}
void Question::setStatement(CString question)
{
	if (question.isEmpty())
	{
		statement.~CString();
		return;
	}
	statement = question;
}
void Question::setAnswer(CString ans)
{
	if (ans.isEmpty())
	{
		answer.~CString();
		return;
	}
	answer = ans;
}
void Question::setMarks(float mark)
{
	if (mark >= 0)
	{
		marks = mark;
	}
}
void Question::setDifficulty(int diff)
{
	if (diff <= 0)
	{
		difficulty = 1;
	}
	else if (diff >= 4)
	{
		difficulty = 3;
	}
	else
	{
		difficulty = diff;
	}
}

CString Question::getStatement()const
{
	return statement;
}
CString Question::getAnswer()const
{
	return answer;
}
float Question::getMarks()const
{
	return marks;
}
int Question::getDifficulty()const
{
	return difficulty;
}

void Question::printQuestion()const
{
	cout << "\nDifficulty: ";
	for (int i = 0; i < difficulty; i++)
	{
		cout << "*";
	}
	cout << "\nMarks(" << marks << ")\n-------------------\n";
	cout << "Question:\n\t";
	statement.display();
	cout << "Answer:\n\t";
	answer.display();
}
Question::~Question()
{
	statement.~CString();
	answer.~CString();
	marks = 0;
	difficulty = 0;
}