//
// Created by ambaqinejad on 2/3/2025.
//

#ifndef CCSDS_PARSER_SQLITEDB_H
#define CCSDS_PARSER_SQLITEDB_H

#include "../CCSDS/CCSDS_Packet.h"

class SqliteDB {
    void insertIntoSQLite(const CCSDS_Packet& packet);
};


#endif //CCSDS_PARSER_SQLITEDB_H
