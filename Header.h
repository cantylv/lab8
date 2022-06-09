#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <fstream>
#include <map>

//#define FIRST_TASK
//#define SECOND_TASK
//#define THIRD_TASK
//#define FOURTH_TASK
//#define FIFTH_TASK
//#define SIXTH_TASK
//#define SEVENTH_TASK
//#define EIGHTH_TASK
#define NINTH_TASK


using digits_in_line = int;
using is_it_punct = bool;

class Box;
digits_in_line FindSymbols(const std::string& line, std::ofstream& fout_small, std::ofstream& fout_big);
is_it_punct IsPunct(const char& symb);
void PrintVector1(const std::vector<double>& dvec);
void PrintVector2(const std::vector<Box>& vec);
void PrintInfo(const std::map<std::string, int> empls);



class Box {
	double a;	// ширина 
	double b;	// высота
	double c;	// длина
	double volume;
public:
	Box() : a(0), b(0), c(0), volume(0) {}
	Box(double a, double b, double c) : a(a), b(b), c(c), volume(a*b*c) {}
	friend bool operator >(const Box& obj1, const Box& obj2);
	friend bool operator ==(const Box& obj1, const Box& obj2);
	friend std::ostream& operator << (std::ostream& out,const Box& obj);
	double GetVolume();
};

class Graduate {
	std::string name;   // фамилия
	double rating; // рейтинг
public:
	Graduate() {
		name = "";
		rating = 0;
	}
	Graduate(std::string Name, double Rating) {
		name = Name;
		rating = Rating;
	}
	bool operator >(const Graduate& group);
	bool operator ==(const Graduate& group);
	friend std::ostream& operator <<(std::ostream& out, const Graduate& group);
	friend Graduate& Best(std::vector<Graduate>& group);
	void PlusRating(double num)
	{
		rating += num;
	}
	friend void PrintGroup(const std::vector<Graduate>& group);

};
