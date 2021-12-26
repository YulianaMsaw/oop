#pragma once
#include <iostream>
#include <sstream>
/*
 14. �����  �������(Elections)�  �  ������:  ���  �����-����,���� ��������, ����� ������, ������� ��������������� �������;
�������  ��������  �  ����������,  �������  ������� ��������� �������� �����. ���������������������� ����

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