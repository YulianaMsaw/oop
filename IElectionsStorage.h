#pragma once
#include "Elections.h"
class IElectiosStorage {
public:
	virtual void AddElection(Elections *person )=0;
};