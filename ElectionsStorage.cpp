#include "ElectionsStorage.h"

void ElectionsStorage::AddElection(Elections* person)
{
	if (_storageID.find(person->GetId()) != _storageID.end()) {
		throw std::exception("Чел обнаружен");
	}
	_storageID.insert(std::make_pair(person->GetId(), person));

	_storageRaiting[person->GetRating()].insert(person->GetId());
	_storageName[person->GetName()].insert(person->GetId());
}

void ElectionsStorage::Remove(int id)
{
	if (_storageID.find(id) == _storageID.end()) {
		throw std::exception("Чела нет. Не надо его удалять");
	}
	auto personRaiting = _storageID.find(id);
	
	_storageRaiting[personRaiting->second->GetRating()].erase(personRaiting->second->GetId());
	_storageName[personRaiting->second->GetName()].erase(personRaiting->second->GetId());
	_storageID.erase(id);

}

std::vector<int> ElectionsStorage::SearchByRating(int raiting)
{
	auto itRaiting = _storageRaiting.upper_bound(raiting);
	std::vector <int> CoolChel;
	for (; itRaiting != _storageRaiting.end(); itRaiting++) {
		for (auto it : itRaiting->second) {
			CoolChel.push_back(it);
	}
	}
	return CoolChel;
}

std::vector<int> ElectionsStorage::SearchByName(std::string name)
{
	auto Candidate = _storageName.find(name);
	std::vector <int> SearchName;
	for (auto it : Candidate->second) {
		SearchName.push_back(it);
	}
	return SearchName;
}


Elections* ElectionsStorage::GetCandidate(int id)
{
	auto Candidate = _storageID.find(id);
	if (Candidate != _storageID.end())
	{
		return Candidate->second;
	}
	throw std::exception("Нет такого кандидата");
}

