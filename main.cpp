#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include "include/bintohex.h"

int main(){
    //TODO: Add an option for the user to manually choose the file directory
    std::ifstream is("cat.png", std::ios::binary);
    int length = 4;
    std::string binStr;
    std::vector<std::string> hexArr;

    //TODO: Expand the list with more file formats
    //TODO: Improve the readablity of the below vector (this can be problematic once the list gets larger)
    std::map<std::string, std::string> formats = {
        {"FFD8FFE0", "JPEG"},
        {"89504E47", "PNG"},
        {"47494638", "GIF"},
        {"25504446", "PDF"},
        {"424D", "BMP"},
        {"49492A00", "TIFF"},
        {"4D4D002A", "TIFF"},
        {"52494646", "WAV"},
        {"ID3", "MP3"},
        {"FFFE4500", "EXE"},
        {"7F454C46", "ELF"},
    };

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
            std::cout << '\n';
        }

        std::cout << "Hex values of first " << length << " bytes of the file: " << binutil::bintohex(binStr) << std::endl;
        std::cout << "The file is a " << formats[binutil::bintohex(binStr)] << " file." << std::endl;
        //TODO: Add better error handling (in case when the format is not found) 
    }
    else{
        std::cout << "Failed to open the file!" << std::endl;
    }

    return 0;
}