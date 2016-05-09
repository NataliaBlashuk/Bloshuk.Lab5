#include <iostream>
#include "student.h"

using namespace std;

Student InitStudent();
Student* InitArray(int);
void DisplayArray(Student*, int);
void EnterArray(int*, int&);
void SortFirstName(Student*, int);
void Swap(Student&, Student&);

int main()
{
	int n;
	cout << "Enter the number of students ";
	cin >> n;
	system("cls");
	Student* students = InitArray(n);
	if (!students)
	{
		cout << "\nDynamic array doesn't exist!\n";
		system("pause");
		return 0;
	}
	cout << "\nThe list of Students\n";
	DisplayArray(students, n);
	char genderTag[M];
	cout << "\nEnter the gender (m/M if man, w/W if woman) ";
	cin >> genderTag;
	int lowScore, upperScore;
	cout << "\nEnter the low boundary of passing score ";
	cin >> lowScore;
	cout << "\nEnter the upper boundary of passing score ";
	cin >> upperScore;
	cout << "\n\nThe list of choise-Students:\n";
	DisplayChoise(students, n, genderTag, lowScore, upperScore);
	cout << "\n\nThe sorting list of Students: \n";
	SortFirstName(students, n);
	DisplayArray(students, n);
	delete[] students;
	system("pause");
	return 0;
}

Student InitStudent()
{
	char firstName[N] = "", secondName[N] = "", middleName[N] = "", gender[N] = "", nationality[N] = "";
	cout << "Enter First name ";
	cin.ignore();
	cin.get(firstName, N, '\n');
	cout << "Enter Second name ";
	cin.ignore();
	cin.get(secondName, N, '\n');
	cout << "Enter Middle name ";
	cin.ignore();
	cin.get(middleName, N, '\n');
	cout << "\nEnter gender (m/M if man, w/W if woman) ";
	cin.ignore();
	cin.get(gender, N, '\n');
	cout << "Enter nationality ";
	cin.ignore();
	cin.get(nationality, N, '\n');

	int yearB, monthB, dayB, score;
	cout << "\nEnter the year of birth ";
	cin >> yearB;
	cout << "Enter the month of birth ";
	cin >> monthB;
	cout << "Enter the day of birth ";
	cin >> dayB;
	cout << "\nEnter the passing score ";
	cin >> score;

	int k;
	cout << "\n\nEnter the number of exams ";
	cin >> k;

	int A[M];
	cout << "Enter the array of marks\n";
	EnterArray(A, k);
	Student man;
	man.SetStudent(firstName, secondName, middleName, gender, nationality, yearB, monthB, dayB, score, A);
	return man;
}

Student* InitArray(int n)
{
	Student* array = new Student[n];
	if (!array)
		return NULL;
	for (int i = 0; i < n; i++)
	{
		cout << "\nEnter the information about " << (i + 1) << " student\n";
		array[i] = InitStudent();
	}
	return array;
}

void EnterArray(int* array, int& k)
{
	for (int i = 0; i < k; i++)
	{
		cout << "enter A[" << (i + 1) << "] = ";
		cin >> array[i];
	}
}

void DisplayArray(Student* array, int n)
{
	for (int i = 0; i < n; i++)
		array[i].DisplayStudent();
	cout << endl;
}

void DisplayChoise(Student* array, int Dimension, char* genderTag, double lowScore, double upperScore)
{
	for (int i = 0; i < Dimension; i++)
		if (!strcmp(array[i].GetGender(), genderTag) && array[i].GetPassingScore() 
			<= upperScore  &&  array[i].GetPassingScore() >= lowScore)
			array[i].DisplayStudent();
}

void SortFirstName(Student* array, int n)
{
	for (int i = 0; i <= n; i++)
		for (int j = n - 1; j > i; j--)
			if (strcmp(array[j].GetFirstName(), array[j - 1].GetFirstName()) < 0)
				Swap(array[j], array[j - 1]);
}

void Swap(Student &a, Student &b)
{
	Student help = a;
	a = b;
	b = help;
}
