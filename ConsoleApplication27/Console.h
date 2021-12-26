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
		// ��������� ������ ������ � ������������ � ��������.
		_menuItems.push_back({ "Exit.", std::bind(&ConsoleUserInterface::ExitDialog, this) });

		// ����� ���� ������ ��� �������, ��������� � �������� ������� ����� ��������.
		_menuItems.push_back({ "Some dialog.", std::bind(&ConsoleUserInterface::SomeDialog, this) });
		_menuItems.push_back({ "Add Elections.", std::bind(&ConsoleUserInterface::AddElections, this) });
		_menuItems.push_back({ "ReadFile.", std::bind(&ConsoleUserInterface::ReadFile, this) });
		_menuItems.push_back({ "PrintInformatin.", std::bind(&ConsoleUserInterface::PrintInformatin, this) });
		_menuItems.push_back({ "SearchBeRating.", std::bind(&ConsoleUserInterface::SearchBeRating, this) });
		_menuItems.push_back({ "SearchByName.", std::bind(&ConsoleUserInterface::SearchByName, this) });

		// ���� ������ ���� ��������� �� ��������.
	}

	void Run()
	{
		// �������� ���� �������������� � �������������.
		// ������������, ��� ��� ����������� ������.

		while (true)
		{
			try
			{
				ShowMenuItems();

				int action = 0;
				std::cin >> action;

				if (!_menuItems.at(action).Dialog())
				{
					// ������ ������ false - �� ����������.
					break;
				}
			}
			catch (const std::exception& ex)
			{
				std::cout << ex.what() << std::endl;
				// ���������� �������� � ���������� ������.
			}
		}
	}

private:

	void ShowMenuItems()
	{
		// ������� ������ ������ �� 1-�, �.�. 0-� Exit ����� �������� ��������� ��������.
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

	bool SomeDialog()// ����� ������ ��� ��� �� ������. 
	{
		std::cout << "Input something: " << std::endl;

		int something = 0;
		std::cin >> something;

		// �� ���� ����� ������� ���� ����� ���������� true, 
		// ���� ������ ��������� �� ������������� ���������� ������ ������-�� ����� Exit.
		return true;
	}

	bool AddElections()
	{
		std::string name;
		std::string date;
		std::string placeJob;
		int rating;
		std::cout << "����� ��� "<<std::endl;
		std::cin >> name ;
		std::cout << "����� ���� " << std::endl;
		std::cin >> date;
		std::cout << "����� ����� " << std::endl;
		std::cin >> placeJob;
		std::cout << "����� ������� " << std::endl;
		std::cin >> rating;

		_repository.AddElection(new Elections(name, date, placeJob, rating));

		return true;
	}

	bool ReadFile()
	{
		std::ifstream inputFile;
		std::cout << "����� ��� �����" << std::endl;
		std::string name;
		std::cin >> name;
		inputFile.open(name);
		if (!inputFile.is_open()) {
			throw std::exception("���� �� ���������");
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
		std::cout << "������ ���� ������� ���?";
		int chel;
		std::cin >> chel;
		auto it = _repository.GetCandidate(chel);
		std::cout<< it->ToString();
		return true;
	}
	bool SearchBeRating() {
		std::cout << "������� �������";
		int raiting;
		std::cin >> raiting;
		auto it = _repository.SearchByRating(raiting);
		for (auto itRait : it) {
			
			std::cout << _repository.GetCandidate(itRait)->ToString()<<std::endl;

		}
		return true;
	}
	bool SearchByName() {
		std::cout << "������� ���";
		std::string name;
		std::cin >> name;
		auto it = _repository.SearchByName(name);
		for (auto itRait : it) {

			std::cout << _repository.GetCandidate(itRait)->ToString() << std::endl;

		}
		return true;
	}
	// ��������� ��� �������� ������ ����
	struct MenuItem
	{
		// ��������� ��� ������ ������ ����
		std::string Message;

		// ������� � ��������. ���� ���������� true - ����������, ���� false - ��������� ������.
		std::function<bool(void)> Dialog;
	};

	// ������ ������� ����.
	std::vector<MenuItem> _menuItems;

	ElectionsStorage _repository;
	
};

