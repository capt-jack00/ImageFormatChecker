#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include "include/bintohex.h"

//TODO: Write a detailed documentation for the code.

int main(int argc, char* argv[]){
    // Arguments
    std::string imgPath;
    if(argc == 2){
        imgPath = argv[1];
    }
    else{
        std::cout << "Incorrect amount of arguments provided!" << std::endl;
        return 0;
    }

    //TODO: Add an option for the user to manually choose the file directory
    std::ifstream imgStream(imgPath, std::ios::binary);
    int length = 10;
    std::string binStr;
    std::vector<std::string> hexArr;

    //TODO: Expand the list with more file formats
    //TODO: Improve the readablity of the below vector (this can be problematic once the list gets larger)
    std::map<std::string, std::string> formats = {
        {"FFD8FFE0", "JPEG"},
        {"89504E47", "PNG"},
        {"494433", "MP3"},
        {"5A4D", "EXE"}
    };

    if (imgStream) {
        std::cout << "Opened the file" << std::endl;
        std::cout << imgPath << std::endl;
        char * buffer = new char[length]; // raw bytes are being stored here in an array
        imgStream.read(buffer, length);
        
        for (size_t i = 0; i >= 0; ++i) {
            unsigned char byte = static_cast<unsigned char>(buffer[i]);

            std::cout << "Byte: ";
            for (int bit = 7; bit >= 0; --bit) {
                std::cout << ((byte >> bit) &1);
                binStr.push_back('0' + ((byte >> bit) &1));
            }

            std::cout << ' ';
            std::cout << '\n';

            //WARNING: This may be a bit dangerous. Every time when format is not found a new element in std::map is being created. It can easlily cause errors!
            if(formats[binutil::bintohex(binStr)] != ""){
                break;
            }
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