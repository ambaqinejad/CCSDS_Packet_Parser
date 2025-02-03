#ifndef CCSDS_PARSER_CCSDS_PACKET_H
#define CCSDS_PARSER_CCSDS_PACKET_H

#include <iostream>
#include <cstdint>
#include <vector>

using namespace std;

class CCSDS_Packet {
public:
    [[nodiscard]] uint16_t getSequence() const;
    void setSequence(uint16_t sequence);
    [[nodiscard]] uint16_t getLength() const;
    void setLength(uint16_t length);
    [[nodiscard]] const vector<uint8_t> &getPayload() const;
    void setPayload(const vector<uint8_t> &payload);
    [[nodiscard]] uint16_t getHeader() const;
    void setHeader(uint16_t header);

    // Constructor
    CCSDS_Packet();

    // Parse raw binary data
    void parsePacket(const vector<uint8_t>& rawData);

    // Display Parsed Packet Data
    void printPacket() const;

private:
    uint16_t header;
    uint16_t sequence;
    uint16_t length;
    vector<uint8_t> payload;
};

// C Wrapper for Python Compatibility
extern "C" {
CCSDS_Packet* create_packet();
void destroy_packet(CCSDS_Packet* packet);
void parse_packet(CCSDS_Packet* packet, uint8_t* data, int length);
void print_packet(CCSDS_Packet* packet);
}

#endif // CCSDS_PARSER_CCSDS_PACKET_H
