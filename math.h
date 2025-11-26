#include <string>
#include <nana/gui/widgets/textbox.hpp>

using namespace std;
using namespace nana;

void convertToString(int, int, string&, int);

void mToKm(int, string&);

void mToCm(int, string&);

void cmToM(int, string&);

void cmToKm(int, string&);

void kmToM(int, string&);

void kmToCm(int, string&);

void convertLenghtEvent(int&, textbox&, textbox&);

void gToKg(int, string&);

void gToT(int, string&);

void kgToT(int, string&);

void kgToG(int, string&);

void tToKg(int, string&);

void tToG(int, string&);

void convertMassEvent(int&, textbox&, textbox&);