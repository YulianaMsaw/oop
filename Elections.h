#pragma once
#include <iostream>
#include <sstream>
/*
 14. Класс  «Выборы(Elections)»  с  полями:  ФИО  канди-дата,дата рождения, место работы, рейтинг предварительных опросов;
Вывести  сведения  о  кандидатах,  рейтинг  которых превышает вводимое число. идентификациягегератор мапы

*/
class Elections {
public:
	Elections(std::string name,std::string date, std::string place, int raring);
	std::string GetName() const;
	std::string GetDate() const;
	std::string GetPlaceJob() const;
	int GetRating() const;
	int GetId() const;
	std::string ToString() const;
private:
	std::string _name;
	std::string _date;
	std::string _placeJob;
	int _rating;
	int _id;
};

static int count = 0;