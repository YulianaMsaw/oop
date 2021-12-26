#pragma once
#pragma once

#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include "ElectionsStorage.h"
#include <fstream>
#include <algorithm>
class ConsoleUserInterface
{
public:

	ConsoleUserInterface()
	{
		// Расширьте список команд в соответствии с заданием.
		_menuItems.push_back({ "Exit.", std::bind(&ConsoleUserInterface::ExitDialog, this) });

		// Пункт меню сделан для примера, сообщение и название функции нужно изменить.
		_menuItems.push_back({ "Some dialog.", std::bind(&ConsoleUserInterface::SomeDialog, this) });
		_menuItems.push_back({ "Add Elections.", std::bind(&ConsoleUserInterface::AddElections, this) });
		_menuItems.push_back({ "ReadFile.", std::bind(&ConsoleUserInterface::ReadFile, this) });
		_menuItems.push_back({ "PrintInformatin.", std::bind(&ConsoleUserInterface::PrintInformatin, this) });
		_menuItems.push_back({ "SearchBeRating.", std::bind(&ConsoleUserInterface::SearchBeRating, this) });
		_menuItems.push_back({ "SearchByName.", std::bind(&ConsoleUserInterface::SearchByName, this) });

		// Свои пункты меню добавлять по аналогии.
	}

	void Run()
	{
		// Основной цикл взаимодействия с пользователем.
		// Маловероятно, что его понадобится менять.

		while (true)
		{
			try
			{
				ShowMenuItems();

				int action = 0;
				std::cin >> action;

				if (!_menuItems.at(action).Dialog())
				{
					// Диалог вернул false - не продолжаем.
					break;
				}
			}
			catch (const std::exception& ex)
			{
				std::cout << ex.what() << std::endl;
				// Исключения логируем и продолжаем работу.
			}
		}
	}

private:

	void ShowMenuItems()
	{
		// Выводим список команд от 1-й, т.к. 0-й Exit будем выводить последним отдельно.
		for (auto i = 1U; i < _menuItems.size(); ++i)
		{
			std::cout << i << "." << _menuItems[i].Message << std::endl;
		}
		std::cout << 0 << "." << _menuItems[0].Message << std::endl;
	}

	bool ExitDialog()
	{
		std::cout << "Good buy!";
		return false;
	}

	bool SomeDialog()// Игорь сказал что она не нужная. 
	{
		std::cout << "Input something: " << std::endl;

		int something = 0;
		std::cin >> something;

		// Во всех своих пунктах меню нужно возвращать true, 
		// если логика программы не подразумевает завершения работы откуда-то кроме Exit.
		return true;
	}

	bool AddElections()
	{
		std::string name;
		std::string date;
		std::string placeJob;
		int rating;
		std::cout << "Введи имя "<<std::endl;
		std::cin >> name ;
		std::cout << "Введи дату " << std::endl;
		std::cin >> date;
		std::cout << "Введи место " << std::endl;
		std::cin >> placeJob;
		std::cout << "Введи рейтинг " << std::endl;
		std::cin >> rating;

		_repository.AddElection(new Elections(name, date, placeJob, rating));

		return true;
	}

	bool ReadFile()
	{
		std::ifstream inputFile;
		std::cout << "Введи имя файла" << std::endl;
		std::string name;
		std::cin >> name;
		inputFile.open(name);
		if (!inputFile.is_open()) {
			throw std::exception("Файл не обнаружен");
		}
		int count;
		inputFile >> count;
		for (int i = 0; i < count; i++) {

			std::string name;
			std::string date;
			std::string placeJob;
			int rating;
			inputFile>>name;
			inputFile >> date;
			inputFile >> placeJob;

			inputFile>>rating;
			char c;
	
			
			_repository.AddElection(new Elections(name, date, placeJob, rating));

		}
	}

	bool PrintInformatin()
	{
		std::cout << "Какого типа вывести вам?";
		int chel;
		std::cin >> chel;
		auto it = _repository.GetCandidate(chel);
		std::cout<< it->ToString();
		return true;
	}
	bool SearchBeRating() {
		std::cout << "Введите рейтинг";
		int raiting;
		std::cin >> raiting;
		auto it = _repository.SearchByRating(raiting);
		for (auto itRait : it) {
			
			std::cout << _repository.GetCandidate(itRait)->ToString()<<std::endl;

		}
		return true;
	}
	bool SearchByName() {
		std::cout << "Введите имя";
		std::string name;
		std::cin >> name;
		auto it = _repository.SearchByName(name);
		for (auto itRait : it) {

			std::cout << _repository.GetCandidate(itRait)->ToString() << std::endl;

		}
		return true;
	}
	// Структура для хранения пункта меню
	struct MenuItem
	{
		// Сообщение для выбора пункта меню
		std::string Message;

		// Функция с диалогом. Если возвращает true - продолжаем, если false - завершаем работу.
		std::function<bool(void)> Dialog;
	};

	// Список пунктов меню.
	std::vector<MenuItem> _menuItems;

	ElectionsStorage _repository;
	
};

