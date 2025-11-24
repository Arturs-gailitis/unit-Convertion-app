#include "lenght.h"

void switchLenght(label& modeTitle, label& choiceLabel, textbox& givenUnit, textbox& resultUnit, label& resultText, button& goBack, label& unitText,
	combox& labelBox) {
	modeTitle.show();
	modeTitle.caption("Lenght Convertion Mode");

	unitText.show();
	labelBox.show();
	choiceLabel.show();
	givenUnit.show();
	resultUnit.show();
	resultText.show();
	goBack.show();
}

void hideLenght(label& modeTitle, label& choiceLabel, textbox& givenUnit, textbox& resultUnit, label& resultText, button& goBack, 
	label& unitText, combox& labelBox) {
	modeTitle.hide();
	choiceLabel.hide();
	givenUnit.hide();
	resultUnit.hide();
	resultText.hide();
	goBack.hide();
	unitText.hide();
	labelBox.hide();
}

void frominfotolenght( label& infoTitle, label& mainIdea, button& infoButton, label& modeTitle, label& choiceLabel, textbox& givenUnit, 
	textbox& resultUnit, label& resultText, button& goBack, label& unitText, combox& labelBox) {
	infoTitle.hide();
	mainIdea.hide();
	infoButton.hide();

	switchLenght(modeTitle, choiceLabel, givenUnit, resultUnit, resultText, goBack, unitText, labelBox);
}