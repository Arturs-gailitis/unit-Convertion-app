#include <nana/gui.hpp>
#include <nana/gui/widgets/panel.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/combox.hpp>

using namespace nana;

int main() {

	bool lenghtStatuss = false;
	bool infoStatuss = false;

	// Gui window
	form window;
	window.caption("Unit Conversion Programm");
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
	label infoTitle(window, rectangle(200, 80, 150, 30), true);
	infoTitle.caption("Brief Info");
	infoTitle.typeface(paint::font("Times New Roman", 16, true));
	infoTitle.hide();

	// The main goal
	label mainIdea(window, rectangle(50, 120, 400, 50), true);
	mainIdea.caption("The main goal of this program is to convert different units of measurement to other units of measurement.");
	mainIdea.hide();

	// Switching from main part to info part and back
	infoButton.events().click([&] {
		if (infoStatuss == false) {
			infoStatuss = true;
			welcomeMessage.hide();
			briefInfo.hide();
			briefInfo2.hide();
			mainIdea.show();
			infoTitle.show();
			infoButton.caption("Go back to main");
		} else {
			infoStatuss = false;
			welcomeMessage.show();
			briefInfo.show();
			briefInfo2.show();
			mainIdea.hide();
			infoTitle.hide();
			infoButton.caption("Click for brief info");
		}
	});

	// Lenght Part //

	// Combo box explaining
	label choiceLabel(window, rectangle(40, 105, 200, 25), true);
	choiceLabel.caption("Choose the conversion type:");
	choiceLabel.hide();

	// Combo box for lenght conversions
	combox lenghtBox(window, rectangle(200, 100, 150, 25), true);
	lenghtBox.hide();
	lenghtBox.push_back("Meters to Kilometers");
	lenghtBox.push_back("Centimeters to Kilometers");
	lenghtBox.push_back("Millimeters to Kilometers");
	lenghtBox.push_back("Kilometers to Miles");
	int choice = lenghtBox.option();

	// Switching to lenght part and back
	lenght.events().click([&] {
		if (lenghtStatuss == false) {
			welcomeMessage.hide();
			briefInfo.hide();
			briefInfo2.hide();
			infoButton.hide();
			infoTitle.hide();
			mainIdea.hide();
			lenghtBox.show();
			choiceLabel.show();
			lenghtStatuss = true;
			lenght.caption("Home");
		} else {
			welcomeMessage.show();
			briefInfo.show();
			briefInfo2.show();
			infoButton.show();
			infoTitle.hide();
			mainIdea.hide();
			choiceLabel.hide();
			lenghtBox.hide();
			lenghtStatuss = false;
			lenght.caption("Lenght");
			infoButton.caption("Click for brief info");
		}
	});

	window.show();
	nana::exec();
    return 0;
}
