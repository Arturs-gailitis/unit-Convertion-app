#include "database.h"

// switch to history and back
void switchHistory(label& modeTitle, button& goBack, listbox& convertHistury, bool& statuss) {
	if (statuss == false) {
		modeTitle.hide();
		goBack.hide();
		convertHistury.hide();
	}
	else {
		modeTitle.show();
		goBack.show();
		convertHistury.show();
	}
}

// change mode title 
void historyTitle(label& modeTitle) {
	modeTitle.caption("History Mode");
}

// switching to history mode when user is in detailed info part
void changeFromInfo(label& infoTitle, label& mainIdea, button& infoButton) {
	infoTitle.hide();
	mainIdea.hide();
	infoButton.hide();
}