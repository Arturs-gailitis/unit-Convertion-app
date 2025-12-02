#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/textbox.hpp>
#include <nana/gui/widgets/combox.hpp>
#include <nana/gui/widgets/panel.hpp>

using namespace nana;

void switchModes(label&, label&, textbox&, textbox&, label&, button&, label&);

void hideModes(label&, label&, textbox&, textbox&, label&, button&, label&);

void frominfotoModes(label&, label&, button&, label&, label&, textbox&, textbox&, label&, button&, label&);

void lenghtTitle(label&);

void differntMode(combox&, button&, bool&);

void massTitle(label&);

void timeTitle(label&);

void temperatureTitle(label&);

void areaTitle(label&);

void navChange(panel<false>&, bool&);

void cleanFields(textbox&, textbox&);