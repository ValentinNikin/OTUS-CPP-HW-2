#include "ip.h"

#include "utils.h"

IpAddress IpAddress::parse(const std::string& line) {
    auto bytes = utils::split(line, '.');

    if (bytes.size() != 4) {
        throw std::invalid_argument(line + " is not ip address");
    }

    auto convertAndCheckByte = [](const std::string& byteStr) {
        auto byte = atoi(byteStr.c_str());

        if (byte >= 0 && byte <= 255) {
            return static_cast<uint8_t>(byte);
        }

        throw std::invalid_argument("IP byte must be in [0, 255] range");
    };

    IpAddress addr;
    addr.byte1 = convertAndCheckByte(bytes[0]);
    addr.byte2 = convertAndCheckByte(bytes[1]);
    addr.byte3 = convertAndCheckByte(bytes[2]);
    addr.byte4 = convertAndCheckByte(bytes[3]);

    return addr;
}