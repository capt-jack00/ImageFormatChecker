#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "include/bintohex.h"

int main(){
    std::ifstream is("testimage.jpg", std::ios::binary);
    int length = 4;
    std::string binStr;
    std::vector<std::string> hexArr;

    //TODO: Add a function that will tell the user the format of the file. (Probably using some kind of std::map is the best solution)

    if (is) {
        std::cout << "Opened the file" << std::endl;
        char * buffer = new char[length]; // raw bytes are being stored here in an array
        is.read(buffer, length);
        
        for (size_t i = 0; i < length; ++i) {
            unsigned char byte = static_cast<unsigned char>(buffer[i]);

            std::cout << "Byte: ";
            for (int bit = 7; bit >= 0; --bit) {
                std::cout << ((byte >> bit) &1);
                binStr.push_back('0' + ((byte >> bit) &1));
            }

            std::cout << ' ';
            hexArr.push_back(binutil::binaryToHexadecimal(binStr));
            binStr = ""; // clear the string
            std::cout << '\n';
        }

        //TODO: Fix the cout below
        //ISSUE: Output looks like this: "t  bytes of the opened image:"
        std::cout << "First " + length << " bytes of the opened image: ";
        for(auto hex : hexArr){
            std::cout << hex << " ";
        }
        std::cout << '\n';
    }
    else{
        std::cout << "Failed to open the file!" << std::endl;
    }

    return 0;
}