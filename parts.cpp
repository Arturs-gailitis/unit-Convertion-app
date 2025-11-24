#include "parts.h"

void lenghtTitle(label& modeTittle) {
	modeTittle.caption("Lenght Convertion Mode");
}

void differntMode(combox& lenghtBox, button& convert, bool& statuss) {
	if (statuss == false) {
		lenghtBox.show();
		convert.show();
	}
	else {
		lenghtBox.hide();
		convert.hide();
	}
}

void switchModes(label& modeTitle, label& choiceLabel, textbox& givenUnit, textbox& resultUnit, label& resultText, button& goBack, label& unitText) {
	modeTitle.show();

	unitText.show();
	choiceLabel.show();
	givenUnit.show();
	resultUnit.show();
	resultText.show();
	goBack.show();
}

void hideModes(label& modeTitle, label& choiceLabel, textbox& givenUnit, textbox& resultUnit, label& resultText, button& goBack, 
	label& unitText) {
	modeTitle.hide();
	choiceLabel.hide();
	givenUnit.hide();
	resultUnit.hide();
	resultText.hide();
	goBack.hide();
	unitText.hide();
}

void frominfotoModes( label& infoTitle, label& mainIdea, button& infoButton, label& modeTitle, label& choiceLabel, textbox& givenUnit, 
	textbox& resultUnit, label& resultText, button& goBack, label& unitText) {
	infoTitle.hide();
	mainIdea.hide();
	infoButton.hide();

	switchModes(modeTitle, choiceLabel, givenUnit, resultUnit, resultText, goBack, unitText);
}

void massTitle(label& modeTittle) {
	modeTittle.caption("Mass Convertion Mode");
}

void timeTitle(label& modeTittle) {
	modeTittle.caption("Time Convertion Mode");
}

void temperatureTitle(label& modeTittle) {
	modeTittle.caption("Temperature Convertion Mode");
}

void areaTitle(label& modeTittle) {
	modeTittle.caption("Area Convertion Mode");
}