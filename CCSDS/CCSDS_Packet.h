//
// Created by ambaqinejad on 2/3/2025.
//

#ifndef CCSDS_PARSER_CCSDS_PACKET_H
#define CCSDS_PARSER_CCSDS_PACKET_H

#include <iostream>
#include <cstdint>
#include <vector>

using namespace std;
class CCSDS_Packet {
public:
    uint16_t getSequence() const;

    void setSequence(uint16_t sequence);

    uint16_t getLength() const;

    void setLength(uint16_t length);

    const vector<uint8_t> &getPayload() const;

    void setPayload(const vector<uint8_t> &payload);

    uint16_t getHeader() const;

    void setHeader(uint16_t header);

    // Constructor
    CCSDS_Packet();

    // Parse raw binary data
    void parsePacket(const vector<uint8_t>& rawData);

    // Display Parsed Packet Data
    void printPacket() const;

private:
    uint16_t header; // First 2 bytes: Version (3), Type (1), SecHdrFlag (1), APID (11)
    uint16_t sequence; // Next 2 bytes: Seq Flags (2), Packet Sequence Count (14)
    uint16_t length; // Next 2 bytes: Packet Length (excluding header)
    vector <uint8_t> payload; // Payload Data
};


#endif //CCSDS_PARSER_CCSDS_PACKET_H
