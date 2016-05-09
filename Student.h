#pragma once

#ifndef student_h
#define student_h

const int N = 35;
const int M = 5;

class Student
{
public:
	Student();
	~Student();
	void SetFirstName(char*);
	void SetSecondName(char*);
	void SetMiddleName(char*);
	void SetGender(char*);
	void SetNationality(char*);
	void SetBirthDate(int, int, int);
	void SetPassingScore(int);
	void SetMarks(int*);

	void SetStudent(char*, char*, char*, char*, char*, int, int,int, int, int*);

	char* GetFirstName();
	char* GetSecondName();
	char* GetMiddleName();
	char* GetGender();
	char* GetNationality();
	int GetDateBirth();
	int GetPassingScore();
	void DisplayStudent();
private:
	char firstName[N], secondName[N], middleName[N], gender[M], nationality[N];
	int yearB, monthB, dayB, score, marks[M];
};

#endif
