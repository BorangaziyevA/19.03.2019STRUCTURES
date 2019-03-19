#include<iostream>
#include<iomanip>
#include<iostream>
#include<fstream>

int buf_size = 0;
int current_size = 0;

using namespace std;

struct Date
{
	int day;

	int month;

	int year;

	void print()
	{
		cout << day << "." << month << "." << year << " ";
	}

};

struct Man
{
	char surname[20];

	char name[20];

	Date date;

	void print()
	{
		cout << name << " " << surname << " " ;
		date.print();
		cout << endl;
	}

};

void MS(Man *&ms,const char* name)
{
	for (size_t i = 0; i < current_size; i++)
	{
		if (strcmp(ms[i].name, name))
		{
			for (size_t j = i; j < current_size -1; j++)
			{
				ms[j] = ms[j + 1];
				i--;
			}
			current_size--;
		}

	}
}

void erase_last(Man *&ms)
{
	current_size--;
	if (current_size == 0)
	{
		delete[] ms;
		buf_size = 0;
	}
}

void add(Man *&ms, Man el)
{
	if (buf_size == 0)
	{
		buf_size = 4;
		ms = new Man[buf_size];
	}
	else
	{
		if (buf_size == current_size)
		{
			buf_size *= 2;

			Man* tmp = new Man[buf_size];

			for (size_t i = 0; i < current_size; i++)
			{
				tmp[i] = ms[i];
			}
			delete[] ms;
			ms = tmp;
		}

	}
	ms[current_size++] = el;
}

struct Mark
{
	char subject[30];

	int grade;
	
	void print()
	{
		cout << subject << " " << grade << " ";
	}

};

struct Student
{
	char name[30];

	char surname[30];

	int age;

	Mark grades[5];

	int fot;

	float sum;

	void sum1()
	{
		sum = 0;
		for (size_t i = 0; i < 5; i++)
		{
			sum = sum + grades[i].grade;
		}
		sum = sum / 5;
		if (sum >= 4)
		{
			fot = 1;
		}
		else
			fot = 0;
	}

	void print()
	{
		sum = 0;
		cout << name << " " << surname << " " << age << endl;
		for (size_t i = 0; i < 5; i++)
		{
			grades[i].print();

		}
		cout << endl;
	}

};

struct Bilet
{
	char marshrut[30];

	char time[10];

	char date[20];

	int money;

	void print()
	{
		cout << marshrut << " " << time << " " << date << " " << money << endl;
	}


};

int main()
{
	ifstream in_file("in.txt");
	Man* ms = 0;
	Man tmp_man;
	char c;

	while (!in_file.eof())
	{
		in_file >> tmp_man.name >> tmp_man.surname >> tmp_man.date.day >> c >> tmp_man.date.month >> c >> tmp_man.date.year;
		add(ms, tmp_man);
	}

	erase_last(ms);
	for (size_t i = 0; i < current_size; i++)
	{
		ms[i].print();
	}
	

	system("pause");
	return 0;
}





////////////////1/////////1////////////1/////////1
//using namespace std;
//
//struct Student
//{
//	char name[30];
//
//	char surname[30];
//
//	int age;
//
//	int grades[5];
//
//	int fot;
//
//	float sum;
//
//	void sum1()
//	{
//		sum = 0;
//		for (size_t i = 0; i < 5; i++)
//		{
//			sum = sum + grades[i];
//		}
//		sum = sum / 5;
//		if (sum >= 4)
//		{
//			fot = 1;
//		}
//		else
//			fot = 0;
//	}
//
//	void print()
//	{
//		sum = 0;
//		cout << name << " " << surname << " " << age << endl;
//		for (size_t i = 0; i < 5; i++)
//		{
//			cout << grades[i] << " ";
//
//		}
//		cout << endl;
//	}
//
//};
//
//int main()
//{
//	ifstream in_file("in.txt");
//	int n;
//
//	if (!in_file)
//	{
//		cout << "File open error" << endl;
//	}
//	else {
//		in_file >> n;
//
//		Student *ss;
//		ss = new Student[n];
//
//		for (size_t i = 0; i < n; i++)
//		{
//			in_file >> ss[i].name >> ss[i].surname >> ss[i].age;
//			for (size_t j = 0; j < 5; j++)
//			{
//				in_file >> ss[i].grades[j];
//			}
//
//		}
//
//		for (size_t i = 0; i < n; i++)
//		{
//			ss[i].print();
//		}
//
//		cout << "Otlichniki:" << endl;
//		for (size_t i = 0; i < n; i++)
//		{
//			ss[i].sum1();
//
//			if (ss[i].fot == 1)
//			{
//				cout << ss[i].name << " " << ss[i].surname << endl;
//			}
//		}
//		cout << "Dvoichniki:" << endl;
//		for (size_t i = 0; i < n; i++)
//		{
//			ss[i].sum1();
//
//			if (ss[i].fot == 0)
//			{
//				cout << ss[i].name << " " << ss[i].surname << endl;
//			}
//		}
//
//	}
//
//	system("pause");
//	return 0;
//}