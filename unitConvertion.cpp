#include <nana/gui.hpp>
#include <nana/gui/widgets/panel.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/combox.hpp>
#include <nana/gui/widgets/textbox.hpp>
#include "events.h"

using namespace nana;

int main() {

	bool lenghtStatuss = false;
	bool infoStatuss = false;

	// Gui window
	form window;
	window.caption("Unit Convertion Programm");
	window.size({ 475, 500 });
	window.bgcolor(color_rgb(0xEBDAAC));
	
	// Navigation bar
	panel<false> navbar(window, rectangle(0, 0, 475, 50), true);

	// Buttons for navigating
	button lenght(navbar, rectangle(5, 5 , 60, 25), true);
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

	// Switching from main part to info part and back
	info(infoButton, infoStatuss, welcomeMessage, briefInfo, briefInfo2, mainIdea, infoTitle);

	// Converting Parts //

	// Combo box explaining
	label choiceLabel(window, rectangle(40, 155, 200, 25), false);
	choiceLabel.caption("Choose the conversion type:");

	// input place for users iven value
	textbox givenUnit(window, rectangle(200, 200, 150, 25), false);

	// label for input place
	label unitText(window, rectangle(100, 205, 100, 25), false);
	unitText.caption("Enter your value:");

	textbox resultUnit(window, rectangle(200, 250, 150, 25), false);

	label resultText(window, rectangle(55, 255, 145, 25), false);
	resultText.caption("The new converted value:");

	button convert(window, rectangle(185, 300, 110, 30), false);
	convert.caption("Start Converting");
	convert.bgcolor(color_rgb(0xE5B940));

	// Lenght part //

	// Convertion lenght mode title
	label modeTitle(window, rectangle(125, 70, 250, 50), false);
	modeTitle.caption("Lenght Unit Convertion");
	modeTitle.typeface(paint::font("Times New Roman", 18, true));

	// Combo box for lenght conversions
	combox lenghtBox(window, rectangle(200, 150, 160, 25), false);
	lenghtBox.push_back("Meters to Kilometers");
	lenghtBox.push_back("Centimeters to Kilometers");
	lenghtBox.push_back("Millimeters to Kilometers");
	lenghtBox.push_back("Kilometers to Miles");
	int choice = lenghtBox.option();

	// Switching to lenght part and home
	lenghtUnit(lenght, lenghtStatuss, welcomeMessage, briefInfo, briefInfo2, infoButton, infoTitle, mainIdea, lenghtBox, choiceLabel,
		modeTitle, givenUnit, unitText, resultUnit, resultText, convert);

	window.show();
	nana::exec();
    return 0;
}
