#ifndef OUTPUTTABLEROW_H
#define OUTPUTTABLEROW_H

#include <string>

namespace cs32 {

	class OutputTableRow {
	public:
		OutputTableRow();
		void setDescription(std::string description);
		void setSurvived(int survived);
		void setTotal(int total);

		std::string getDescription();
		int getSurvived();
		int getTotal();
		double getPercentage();

		void display();

	private:
		std::string mDescription;
		int mSurvived;
		int mTotal;

		std::string padToThreeCharacters(int value);

	};
	
}

#endif
