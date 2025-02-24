#include "CCSDS_Packet.h"
#include <iostream>
#include <cstring>
#include <iomanip>

CCSDS_Packet::CCSDS_Packet() : header(0), sequence(0), length(0) {}

uint16_t CCSDS_Packet::getSequence() const { return sequence; }

void CCSDS_Packet::setSequence(uint16_t _sequence) { sequence = _sequence; }

uint16_t CCSDS_Packet::getLength() const { return length; }

void CCSDS_Packet::setLength(uint16_t _length) { length = _length; }

uint16_t CCSDS_Packet::getHeader() const { return header; }

void CCSDS_Packet::setHeader(uint16_t _header) { header = _header; }

const std::vector<uint8_t> &CCSDS_Packet::getPayload() const { return payload; }

void CCSDS_Packet::setPayload(const std::vector<uint8_t> &_payload) { payload = _payload; }

void CCSDS_Packet::parsePacket(const vector<uint8_t> &rawData) {
    if (rawData.size() < 6) {
        cerr << "Packet is too short for parsing!" << endl;
        return;
    }

    memcpy(&header, rawData.data(), 2);
    memcpy(&sequence, rawData.data() + 2, 2);
    memcpy(&length, rawData.data() + 4, 2);

    payload.assign(rawData.begin() + 6, rawData.end());
}

void CCSDS_Packet::printPacket() const {
    cout << "CCSDS Packet Header Info:" << endl;
    cout << "Version: " << ((header >> 13) & 0x07) << endl;
    cout << "Type: " << ((header >> 12) & 0x01) << endl;
    cout << "APID: " << (header & 0x07FF) << endl;
    cout << "Packet Sequence Count: " << (sequence & 0x3FFF) << endl;
    cout << "Payload Data: ";
    for (uint8_t byte: payload) {
        cout << hex << setw(2) << setfill('0') << (int) byte << " ";
    }
    cout << dec << endl;
}

// C-Compatible Functions
extern "C" {
CCSDS_Packet *create_packet() {
    return new CCSDS_Packet();
}

void destroy_packet(CCSDS_Packet *packet) {
    delete packet;
}

void parse_packet(CCSDS_Packet *packet, uint8_t *data, int length) {
    vector<uint8_t> rawData(data, data + length);
    packet->parsePacket(rawData);
}

void print_packet(CCSDS_Packet *packet) {
    packet->printPacket();
}
}
