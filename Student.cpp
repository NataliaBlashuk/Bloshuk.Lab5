#include <iostream>
#include <string.h>
#include "Student.h"

using namespace std;

Student::Student() {}

Student::~Student() {}

void Student::SetFirstName(char* s)
{
	strcpy(firstName, s);
}

void Student::SetSecondName(char* s)
{
	strcpy(secondName, s);
}

void Student::SetMiddleName(char* s)
{
	strcpy(middleName, s);
}

void Student::SetGender(char* s)
{
	strcpy(gender, s);
}

void Student::SetNationality(char* s)
{
	strcpy(nationality, s);
}

void Student::SetBirthDate(int yearB, int monthB, int dayB)
{
	this->yearB = yearB;
	this->monthB = monthB;
	this->dayB = dayB;
}

void Student::SetPassingScore(int score)
{
	this->score = score;
}

void Student::SetMarks(int* A)
{
	for (int i = 0; i < M; i++)
		marks[i] = A[i];
}

void Student::SetStudent(char* s1, char* s2, char* s3, char* s4, char* s5, int n1, int n2, int n3, int n4, int* a)
{
	SetFirstName(s1);
	SetSecondName(s2);
	SetMiddleName(s4);
	SetGender(s3);
	SetNationality(s5);
	SetBirthDate(n1, n2, n3);
	SetPassingScore(n4);
	SetMarks(a);
}

char* Student::GetFirstName()
{
	return firstName;
}

char* Student::GetSecondName()
{
	return secondName;
}

char* Student::GetMiddleName()
{
	return middleName;
}

char* Student::GetGender()
{
	return gender;
}

char* Student::GetNationality()
{
	return nationality;
}

int Student::GetDateBirth()
{
	return yearB, monthB, dayB;
}

int Student::GetPassingScore()
{
	return score;
}

void Student::DisplayStudent()
{
	cout << endl << firstName << " " << secondName << " " << middleName << ", \t";
	cout << gender << " " << nationality << ", \t" << yearB << "/" << monthB << "/" << dayB << ", \t" << score << ", \t";
	cout << "\tMarks ";
	for (int i = 0; i < M; i++)
		cout << marks[i] << "  ";
}
