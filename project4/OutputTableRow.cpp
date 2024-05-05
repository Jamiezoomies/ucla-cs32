#include "OutputTableRow.h"
#include <iostream>

namespace cs32 {

	// Constructor with the empty description, 0 survived, and 0 total.
	OutputTableRow::OutputTableRow() {
		mDescription = "";
		mSurvived = 0;
		mTotal = 0;
	}

	// description setter
	void OutputTableRow::setDescription(std::string description) {
		mDescription = description;
	}
	// survived setter
	void OutputTableRow::setSurvived(int survived) {
		mSurvived = survived;
	}
	// total setter
	void OutputTableRow::setTotal(int total) {
		mTotal = total;
	}
	// description getter
	std::string OutputTableRow::getDescription() {
		return mDescription;
	}

	// survived getter
	int OutputTableRow::getSurvived() {
		return mSurvived;
	}

	// total getter
	int OutputTableRow::getTotal() {
		return mTotal;
	}

	// return the percentage of survived relative to the total.
	double OutputTableRow::getPercentage() {
		// declare variable as double type
		double mSurvivedAsDouble(mSurvived);
		double mTotalAsDouble(mTotal);

		// if total is 0
		if (mTotalAsDouble == 0.0) {
			return 0.0;
		}

		double result = mSurvivedAsDouble / mTotalAsDouble;

		return result;

	}

	// display the description, survived, total, and percentage.
	void OutputTableRow::display() {
		std::cout << mDescription << "        " << mSurvived << "     /     " << mTotal << "         " << getPercentage() * 100 << std::endl;
	
	}

	// pad string to three chars.
	std::string OutputTableRow::padToThreeCharacters(int value) {
		std::string stringValue = std::to_string(value);
		if (stringValue.length() >= 3) {
			// If the string representation of the value is already three or more characters, no need for padding
			return stringValue;
		}
		else {
			// If the string representation of the value is less than three characters, pad with zeros
			return std::string(3 - stringValue.length(), '0') + stringValue;
		}
	}
}