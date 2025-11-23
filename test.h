#include <nana/gui.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/listbox.hpp>
#include <SQLiteCpp/SQLiteCpp.h>
#include <vector>
#include <string>

void test() {
    using namespace nana;

    // GUI logs
    form fm;
    fm.caption("Nana + SQLiteCpp piemers");
    fm.size({ 400, 300 });

    // Listbox, lai parādītu datubāzes saturu
    listbox lst(fm, rectangle(10, 10, 380, 200));
    lst.append_header("People");

    // Poga, lai pievienotu ierakstu
    button btn(fm, rectangle(10, 220, 120, 30));
    btn.caption("Saglabat DB");

    // Funkcija datubāzes satura atjaunošanai logā
    auto refresh_list = [&lst]() {
        lst.clear(); // Notīra iepriekšējo saturu
        try {
            SQLite::Database db("test.db", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);

            // **Izveido tabulu tikai, ja tās nav**
            db.exec("CREATE TABLE IF NOT EXISTS people(name TEXT)");

            SQLite::Statement query(db, "SELECT name FROM people");
            while (query.executeStep()) {
                lst.at(0).append({ query.getColumn(0).getString() });
            }
        }
        catch (std::exception& e) {
            msgbox mb("Error");
            mb << e.what();
            mb.show();
        }
        };

    // Poga → pievieno datubāzes ierakstu
    btn.events().click([&refresh_list]() {
        try {
            SQLite::Database db("test.db", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);
            SQLite::Statement query(db, "INSERT INTO people VALUES ('Janis')");
            query.exec();
        }
        catch (std::exception& e) {
            msgbox mb("Error");
            mb << e.what();
            mb.show();
        }

        // Atjauno listbox
        refresh_list();
        });

    // Inicializē logu ar esošajiem datiem
    refresh_list();

    fm.show();
    exec();
}