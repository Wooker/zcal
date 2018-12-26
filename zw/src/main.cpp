#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sqlite3.h>
#include <string>

static int callback (void *data, int argc, char **argv, char **azColName) {
	int i;
	fprintf(stderr, "%s: ", (const char*)data);
	printf ("\n");
	for (i = 0; i < argc; i++)
		printf ("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	printf ("\n");
	return 0;
}

int main()
{
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	const char* data = "Callback function called";

	std::string answer, sql;

	// Open database
	rc = sqlite3_open("../cal.db", &db);

	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return 0;
	}

	std::string date, description;

	// Date input
	std::cout << "What is the date of your event? ";
	std::getline(std::cin, date);
	if (date == "") {
		std::cerr << "Error: Date is empty\n";
		return 0;
	}

	// Event description input
	std::cout << "Event description: ";
	std::getline(std::cin, description);
	if (description == "") {
		std::cerr << "Error: Description is empty\n";
		return 0;
	}

	// Create SQL statement
	// Insert event into database
	sql = "INSERT INTO EVENTS (DATE, EVENT) " \
			   "VALUES ('" + date + "', '" + description + "');";

	// Execute SQL statement
	rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &zErrMsg);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}

	// Close database
	sqlite3_close(db);

	return 0;
}
