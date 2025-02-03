#include <iostream>
#include "sqlite_core/sqlite3.h"
#include <cstdint>
#include <vector>
#include <iostream>
#include <iomanip>
#include <winsock2.h>
#include "CCSDS/CCSDS_Packet.h"

using namespace std;
int main () {
    // Simulated CCSDS packet data (APID = 100, Seq Count = 5, Payload = {0x11, 0x22, 0x33})
    vector<uint8_t> rawData = {0x00, 0x64, 0x00, 0x05, 0x00, 0x03, 0x11, 0x22, 0x33};

    // Parse the CCSDS packet
    CCSDS_Packet packet;
    packet.parsePacket(rawData);
    packet.printPacket();

    return 0;
}