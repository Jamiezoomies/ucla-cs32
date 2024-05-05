#ifndef PASSENGEROUTPUTTABLE_H
#define PASSENGEROUTPUTTABLE_H

#include <vector>
#include "Passenger.h"
#include "OutputTableRow.h"

namespace cs32 {

class PassengerOutputTable {

public:
	// Constructor for PassengerOutputTable
	PassengerOutputTable(std::vector<Passenger*> passengers);
	// Field setter.
	void setOutputField(Field f);
	// Description setter
	void setDescription(std::string description);
	// Field getter
	Field getOutputField();
	// Description getter
	std::string getDescription();
	// display output table rows
	void display();

	// return the rows vector's size.
	size_t rowCount();
	// return the OutputTableRow at the specified index.
	OutputTableRow getRow(int index);

private:
	std::vector<Passenger*> mPassengerList;
	std::vector<OutputTableRow> mRows;
	Field mField;
	std::string mDescription;

};
}


#endif
