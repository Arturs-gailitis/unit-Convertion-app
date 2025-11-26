#include "parts.h"

// Change the lenght mode tittle
void lenghtTitle(label& modeTittle) {
	modeTittle.caption("Lenght Convertion Mode");
}

// Changes the invisibility for different mode
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

// Changes the visibility for default elements in converting mode 
void switchModes(label& modeTitle, label& choiceLabel, textbox& givenUnit, textbox& resultUnit, label& resultText, button& goBack, label& unitText) {
	modeTitle.show();

	unitText.show();
	choiceLabel.show();
	givenUnit.show();
	resultUnit.show();
	resultText.show();
	goBack.show();
}

// Hides the default elements in converting mode
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

// chnages from info to converting mode
void frominfotoModes( label& infoTitle, label& mainIdea, button& infoButton, label& modeTitle, label& choiceLabel, textbox& givenUnit, 
	textbox& resultUnit, label& resultText, button& goBack, label& unitText) {
	infoTitle.hide();
	mainIdea.hide();
	infoButton.hide();

	switchModes(modeTitle, choiceLabel, givenUnit, resultUnit, resultText, goBack, unitText);
}

// Change the mass mode tittle
void massTitle(label& modeTittle) {
	modeTittle.caption("Mass Convertion Mode");
}

// Change the time mode tittle
void timeTitle(label& modeTittle) {
	modeTittle.caption("Time Convertion Mode");
}

// Change the temperature mode tittle
void temperatureTitle(label& modeTittle) {
	modeTittle.caption("Temperature Convertion Mode");
}

// Change the area mode tittle
void areaTitle(label& modeTittle) {
	modeTittle.caption("Area Convertion Mode");
}

void navChange(panel<false>& nav, bool& statuss ) {
	if (statuss == false) {
		nav.hide();
	
	}
	else {
		nav.show();
	}
}