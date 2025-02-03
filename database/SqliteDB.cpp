//
// Created by ambaqinejad on 2/3/2025.
//


#include "../sqlite_core/sqlite3.h"
#include "SqliteDB.h"
#include <iostream>

using namespace std;

void SqliteDB::insertIntoSQLite(const CCSDS_Packet &packet) {
    sqlite3* db;
    sqlite3_stmt* stms;
    const char* db_name = "ccsds_data.db";

    if (sqlite3_open(db_name, &db)) {
        cerr << "Error opening SQLite database: " << sqlite3_errmsg(db) << endl;
        return;
    }

    // Create table if not exists
    const char* createTableQuery =
            "CREATE TABLE IF NOT EXISTS CCSDS_TELEMETRY ("
            "id INTEGER PRIMARY KEY AUTOINCREMENT, "
            "apid INT, "
            "sequence INT"
            "length INT"
            "payload BLOB);";

    if (sqlite3_exec(db, createTableQuery, nullptr, nullptr, nullptr) != SQLITE_OK) {
        cerr << "Error creating table: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        return;
    }



}
