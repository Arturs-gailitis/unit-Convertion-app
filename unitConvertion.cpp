#include <nana/gui.hpp>
#include <nana/gui/widgets/panel.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/combox.hpp>
#include <nana/gui/widgets/textbox.hpp>
#include "info.h"
#include "parts.h"

using namespace nana;

int main() {

	bool statuss;

	// Gui window
	form window;
	window.caption("Unit Convertion Programm - TEST");
	window.size({ 475, 500 });
	window.bgcolor(color_rgb(0xEBDAAC));

	// Navigation bar
	panel<false> navbar(window, rectangle(0, 0, 475, 50), true);

	// Buttons for navigating
	button lenght(navbar, rectangle(5, 5, 60, 25), true);
	lenght.caption("Lenght");
	lenght.bgcolor(color_rgb(0xE5B940));

	button mass(navbar, rectangle(66, 5, 60, 25), true);
	mass.caption("Mass");
	mass.bgcolor(color_rgb(0xE5B940));

	button time(navbar, rectangle(127, 5, 60, 25), true);
	time.caption("Time");
	time.bgcolor(color_rgb(0xE5B940));

	button temperature(navbar, rectangle(188, 5, 100, 25), true);
	temperature.caption("Temperature");
	temperature.bgcolor(color_rgb(0xE5B940));

	button area(navbar, rectangle(289, 5, 60, 25), true);
	area.caption("Area ");
	area.bgcolor(color_rgb(0xE5B940));

	button history(navbar, rectangle(350, 5, 120, 25), true);
	history.caption("Convertion History");
	history.bgcolor(color_rgb(0xE5B940));

	// Main Part //

	// Programm intro title
	label welcomeMessage(window, rectangle(40, 120, 455, 50), true);
	welcomeMessage.caption("Welcome to Unit Conversion Program!");
	welcomeMessage.typeface(paint::font("Times New Roman", 18, true));

	// Telling the user where to find brief info
	label briefInfo(window, rectangle(100, 180, 350, 50), true);
	briefInfo.caption("Before using this programm check out brief info");

	label briefInfo2(window, rectangle(130, 210, 400, 50), true);
	briefInfo2.caption("by pressing the button down below.");

	// Button for switching to brief info
	button infoButton(window, rectangle(160, 250, 125, 30), true);
	infoButton.caption("Click for brief info");
	infoButton.bgcolor(color_rgb(0xE5B940));

	// Info Part //

	// Brief info title
	label infoTitle(window, rectangle(200, 80, 150, 30), false);
	infoTitle.caption("Brief Info");
	infoTitle.typeface(paint::font("Times New Roman", 16, false));

	// The main goal
	label mainIdea(window, rectangle(50, 120, 400, 50), false);
	mainIdea.caption("The main goal of this program is to convert different units of measurement to other units of measurement.");

	// Converting Parts //

	// Convertion lenght mode title
	label modeTitle(window, rectangle(125, 70, 250, 50), false);
	modeTitle.typeface(paint::font("Times New Roman", 18, true));

	// Combo box explaining
	label choiceLabel(window, rectangle(40, 155, 200, 25), false);
	choiceLabel.caption("Choose the conversion type:");

	// input place for users iven value
	textbox givenUnit(window, rectangle(200, 200, 150, 25), false);

	// label for input place
	label unitText(window, rectangle(100, 205, 100, 25), false);
	unitText.caption("Enter your value:");

	// the user can see the results
	textbox resultUnit(window, rectangle(200, 250, 150, 25), false);

	// label for the results
	label resultText(window, rectangle(55, 255, 145, 25), false);
	resultText.caption("The new converted value:");

	// button that goes back to main part
	button goBack(window, rectangle(185, 400, 110, 30), false);
	goBack.caption("Go Back");
	goBack.bgcolor(color_rgb(0xE5B940));

	// Lenght part //

	// Combo box for lenght conversions
	combox lenghtBox(window, rectangle(200, 150, 160, 25), false);
	lenghtBox.push_back("Meters to Kilometers");
	lenghtBox.push_back("Centimeters to Kilometers");
	lenghtBox.push_back("Millimeters to Kilometers");
	lenghtBox.push_back("Kilometers to Miles");
	int lenghtChoice = lenghtBox.option();

	// to convert lenght units
	button convertLenght(window, rectangle(185, 300, 110, 30), false);
	convertLenght.caption("Start Converting");
	convertLenght.bgcolor(color_rgb(0xE5B940));

	// Mass part //

	// Combo box for mass conversions
	combox massBox(window, rectangle(200, 150, 160, 25), false);
	int massChoice = massBox.option();

	// to convert mass units
	button convertMass(window, rectangle(185, 300, 110, 30), false);
	convertMass.caption("Start Converting");
	convertMass.bgcolor(color_rgb(0xE5B940));

	// Time part //

	// Combo box for time conversions
	combox timeBox(window, rectangle(200, 150, 160, 25), false);
	int timeChoice = timeBox.option();

	// to convert time units
	button convertTime(window, rectangle(185, 300, 110, 30), false);
	convertTime.caption("Start Converting");
	convertTime.bgcolor(color_rgb(0xE5B940));

	// Temperature part //

	// Combo box for temperature conversions
	combox temperatureBox(window, rectangle(200, 150, 160, 25), false);
	int temperatureChoice = temperatureBox.option();

	// to convert temperature units
	button convertTemperature(window, rectangle(185, 300, 110, 30), false);
	convertTemperature.caption("Start Converting");
	convertTemperature.bgcolor(color_rgb(0xE5B940));

	// Area part //

	// Combo box for area conversions
	combox areaBox(window, rectangle(200, 150, 160, 25), false);
	int areaChoice = areaBox.option();

	// to convert area units
	button convertArea(window, rectangle(185, 300, 110, 30), false);
	convertArea.caption("Start Converting");
	convertArea.bgcolor(color_rgb(0xE5B940));

	// History part //

	// Part events //

	// Switches to brief Info part and back home 
	infoButton.events().click([&]() {

		changeInfo(infoButton, infoTitle, mainIdea);
		statuss = false;
		disapierInfo(welcomeMessage, briefInfo, briefInfo2, statuss, infoButton);

		if (infoButton.caption() == "Click for brief info") {
			statuss = true;
			disapierInfo(welcomeMessage, briefInfo, briefInfo2, statuss, infoButton);
		}
	});

	// switches to lenght part from main and brief info part or from diffent parts
	lenght.events().click([&]() {
		if (infoButton.caption() == "Click for brief info") {
			switchModes(modeTitle, choiceLabel, givenUnit, resultUnit, resultText, goBack, unitText);
			infoButton.hide();
			statuss = false;
			differntMode(lenghtBox, convertLenght, statuss);
			disapierInfo(welcomeMessage, briefInfo, briefInfo2, statuss, infoButton);
			lenghtTitle(modeTitle);
		}
		else if (infoButton.caption() == "Back to main part") {
			frominfotoModes(infoTitle, mainIdea, infoButton, modeTitle, choiceLabel, givenUnit, resultUnit, resultText, goBack, unitText);
			statuss = false;
			differntMode(lenghtBox, convertLenght, statuss);
			lenghtTitle(modeTitle);
		}
	});

	// switches to mass part from main and brief info part
	mass.events().click([&]() {
		if (infoButton.caption() == "Click for brief info") {
			switchModes(modeTitle, choiceLabel, givenUnit, resultUnit, resultText, goBack, unitText);
			infoButton.hide();
			statuss = false;
			differntMode(massBox, convertMass, statuss);
			disapierInfo(welcomeMessage, briefInfo, briefInfo2, statuss, infoButton);
			massTitle(modeTitle);
		}
		else if (infoButton.caption() == "Back to main part") {
			frominfotoModes(infoTitle, mainIdea, infoButton, modeTitle, choiceLabel, givenUnit, resultUnit, resultText, goBack, unitText);
			statuss = false;
			differntMode(massBox, convertMass, statuss);
			massTitle(modeTitle);
		}
	});

	// switches to time part from main and brief info part
	time.events().click([&]() {
		if (infoButton.caption() == "Click for brief info") {
			switchModes(modeTitle, choiceLabel, givenUnit, resultUnit, resultText, goBack, unitText);
			infoButton.hide();
			statuss = false;
			differntMode(timeBox, convertTime, statuss);
			disapierInfo(welcomeMessage, briefInfo, briefInfo2, statuss, infoButton);
			timeTitle(modeTitle);
		}
		else if (infoButton.caption() == "Back to main part") {
			frominfotoModes(infoTitle, mainIdea, infoButton, modeTitle, choiceLabel, givenUnit, resultUnit, resultText, goBack, unitText);
			statuss = false;
			differntMode(timeBox, convertTime, statuss);
			timeTitle(modeTitle);
		}
	});

	// switches to time part from main and brief info part
	temperature.events().click([&]() {
		if (infoButton.caption() == "Click for brief info") {
			switchModes(modeTitle, choiceLabel, givenUnit, resultUnit, resultText, goBack, unitText);
			infoButton.hide();
			statuss = false;
			differntMode(temperatureBox, convertTemperature, statuss);
			disapierInfo(welcomeMessage, briefInfo, briefInfo2, statuss, infoButton);
			temperatureTitle(modeTitle);
		}
		else if (infoButton.caption() == "Back to main part") {
			frominfotoModes(infoTitle, mainIdea, infoButton, modeTitle, choiceLabel, givenUnit, resultUnit, resultText, goBack, unitText);
			statuss = false;
			differntMode(temperatureBox, convertTemperature, statuss);
			temperatureTitle(modeTitle);
		}
	});

	// switches to area part from main and brief info part
	area.events().click([&]() {
		if (infoButton.caption() == "Click for brief info") {
			switchModes(modeTitle, choiceLabel, givenUnit, resultUnit, resultText, goBack, unitText);
			infoButton.hide();
			statuss = false;
			differntMode(areaBox, convertArea, statuss);
			disapierInfo(welcomeMessage, briefInfo, briefInfo2, statuss, infoButton);
			areaTitle(modeTitle);
		}
		else if (infoButton.caption() == "Back to main part") {
			frominfotoModes(infoTitle, mainIdea, infoButton, modeTitle, choiceLabel, givenUnit, resultUnit, resultText, goBack, unitText);
			statuss = false;
			differntMode(areaBox, convertArea, statuss);
			areaTitle(modeTitle);
		}
	});

	// multiple switches from convertion part to main part
	goBack.events().click([&]() {
		if (modeTitle.caption() == "Lenght Convertion Mode") {
			hideModes(modeTitle, choiceLabel, givenUnit, resultUnit, resultText, goBack, unitText);
			statuss = true;
			differntMode(lenghtBox, convertLenght, statuss);
			disapierInfo(welcomeMessage, briefInfo, briefInfo2, statuss, infoButton);
		
		}
		else if (modeTitle.caption() == "Mass Convertion Mode") {
			hideModes(modeTitle, choiceLabel, givenUnit, resultUnit, resultText, goBack, unitText);
			statuss = true;
			differntMode(massBox, convertMass, statuss);
			disapierInfo(welcomeMessage, briefInfo, briefInfo2, statuss, infoButton);
		}
		else if (modeTitle.caption() == "Time Convertion Mode") {
			hideModes(modeTitle, choiceLabel, givenUnit, resultUnit, resultText, goBack, unitText);
			statuss = true;
			differntMode(timeBox, convertTime, statuss);
			disapierInfo(welcomeMessage, briefInfo, briefInfo2, statuss, infoButton);
		}
		else if (modeTitle.caption() == "Temperature Convertion Mode") {
			hideModes(modeTitle, choiceLabel, givenUnit, resultUnit, resultText, goBack, unitText);
			statuss = true;
			differntMode(temperatureBox, convertTemperature, statuss);
			disapierInfo(welcomeMessage, briefInfo, briefInfo2, statuss, infoButton);
		}
		else if (modeTitle.caption() == "Area Convertion Mode") {
			hideModes(modeTitle, choiceLabel, givenUnit, resultUnit, resultText, goBack, unitText);
			statuss = true;
			differntMode(areaBox, convertArea, statuss);
			disapierInfo(welcomeMessage, briefInfo, briefInfo2, statuss, infoButton);
		}
	});

	window.show();
	exec();

	return 0;
}