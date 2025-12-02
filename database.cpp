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

// ------------ When writing this code snippet I looked at this source - https://github.com/SRombauts/SQLiteCpp ------------ 
// get connection to local database
auto getConnection() {
	Database db("History.db", OPEN_READWRITE | OPEN_CREATE);
	return db;
}

// Delete old table and create new table
void newTable() {
	Database db = getConnection();
	db.exec("DROP TABLE IF EXISTS convertions");
	db.exec("CREATE TABLE IF NOT EXISTS convertions (id INTEGER PRIMARY KEY AUTOINCREMENT, givenNr INTEGER, convertion TEXT, result TEXT)");
}

// Insert values in the database table
void insertValues(int given, string convertion, string result) {
	Database db = getConnection();
	Statement querry(db, "INSERT INTO convertions (givenNr, convertion, result) VALUES (?, ?, ?)");
	querry.bind(1, given);
	querry.bind(2, convertion);
	querry.bind(3, result);
	querry.exec();
}

// Inserts values from the database table to the listbox
void selectValues(listbox& convertHistury) {
	convertHistury.clear();
	Database db = getConnection();
	Statement select(db, "SELECT givenNr, convertion, result FROM convertions");

	listbox::cat_proxy listCat = convertHistury.at(0);

	while (select.executeStep()) {
		string givenNr = select.getColumn(0).getString();
		string convertion = select.getColumn(1).getString();
		string result = select.getColumn(2).getString();
		listCat.append({ givenNr, convertion, result });
	}
}
// ------------ Code snippet ends ------------