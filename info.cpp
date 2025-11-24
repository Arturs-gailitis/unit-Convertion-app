#include "info.h"

// Switches between info and main part
void changeInfo(button& button, label& infoTitle, label& mainIdea) {
	button.show();
	
	if (button.caption() == "Click for brief info") {
		infoTitle.show();
		mainIdea.show();
		button.caption("Back to main part");
	}
	else {
		infoTitle.hide();
		mainIdea.hide();
		button.caption("Click for brief info");
	}

}

// Hides and shows main part
void disapierInfo(label& welcomeMessage, label& briefInfo, label& briefInfo2, bool& statuss, button& infoButton) {
	if (statuss == false) {
		welcomeMessage.hide();
		briefInfo.hide();
		briefInfo2.hide();
		statuss = true;
	}
	else {
		infoButton.show();
		infoButton.caption("Click for brief info");

		welcomeMessage.show();
		briefInfo.show();
		briefInfo2.show();
		statuss = false;
	}
}