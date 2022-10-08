#pragma once

#include <string>
#include <iostream>

struct IpAddress {
public:
    uint8_t byte1;
    uint8_t byte2;
    uint8_t byte3;
    uint8_t byte4;

    friend bool operator< (const IpAddress& addr1, const IpAddress& addr2) {
        if (addr1.byte1 < addr2.byte1) return true;
        else if (addr1.byte1 > addr2.byte1) return false;

        if (addr1.byte2 < addr2.byte2) return true;
        else if (addr1.byte2 > addr2.byte2) return false;

        if (addr1.byte3 < addr2.byte3) return true;
        else if (addr1.byte3 > addr2.byte3) return false;

        if (addr1.byte4 < addr2.byte4) return true;
        else if (addr1.byte4 > addr2.byte4) return false;

        return false;
    }

    friend std::ostream& operator<< (std::ostream& stream, const IpAddress& addr) {
        stream << +addr.byte1 << '.' << +addr.byte2 << '.' << +addr.byte3 << '.' << +addr.byte4; 
        return stream;
    }

    static IpAddress parse(const std::string& line);
};