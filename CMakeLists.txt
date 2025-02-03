cmake_minimum_required(VERSION 3.30)
project(CCSDS_PARSER)

set(CMAKE_CXX_STANDARD 20)

add_executable(CCSDS_PARSER main.cpp sqlite_core/sqlite3.c
        CCSDS/CCSDS_Packet.cpp
        CCSDS/CCSDS_Packet.h
        database/SqliteDB.cpp
        database/SqliteDB.h)
