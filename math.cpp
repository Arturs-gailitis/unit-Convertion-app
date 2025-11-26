#include "math.h"

// Change datatype from int to string
void convertToString(int number, int fraction, string& text, int constNumber) {

	if (fraction == 0) {
		text = to_string(number);
	}
	else {

		double fractionNumber = (double) fraction / constNumber;
		int remainderDivisor = 10;

		int firstNumber = (int) (fractionNumber * 10);
		int secondNumber = (int) (fractionNumber * 100);
		int thirdNumber = (int) (fractionNumber * 1000);
		int fourthNumber = (int) (fractionNumber * 10000);
		int fithNumber = (int) (fractionNumber * 100000);

		if ((fithNumber % remainderDivisor) > 0) {
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