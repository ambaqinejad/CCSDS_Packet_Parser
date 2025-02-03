#include "CCSDS_Packet.h"
#include <iostream>
#include <iomanip>
#include <cstring>
//#include <winsock2.h>
#include <cstdint>


using namespace std;

////
//// Created by ambaqinejad on 2/3/2025.
////

unsigned short CCSDS_Packet::getSequence() const {
    return sequence;
}

void CCSDS_Packet::setSequence(unsigned short _sequence) {
    CCSDS_Packet::sequence = _sequence;
}

unsigned short CCSDS_Packet::getLength() const {
    return length;
}

void CCSDS_Packet::setLength(unsigned short _length) {
    CCSDS_Packet::length = _length;
}

const std::vector<uint8_t> &CCSDS_Packet::getPayload() const {
    return payload;
}

void CCSDS_Packet::setPayload(const std::vector<uint8_t> &_payload) {
    CCSDS_Packet::payload = _payload;
}

unsigned short CCSDS_Packet::getHeader() const {
    return header;
}

void CCSDS_Packet::setHeader(unsigned short _header) {
    CCSDS_Packet::header = _header;
}

CCSDS_Packet::CCSDS_Packet() : header(0), sequence(0), length(0) {}

void CCSDS_Packet::parsePacket(const vector<uint8_t> &rawData) {
    if (rawData.size() < 6) {
        cerr << "Packet is too short for parsing!" << endl;
        return;
    }

    memcpy(&header, rawData.data(), 2);
    memcpy(&sequence, rawData.data() + 2, 2);
    memcpy(&length, rawData.data() + 4, 2);
//    length = ntohs(length);

    // extract payload
    payload.assign(rawData.begin() + 6, rawData.end());
}

// Display parsed packet data
void CCSDS_Packet::printPacket() const {
    cout << "CCSDS Packet Header Info:" << endl;
    cout << "Version: " << ((header >> 13) & 0x07) << endl;
    cout << "Type: " << ((header >> 12) & 0x01) << endl;
    cout << "APID " << (header & 0x07FF) << endl;
    cout << "Packet Sequence Count: " << ((sequence & 0x3FFF)) << endl;
    cout << "Payload Data: ";
    for (uint8_t byte: payload) {
        cout << hex << setw(2) << setfill('0') << (int)byte << " ";
    }
    cout << dec << endl;
}
