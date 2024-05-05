#include "Passenger.h"

namespace cs32 {

	// constructor. set member variables to their default values.
	Passenger::Passenger() {
		mClass = Class::NOTKNOWN;
		mEmbarked = Embarcation::NOTKNOWN;
		mFare = 0;
		mSurvived = false;
		mName = "";
	}

	// name setter
	void Passenger::setName(std::string name) {
		mName = name;
	}

	// name getter
	std::string Passenger::getName() {
		return mName;
	}

	// set embarcation based on the specified embarked string.
	void Passenger::setEmbarcation(std::string embarked) {
		if (embarked == "C") {
			mEmbarked = Embarcation::CHERBOURG;
		}
		else if (embarked == "Q") {
			mEmbarked = Embarcation::QUEENSTOWN;
		}
		else if (embarked == "S") {
			mEmbarked = Embarcation::SOUTHHAMPTON;
		}
		else {
			mEmbarked = Embarcation::NOTKNOWN;
		}
	}

	// set class based on the specified classofFare string.
	void Passenger::setClass(std::string classofFare) {
		if (classofFare == "1") {
			mClass = Class::FIRST;
		}
		else if (classofFare == "2") {
			mClass = Class::SECOND;
		}
		else if (classofFare == "3") {
			mClass = Class::THIRD;
		}
		else {
			mClass = Class::NOTKNOWN;
		}
	}

	// set survived to true if the string is "1"; otherwise, set it to false.
	void Passenger::setSurvived(std::string survived) {
		if (survived == "1") {
			mSurvived = true;
		}
		else if (survived == "0") {
			mSurvived = false;
		}
		else {
			mSurvived = false;
		}
	}
	// fare setter
	void Passenger::setFare(std::string fare) {
		
		bool isNumeric = true;
		
		// validate if fare is non empty
		if (fare == "") {
			isNumeric = false;
		}

		// validate if the fare string is numeric
		for (int i = 0; i < fare.size(); i++) {
			if (!std::isdigit(fare.at(i)) && fare.at(i) != '.') {
				isNumeric = false;
				break;
			}
		}

		// if the fare string is numeric, convert it to double; otherswise, set fare to 0
		if (isNumeric) {
			mFare = std::stod(fare);
		}
		else {
			mFare = 0;
		}
	}

	// embarcation getter
	Embarcation Passenger::getEmbarcation() {
		return mEmbarked;
	}

	// class getter
	Class Passenger::getClass() {
		return mClass;
	}

	// isSurvived getter
	bool Passenger::getSurvived() {
		return mSurvived;
	}

	// fare getter
	double Passenger::getFare() {
		return mFare;
	}



}