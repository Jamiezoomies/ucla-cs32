#include "PassengerDatabase.h"
#include "CSVFile.h"

namespace cs32 {

	// isLoaded is false as default with an empty passengers vector.
	PassengerDatabase::PassengerDatabase() {
		isLoaded = false;
	}

	// free any allocated passenger objects when destructed.
	PassengerDatabase::~PassengerDatabase() {
		clearAllPassengers();
	}

	// reads passenger data from a CSV file located at the specific path.
	int PassengerDatabase::load(std::string filePath) {
		CSVFile file(this);
		int recordCount = file.readFile(filePath);
		if (passengers.size() > 0) {
			isLoaded = true;
		}
		return(recordCount);
	}

	// delete all allocated passengers and set isLoaded as false.
	void PassengerDatabase::clearAllPassengers() {
		// delete all passengers using the iterator.
		for (std::vector<Passenger*>::iterator it = passengers.begin(); it != passengers.end(); ++it) {
			delete (*it);
		}

		// reassure that all elements in the passenger vector have been cleared.
		passengers.clear();

		// set isLoaded as false
		isLoaded = false;
	}

	// return the member variable, isLoaded.
	bool PassengerDatabase::loaded() {
		return isLoaded;
	}

	// return a passenger found by name
	Passenger* PassengerDatabase::getPassenger_byName(std::string name) {
		// if the passenger's name matches the specified name, return the passenger as a result.
		for (std::vector<Passenger*>::iterator it = passengers.begin(); it != passengers.end(); ++it) {
			if ((*it)->getName() == name) {
				return (*it);
			}
		}

		// if not found, return nullptr.
		return nullptr;
	}

	// return passengers vector.
	std::vector<Passenger*> PassengerDatabase::getPassengers() {
		return passengers;
	}

	// filter passengers by class and return all passengers that match the criteria.
	std::vector<Passenger*> PassengerDatabase::getPassengers_byClass(Class paidClass, bool survived, double minimumFare) {
		std::vector<Passenger*> result;
		// if all arguments match, push the passenger to the result vector.
		for (std::vector<Passenger*>::iterator it = passengers.begin(); it != passengers.end(); ++it) {
			if ((*it)->getClass() == paidClass && (*it)->getSurvived() == survived && (*it) && (*it)->getFare() >= minimumFare) {
				result.push_back(*it);
			}
		}

		return result;
	}

	// filter passengers by embaracation, and return all passengers that match the criteria.
	std::vector<Passenger*> PassengerDatabase::getPassengers_byEmbarcation(Embarcation embarked, bool survived, double minimumFare) {
		std::vector<Passenger*> result;
		// if all arguments match, push the passenger to the result vector.
		for (std::vector<Passenger*>::iterator it = passengers.begin(); it != passengers.end(); ++it) {
			if ((*it)->getEmbarcation() == embarked && (*it)->getSurvived() == survived && (*it)->getFare() >= minimumFare) {
				result.push_back(*it);
			}
		}
		return result;
	}

	// Parse and store passenger data from CSV rows
	void PassengerDatabase::csvData(std::map<std::string, std::string> row) {
		// create a new Passenger object to store the parsed data.
		Passenger* newPassenger = new Passenger();
		// iterate through the map and set member variables based on the column names.
		for (std::map<std::string, std::string>::iterator it = row.begin(); it != row.end(); ++it) {
			if (it->first == "pclass") {
				newPassenger->setClass(it->second);
			}
			else if (it->first == "survived") {
				newPassenger->setSurvived(it->second);
			}
			else if (it->first == "embarked") {
				newPassenger->setEmbarcation(it->second);
			} 
			else if (it->first == "fare") {
				newPassenger->setFare(it->second);
			}
			else if (it->first == "name") {
				newPassenger->setName(it->second);
			}
		}
		passengers.push_back(newPassenger);
	}



}