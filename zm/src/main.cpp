#include <stdio.h>
#include <iostream>
#include <stdlib.h>
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

	std::string sql;

	// Open database
	rc = sqlite3_open("../cal.db", &db);

	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return 0;
	}

	while (true) {

		std::cout << "Write your SQL Query:" << std::endl;
		// Create SQL statement
		std::getline(std::cin, sql);

		// Execute SQL statement
		rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &zErrMsg);

		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		} else
			fprintf(stdout, "Operation done successfully\n");
	}

	return 0;
}
