#ifndef PASSENGERDATABASE_H
#define PASSENGERDATABASE_H

#include "DataCollectorCallback.h"
#include "Passenger.h"
#include <vector>
#include <map>

namespace cs32 {
	class PassengerDatabase : public DataCollectorCallback {
		public:
			// isLoaded is false as default with an empty passengers vector.
			PassengerDatabase();
			// free any allocated passenger objects when destructed.
			~PassengerDatabase();

			// reads passenger data from a CSV file located at the specific path.
			int load(std::string filePath);
			// delete all allocated passengers and set isLoaded as false.
			void clearAllPassengers();
			// return the member variable, isLoaded.
			bool loaded();

			// return a passenger found by name
			Passenger* getPassenger_byName(std::string name);
			// return passengers vector.
			std::vector<Passenger*> getPassengers();
			// filter passengers by class and return all passengers that match the criteria.
			std::vector<Passenger*> getPassengers_byClass(Class paidClass, bool survived, double minimumFare);
			// filter passengers by embaracation, and return all passengers that match the criteria.
			std::vector<Passenger*> getPassengers_byEmbarcation(Embarcation embarked, bool survived, double minimumFare);

			// Parse and store passenger data from CSV rows
			virtual void csvData(std::map<std::string, std::string> row);

		private:
			std::vector<Passenger*> passengers;
			bool isLoaded;
		};

}

#endif
