#include "Header.h"

digits_in_line FindSymbols(const std::string& line, std::ofstream& fout_small, std::ofstream& fout_big)
{
	int num = 0;
	for (size_t i = 0; i < line.size(); i++)
	{
		if (line[i] >= 48 && line[i] <= 57)
			num++;
		if ((line[i] >= 97 && line[i] <= 122) || (line[i] >= -32 && line[i] <= -1))     // ASCII коды латинского и русского алфавитов букв нижнего регистра
			fout_small.put(line[i]);
		if ((line[i] >= 65 && line[i] <= 90) || (line[i] >= -64 && line[i] <= -33))     // ASCII коды латинского и русского алфавитов букв верхнего регистра
			fout_big.put(line[i]);
	}
	return num;
}

is_it_punct IsPunct(const char& symb)
{
	return symb == ' ' || symb == '.' || symb == '(' || symb == ')' ? true : false;
}


void PrintVector1(const std::vector<double>& dvec)
{
	for (size_t i = 0; i < dvec.size(); i++)
		std::cout << dvec[i] << '\t';
	std::cout << std::endl << std::endl;
}

void PrintVector2(const std::vector<Box>& vec)
{
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i];
}

bool operator >(const Box& obj1, const Box& obj2)
{
	return obj1.a > obj2.a && obj1.b > obj2.b && obj1.c > obj2.c ? true : false;
}

bool operator==(const Box& obj1, const Box& obj2)
{
	return obj1.a == obj2.a && obj1.b == obj2.b && obj1.c == obj1.b ? true : false;
}

std::ostream& operator <<(std::ostream& out, const Box& obj)
{
	return out << obj.a << "  " << obj.b << "  " << obj.c << "  \n";
}

double Box::GetVolume()
{
	return volume;
}


bool Graduate::operator>(const Graduate& student)
{
	return this->rating > student.rating ? true : false;
}

bool Graduate::operator ==(const Graduate& student)
{
	return this->rating == student.rating ? true : false;
}

std::ostream& operator <<(std::ostream& out, const Graduate& group)
{
	return out << "Фамилия\t " << group.name << "\nРейтинг: " << group.rating << '\n';
}

Graduate& Best(std::vector<Graduate>& group)
{
	int maxi = 0;
	for (size_t i = 1; i < group.size(); i++)
	{
		if (group[maxi].rating < group[i].rating)
			maxi = i;
	}
	return group[maxi];
}

void PrintGroup(const std::vector<Graduate>& group)
{
	for (auto el : group)
		std::cout << el << "\n\n";
}

void PrintInfo(const std::map<std::string, int> empls)
{
	for (auto iter = empls.begin();iter != empls.end();++iter)
		std::cout << "Имя:  " << (*iter).first << "\tКол-во изготовленных деталей:  " << (*iter).second << '\n';
}