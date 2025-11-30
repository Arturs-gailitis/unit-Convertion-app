#include <nana/gui/widgets/listbox.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/label.hpp>
#include <SQLiteCpp/SQLiteCpp.h>
#include <string>

using namespace nana;
using namespace SQLite;
using namespace std;

void switchHistory(label&, button&, listbox&, bool&);

void historyTitle(label&);

void changeFromInfo(label&, label&, button&);

auto getConnection();

void newTable();

void insertValues(int, string, string);

void selectValues(listbox&);