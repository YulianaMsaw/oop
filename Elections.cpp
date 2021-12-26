#include "Elections.h"

Elections::Elections(std::string name, std::string date, std::string place, int raring):_name(name), _date(date), _placeJob(place), _rating(raring){
	count++;
	_id = count;

}

std::string Elections::GetName() const
{
	return _name;
}

std::string Elections::GetDate() const
{
	return _date;
}

std::string Elections::GetPlaceJob() const
{
	return _placeJob;
}

int Elections::GetRating() const
{
	return _rating;
}

int Elections::GetId() const
{
	return _id;
}

std::string Elections::ToString() const
{
	std::ostringstream sout;
	sout << "name=" << _name << std::endl;
	sout << "date=" << _date << std::endl;
	sout << "place=" << _placeJob << std::endl;
	sout << "rating=" << _rating << std::endl;
	return sout.str();
}
