#include "PassengerOutputTable.h"
#include "OutputTableRow.h"
#include <iostream>
#include <map>

namespace cs32 {

	// Constructor for PassengerOutputTable
	PassengerOutputTable::PassengerOutputTable(std::vector<Passenger*> passengers) {
		// set mPassengerList with the provided vector.
		mPassengerList = passengers;
		mField = Field::NOVALUE;
		mDescription = "";
	}

	// Field setter.
	void PassengerOutputTable::setOutputField(Field f) {
		mField = f;
	}

	// Description setter
	void PassengerOutputTable::setDescription(std::string description) {
		mDescription = description;
	}

	// Field getter
	Field PassengerOutputTable::getOutputField() {
		return mField;
	}

	// Description getter
	std::string PassengerOutputTable::getDescription() {
		return mDescription;
	}

	// display output table rows
	void PassengerOutputTable::display() {
		// if Field is NoValue, display nothing.
		if (getOutputField() == Field::NOVALUE) {
			return;
		}

		// display the description of the passenger output table.
		std::cout << mDescription << std::endl;
		std::cout << "                  " << "Survived /  Total" << "        " << "%" << std::endl;
		
		std::map<std::string, int> totalMap, survivedMap;

		// Add descriptions to the list based on Field.
		std::vector<std::string> descriptionList;
		// a string for the key of a map.
		std::string key;

		// add all necessary row descriptions to the list.
		if (getOutputField() == Field::BYCLASS) {
			descriptionList.push_back("First Class -");
			descriptionList.push_back("Second Class-");
			descriptionList.push_back("Third Class -");
			descriptionList.push_back("Not Known   -");

		}
		else if (getOutputField() == Field::BYEMBARCATION) {
			descriptionList.push_back("Cherbourg   -");
			descriptionList.push_back("Queenstown  -");
			descriptionList.push_back("Southhampton-");
			descriptionList.push_back("Not Known   -");

		}
		else if (getOutputField() == Field::BYFARE) {
			descriptionList.push_back("Not Known   -");
			descriptionList.push_back("$ 1-$10     -");
			descriptionList.push_back("$10-$25     -");
			descriptionList.push_back("$25-$50     -");
			descriptionList.push_back("   >$50     -");
		}
		

		// initialize maps with each key corresponding to an element in the description list.
		for (int i = 0; i < descriptionList.size(); i++) {
			totalMap[descriptionList.at(i)] = 0;
			survivedMap[descriptionList.at(i)] = 0;
		}


		// iterate through the passenger list, calculating the number of survivors and total passengers based on the specified field.
		for (std::vector<Passenger*>::iterator it = mPassengerList.begin(); it != mPassengerList.end(); ++it) {
			// set the key for the map.
			switch (getOutputField()) {
			// based on the passenger's class.
			case Field::BYCLASS:
				if ((*it)->getClass() == Class::FIRST) {
					key = descriptionList[0];
				}
				else if ((*it)->getClass() == Class::SECOND) {
					key = descriptionList[1];
				}
				else if ((*it)->getClass() == Class::THIRD) {
					key = descriptionList[2];
				}
				else if ((*it)->getClass() == Class::NOTKNOWN) {
					key = descriptionList[3];
				}
				break;
			// based on the passenger's embarcation.
			case Field::BYEMBARCATION:
				if ((*it)->getEmbarcation() == Embarcation::CHERBOURG) {
					key = descriptionList[0];
				}
				else if ((*it)->getEmbarcation() == Embarcation::QUEENSTOWN) {
					key = descriptionList[1];
				}
				else if ((*it)->getEmbarcation() == Embarcation::SOUTHHAMPTON) {
					key = descriptionList[2];
				}
				else if ((*it)->getEmbarcation() == Embarcation::NOTKNOWN) {
					key = descriptionList[3];
				}
				break;
			// based on the passenger's fare.
			case Field::BYFARE:
				if ((*it)->getFare() > 0 && (*it)->getFare() <= 10) {
					key = descriptionList[1];
				}
				else if ((*it)->getFare() > 10 && (*it)->getFare() <= 25) {
					key = descriptionList[2];
				}
				else if ((*it)->getFare() > 25 && (*it)->getFare() <= 50) {
					key = descriptionList[3];
				}
				else if ((*it)->getFare() > 50) {
					key = descriptionList[4];
				}
				else {
					// not known fare
					key = descriptionList[0];
				}
				break;
			default:
				break;
			}

			// increment the count for survivors if they survived.
			if ((*it)->getSurvived()) {
				survivedMap[key]++;
			}

			// increment the count for total passengers
			totalMap[key]++;
		}


		// generate output table rows with the description list, total, and survived.
		for (int i = 0; i < descriptionList.size(); i++) {
			std::string description = descriptionList.at(i);
			int total = totalMap[descriptionList.at(i)];
			int survived = survivedMap[descriptionList.at(i)];

			// for each description element, create an output table row with calculated total and survived values. 
			OutputTableRow newOutputTableRow;
			newOutputTableRow.setDescription(description);
			newOutputTableRow.setTotal(total);
			newOutputTableRow.setSurvived(survived);
			// display each output table row.
			newOutputTableRow.display();
			// add each row to the rows vector
			mRows.push_back(newOutputTableRow);
		}

		std::cout << std::endl << std::endl;
	}

	// return the rows vector's size.
	size_t PassengerOutputTable::rowCount() {
		return mRows.size();
	}

	// return the OutputTableRow at the specified index.
	OutputTableRow PassengerOutputTable::getRow(int index) {
		if (index >= 0 && index < mRows.size()) {
			int i = 0;
			for (std::vector<OutputTableRow>::iterator it = mRows.begin(); it != mRows.end(); ++it) {
				if (index == i) {
					return (*it);
				}
				i++;
			}
		}

		// If the index is invalid, just return a default OutputTableRow.
		return OutputTableRow();
	}

}