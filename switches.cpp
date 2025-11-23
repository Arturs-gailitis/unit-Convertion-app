#include "events.h"

void info(button& infoButton, bool& infoStatuss, label& welcomeMessage, label& briefInfo, label& briefInfo2, 
	label& mainIdea, label& infoTitle) {
	infoButton.events().click([&infoButton, &infoStatuss, &welcomeMessage, &briefInfo, &briefInfo2, &mainIdea, &infoTitle] {
		if (infoStatuss == false) {
			infoStatuss = true;
			welcomeMessage.hide();
			briefInfo.hide();
			briefInfo2.hide();
			mainIdea.show();
			infoTitle.show();
			infoButton.caption("Go back to main");
		}
		else {
			infoStatuss = false;
			welcomeMessage.show();
			briefInfo.show();
			briefInfo2.show();
			mainIdea.hide();
			infoTitle.hide();
			infoButton.caption("Click for brief info");
		}
		});
}

void lenghtUnit(button& lenght, bool& lenghtStatuss, label& welcomeMessage, label& briefInfo, label& briefInfo2, button& infoButton,
	label& infoTitle, label& mainIdea, combox& lenghtBox, label& choiceLabel, label& modeTitle, textbox& givenUnit, label& unitText,
	textbox& resultUnit, label& resultText, button& convert) {
	lenght.events().click([&lenght, &lenghtStatuss, &welcomeMessage, &briefInfo, &briefInfo2, &infoButton, &infoTitle, &mainIdea,
	&lenghtBox, &choiceLabel, &modeTitle, &givenUnit, &unitText, &resultUnit, &resultText, &convert] {
		if (lenghtStatuss == false) {
			welcomeMessage.hide();
			briefInfo.hide();
			briefInfo2.hide();
			infoButton.hide();
			infoTitle.hide();
			mainIdea.hide();
			lenghtBox.show();
			choiceLabel.show();
			modeTitle.show();
			givenUnit.show();
			unitText.show();
			resultUnit.show();
			resultText.show();
			convert.show();
			lenghtStatuss = true;
			lenght.caption("Home");
		}
		else {
			welcomeMessage.show();
			briefInfo.show();
			briefInfo2.show();
			infoButton.show();
			infoTitle.hide();
			mainIdea.hide();
			choiceLabel.hide();
			lenghtBox.hide();
			modeTitle.hide();
			givenUnit.hide();
			unitText.hide();
			resultUnit.hide();
			resultText.hide();
			convert.hide();
			lenghtStatuss = false;
			lenght.caption("Lenght");
			infoButton.caption("Click for brief info");
		}
		});
}