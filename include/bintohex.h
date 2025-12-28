#pragma once

#include <string>
#include <bitset>
#include <sstream>

namespace binutil {

    inline std::string binaryToHexadecimal(std::string binary)
    {
        while (binary.length() % 4 != 0)
        {
            binary.insert(binary.begin(), '0');
        }

        std::stringstream hexResult;
        hexResult << std::uppercase << std::hex;

        for (std::size_t i = 0; i < binary.length(); i += 4)
        {
            std::bitset<4> bits(binary.substr(i, 4));
            hexResult << bits.to_ulong();
        }

        return hexResult.str();
    }

}
