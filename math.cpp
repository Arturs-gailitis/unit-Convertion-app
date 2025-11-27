#include "math.h"

// Change datatype from int to string
void convertToString(int number, int fraction, string& text, int constNumber) {

	if (fraction == 0) {
		text = to_string(number);
	}
	else {

		double fractionNumber = (double) fraction / constNumber;
		int remainderDivisor = 10;
		
		int standartNumber = 10;
		int secondStandartNumber = standartNumber * standartNumber;
		int thirdStandartNumber = secondStandartNumber * standartNumber;
		int fourthStandartNumber = thirdStandartNumber * standartNumber;
		int fithStandartNumber = fourthStandartNumber * standartNumber;
		int sixStandartNumber = fithStandartNumber * standartNumber;

		int firstNumber = (int) (fractionNumber * standartNumber);
		int secondNumber = (int)(fractionNumber * secondStandartNumber);
		int thirdNumber = (int) (fractionNumber * thirdStandartNumber);
		int fourthNumber = (int) (fractionNumber * fourthStandartNumber);
		int fithNumber = (int) (fractionNumber * fithStandartNumber);
		int sixNumber = (int) (fractionNumber * sixStandartNumber);

		if ((sixNumber % remainderDivisor) > 0) {
			text = to_string(number) + "," + to_string(firstNumber % remainderDivisor) + to_string(secondNumber % remainderDivisor) +
				to_string(thirdNumber % remainderDivisor) + to_string(fourthNumber % remainderDivisor) + to_string(fithNumber % remainderDivisor) + 
				to_string(sixNumber % remainderDivisor);
		}
		else if ((fithNumber % remainderDivisor) > 0) {
			text = to_string(number) + "," + to_string(firstNumber % remainderDivisor) + to_string(secondNumber % remainderDivisor) + 
				to_string(thirdNumber % remainderDivisor) + to_string(fourthNumber % remainderDivisor) + to_string(fithNumber % remainderDivisor);
		}
		else if ((fourthNumber % remainderDivisor) > 0) {
			text = to_string(number) + "," + to_string(firstNumber % remainderDivisor) + to_string(secondNumber % remainderDivisor) + 
				to_string(thirdNumber % remainderDivisor) + to_string(fourthNumber % remainderDivisor);
		}
		else if ((thirdNumber % remainderDivisor) > 0) {
			text = to_string(number) + "," + to_string(firstNumber % remainderDivisor) + to_string(secondNumber % remainderDivisor) + 
				to_string(thirdNumber % remainderDivisor);
		}
		else if ((secondNumber % remainderDivisor) > 0) {
			text = to_string(number) + "," + to_string(firstNumber % remainderDivisor) + to_string(secondNumber % remainderDivisor);
		}
		else if ((firstNumber % remainderDivisor) > 0) {
			text = to_string(number) + "," + to_string(firstNumber % remainderDivisor);
		}
	}
}

// Lenght //

// Convert meters to kilometers
void mToKm(int meters, string& kilometers) {
	int constNumber = 1000;
	int km = meters / constNumber;
	int kmDouble = meters % constNumber;
	convertToString(km, kmDouble, kilometers, constNumber);
}

// Convert meters to centimeters
void mToCm(int meters, string& centimeters) {
	int constNumber = 100;
	int cm = meters * constNumber;
	convertToString(cm, 0, centimeters, constNumber);
}

// Convert centimeters to meters
void cmToM(int centimeters, string& meters) {
	int constNumber = 100;
	int m = centimeters / constNumber;
	int metersDouble = centimeters % constNumber;
	convertToString(m, metersDouble, meters, constNumber);
}

// Convert centimeters to kilometers 
void cmToKm(int centimeters, string& kilometers) {
	int constNumber = 100000;
	int km = centimeters / constNumber;
	int kmDouble = centimeters % constNumber;
	convertToString(km, kmDouble, kilometers, constNumber);
}

// Convert kilometers to meters
void kmToM(int kilometers, string& meters) {
	int constNumber = 1000;
	int m = kilometers * constNumber;
	convertToString(m, 0, meters, constNumber);
}

// Convert kilometers to centimeters
void kmToCm(int kilometers, string& centimeters) {
	int constNumber = 100000;
	int cm = kilometers * constNumber;
	convertToString(cm, 0, centimeters, constNumber);
}

// Extracts given lenght value and returns converted value based of given option
void convertLenghtEvent(int& option, textbox& givenUnit, textbox& resultUnit) {
	string text = givenUnit.text();
	int number = stoi(text);

	if (option == 0) {
		mToKm(number, text);
	}
	else if (option == 1) {
		mToCm(number, text);
	}
	else if (option == 2) {
		cmToM(number, text);
	}
	else if (option == 3) {
		cmToKm(number, text);
	}
	else if (option == 4) {
		kmToM(number, text);
	}
	else if (option == 5) {
		kmToCm(number, text);
	}

	resultUnit.reset(text);
}

// Mass //

// Converts grams to kilograms
void gToKg(int grams, string& kilograms) {
	int constNumber = 1000;
	int kg = grams / constNumber;
	int kgDouble = grams % constNumber;
	convertToString(kg, kgDouble, kilograms, constNumber);
}

// Converts grams to tons
void gToT(int grams, string& tons) {
	int constNumber = 1000000;
	int t = grams / constNumber;
	int tDouble = grams % constNumber;
	convertToString(t, tDouble, tons, constNumber);
}

// Converts kilograms to tons
void kgToT(int kilograms, string& tons) {
	int constNumber = 1000;
	int t = kilograms / constNumber;
	int tDouble = kilograms % constNumber;
	convertToString(t, tDouble, tons, constNumber);
}

// Converts kilograms to grams
void kgToG(int kilograms, string& grams) {
	int constNumber = 1000;
	int g = kilograms * constNumber;
	convertToString(g, 0, grams, constNumber);
}

// Converts tons to kilograms
void tToKg(int tons, string& kilograms) {
	int constNumber = 1000;
	int kg = tons * constNumber;
	convertToString(kg, 0, kilograms, constNumber);
}

// Converts tons to grams
void tToG(int tons, string& grams) {
	int constNumber = 1000000;
	int g = tons * constNumber;
	convertToString(g, 0, grams, constNumber);
}

// Extracts given mass value and returns converted value based of given option
void convertMassEvent(int& option, textbox& givenUnit, textbox& resultUnit) {
	string text = givenUnit.text();
	int number = stoi(text);

	if (option == 0) {
		gToKg(number, text);
	}
	else if (option == 1) {
		gToT(number, text);
	}
	else if (option == 2) {
		kgToT(number, text);
	}
	else if (option == 3) {
		kgToG(number, text);
	}
	else if (option == 4) {
		tToKg(number, text);
	}
	else if (option == 5) {
		tToG(number, text);
	}

	resultUnit.reset(text);
}

// Time //

// Converts seconds to minutes
void sToMin(int seconds, string& minutes) {
	int constNumber = 60;
	int min = seconds / constNumber;
	int minDouble = seconds % constNumber;
	convertToString(min, minDouble, minutes, constNumber);
}

// Converts seconds to hours
void sToH(int seconds, string& hours) {
	int constNumber = 3600;
	int h = seconds / constNumber;
	int hDouble = seconds % constNumber;
	convertToString(h, hDouble, hours, constNumber);
}

// Converts minutes to hours
void minToH(int minutes, string& hours) {
	int constNumber = 60;
	int h = minutes / constNumber;
	int hDouble = minutes % constNumber;
	convertToString(h, hDouble, hours, constNumber);
}

// Converts minutes to seconds
void minToS(int minutes, string& seconds) {
	int constNumber = 60;
	int s = minutes * constNumber;
	convertToString(s, 0, seconds, constNumber);
}

// Converts hours to minutes
void hToMin(int hours, string& minutes) {
	int constNumber = 60;
	int min = hours * constNumber;
	convertToString(min, 0, minutes, constNumber);
}

// Converts hours to seconds
void hToS(int hours, string& seconds) {
	int constNumber = 3600;
	int s = hours * constNumber;
	convertToString(s, 0, seconds, constNumber);
}

// Extracts given time value and returns converted value based of given option
void convertTimeEvent(int& option, textbox& givenUnit, textbox& resultUnit) {
	string text = givenUnit.text();
	int number = stoi(text);

	if (option == 0) {
		sToMin(number, text);
	}
	else if (option == 1) {
		sToH(number, text);
	}
	else if (option == 2) {
		minToH(number, text);
	}
	else if (option == 3) {
		minToS(number, text);
	}
	else if (option == 4) {
		hToMin(number, text);
	}
	else if (option == 5) {
		hToS(number, text);
	}

	resultUnit.reset(text);
}