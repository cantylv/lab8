// Lab8, made by Lobanov Ivan, IU5-23B, variant №9
#include "Header.h"

int main()
{
	system("chcp 1251");

#ifdef FIRST_TASK
	// TASK1
	/*9. Пользователь вводит текст.Определить в каких позициях в тексте начинается каждое новое слово(сначала найти позиции пробелов).*/
	int arr_size = 0;
	std::string str;
	std::list<int> pos;
	std::list<int> ind_words;
	std::list<int>::iterator iter;

	std::getline(std::cin, str);
	for (size_t i = 0; i < str.size(); i++)
		if (IsPunct(str[i]))
			pos.push_back(i);

	if (pos.size())
	{
		if (pos.front() != 0)
			ind_words.push_back(0);
		for (iter = pos.begin(); iter != --pos.end();iter++)
		{
			if ((*iter) + 1 != *(++iter))
				ind_words.push_back((*(--iter) + 1));
			else --iter;
		}
		if (str[*iter] != str[str.size()-1])
			ind_words.push_back(*iter+1);
	}
	else ind_words.push_back(0);
	std::cout << "Индексы начала слов в тексте:\n";
	for (iter = ind_words.begin(); iter != ind_words.end();iter++)
		std::cout << *iter << '\t';
	std::cout << std::endl;


#endif FIRST_TASK

#ifdef SECOND_TASK

	//TASK 2
	//9.Пользователь вводит некоторый текст. Переписать в другую переменную только все символы за исключением цифр.
	std::string text;
	std::string new_text = "";
	std::getline(std::cin, text);
	for (size_t i = 0; i < text[i]; i++)
	{
		if (text[i] < 48 || text[i]>57)         // [48;57] - ASCII коды цифр
			new_text += text[i];
	}
	std::cout << "Новый текст:\n";
	std::cout << new_text << std::endl;

#endif SECOND_TASK

#ifdef THIRD_TASK
	// TASK 3
	//9. Дан текстовый файл. Запишите в один файл из исходного файла только большие латинские буквы, в другой новый файл - только малые латинские буквы и посчитайте количество цифр в исходном файле. 
	int num_of_digits = 0;
	std::ifstream fin("TASK3.txt");
	std::ofstream fout_small("TASK3_smallSymbols.txt");
	std::ofstream fout_big("TASK3_bigSymbols.txt");
	std::string line;
	while (std::getline(fin, line))
		num_of_digits += FindSymbols(line, fout_small, fout_big);
	fout_small.close();
	fout_big.close();
	fin.close();
	std::ifstream  fout_small_in("TASK3_smallSymbols.txt");
	std::ifstream fout_big_in("TASK3_bigSymbols.txt");
	std::cout << "Количество цифр в исходном тексте:\t" << num_of_digits << std::endl;
	std::cout << "Содержимое файла TASK3_smallSymbols.txt\n";
	while (std::getline(fout_small_in, line))
		std::cout << line << std::endl;
	std::cout << "Содержимое файла TASK3_bigSymbols.txt\n";
	while (std::getline(fout_big_in, line))
		std::cout << line << std::endl;
	fout_small_in.close();
	fout_big_in.close();

#endif THIRD_TASK

#ifdef FOURTH_TASK
	// TASK 4
	// 9. Создать вектор из 10-ти вещественных случайных чисел (-50 до 50). Распечатать. Посчитать среднее число вектора. 
	// Из первого вектора создать второй вектор, который содержит только те элементы первого вектора, которые больше среднего первого массива.
	// Удалить из первого вектора элемент с индексом 8 и снова распечатать вектор. Переделать программу: печатать векторы с помощью функции.

	double mean = 0;
	std::vector<double> new_dvec;
	std::vector<double> dvec{ -34, 28, 0, -7, -28, 16, 20, 9 , 27, 49 };
	std::vector<double>::iterator iter = dvec.begin();
	std::cout << "Исходный вектор:\n";
	for (size_t i = 0; i < dvec.size(); i++)
		std::cout << dvec[i] << '\t';
	std::cout << std::endl;
	for (size_t i = 0; i < dvec.size(); i++)
		mean += dvec[i];
	mean /= dvec.size();
	std::cout << "\nСреднее арифметическое элементов вектора = " << mean << std::endl << std::endl;
	for (size_t i = 0; i < dvec.size(); i++)
	{
		if (dvec[i] > mean)
			new_dvec.push_back(dvec[i]);
	}
	iter += 8;
	dvec.erase(iter);
	PrintVector1(dvec);
#endif FOURTH_TASK

#ifdef FIFTH_TASK
	//TASK 5
	int maxi = 0;
	std::vector<Box> vec{ {1, 2, 63}, {14, 57, 19}, {7, 32, 20}, {5, 13, 23}, {10, 19, 45}, {19, 9, 59} };
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i];
	for (size_t i = 1; i < vec.size(); i++)
		if (vec[i].GetVolume() > vec[maxi].GetVolume())
			maxi = i;
	std::cout << "Максимальный объем равен = " << vec[maxi].GetVolume() << std::endl;
	PrintVector2(vec);
#endif FITHH_TASK

#ifdef SIXTH_TASK
	//TASK 6
	//9. Создать вектор из 10 - ти вещественных случайных чисел(-50 до 50).Распечатать.Посчитать среднее число вектора.
	//Из первого вектора создать второй вектор, который содержит только те элементы первого вектора, которые больше среднего первого массива.
	//Удалить из первого вектора элемент с индексом 8 и снова распечатать вектор.Переделать программу : печатать векторы с помощью функции.



	// ТОЖЕ САМОЕ, ЧТО И ЗАДАНИЕ 4
#endif SIXTH_TASK

#ifdef SEVENTH_TASK
	//TASK 7
	double num = 0;
	std::vector<Graduate> group{ {"Иванов",99}, {"Петров",430}, {"Семенов",70}, {"Котов",540}, {"Белых",230}, {"Черных",350} };
	for (size_t i = 0;i < group.size();++i)
		std::cout << group[i] << "\n\n";
	std::cout << "Лучший рейтинг будет у этого человека:\n\n";
	std::cout << Best(group);
	std::cout << "\nВведите число, на которое хотите увеличить рейтинг каждого человека:\t";
	std::cin >> num;
	for (size_t i = 0; i < group.size(); i++)
		group[i].PlusRating(num);
	PrintGroup(group);
#endif SEVENTH_TASK

#ifdef EIGHTH_TASK
	std::map<std::string, std::string>::iterator iter;
	std::map<std::string, std::string> geo;
	std::string country;
	std::string capital;
	geo["Russia"] = "Moscow";
	geo["Finland"] = "Helsinki";
	geo["France"] = "Paris";
	geo["Great Britian"] = "London";
	geo["Germany"] = "Berlin";
	std::cout << "Введите название страны:\n";
	std::getline(std::cin, country);
	iter = geo.find(country);
	if (iter != geo.end())
		std::cout <<"Сapital of "<<country<<" is "<< (*iter).second << '\n';
	else
	{
		std::cout << "Enter the capital of your country:\n";
		std::getline(std::cin, capital);
		geo[country] = capital;
	}
	for (auto iter = geo.begin();iter != geo.end();++iter)
		std::cout << "Country:  " << (*iter).first << "\tCapital:  " << (*iter).second << '\n';
#endif EIGHTH_TASK

#ifdef NINTH_TASK
	std::map<std::string, int> empls; // employees
	int count_det = 0; // count of details

	empls["Иванов"] = 123;
	empls["Петров"] = 89;
	empls["Сидоров"] = 108;
	empls["Краснов"] = 132;
	empls["Демин"] = 99;
	empls["Черепанов"] = 111;

	for (auto iter = empls.begin();iter != empls.end();++iter)
		count_det += (*iter).second;

	std::cout << "За неделю было изготовлено " << count_det << " детали!\n";
	PrintInfo(empls);

#endif NINTH_TASK
	return 0;
}