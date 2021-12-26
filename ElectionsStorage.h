#pragma once
#include <set>
#include "IElectionsStorage.h"
#include <map>
#include <vector>

class ElectionsStorage: public IElectiosStorage {
public:
	void AddElection(Elections* person) override;
	void Remove(int id);
	std::vector <int> SearchByRating(int raiting);
	std::vector <int> SearchByName(std::string name);
	Elections* GetCandidate(int id);
private:
	std::map <int, Elections*> _storageID;
	std::map <int, std::set<int>> _storageRaiting;
	std::map <std::string, std::set<int>> _storageName;
};