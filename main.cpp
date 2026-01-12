#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include "include/bintohex.h"


int main(int argc, char* argv[]){
    std::string imgPath;
    if(argc == 2){                                                                  //This argc needs to be equal to number 2 because executing command "./main" also counts as an argument
        imgPath = argv[1];                                                          //The second argument equals an image path
    }
    else{
        std::cout << "Incorrect amount of arguments provided!" << std::endl;
        return 0;
    }

    std::ifstream imgStream(imgPath, std::ios::binary);                             //Open the file in binary
    int length = 10;
    std::string binStr;                                                             //Bytes are stored in this variable. It's a sting to make the output easier                                                     

    //TODO: Expand the list with more file formats
    //TODO: Improve the readablity of the below vector (this can be problematic once the list gets larger)
    std::map<std::string, std::string> formats = {                                  //Simple map with formats. Hex values are keys to easily check the file format
        {"FFD8FFE0", "JPEG"},
        {"89504E47", "PNG"},
        {"494433", "MP3"},
        {"5A4D", "EXE"}
    };

    if (imgStream) {
        std::cout << "Opened the file" << std::endl;
        std::cout << imgPath << std::endl;                                          //Optional. It's for debuging
        char * buffer = new char[length];                                           //Raw bytes are being stored here in an array
        imgStream.read(buffer, length);                                             //Read the buffer with the lenght of "length" variable
        
        for (size_t i = 0; i >= 0; ++i) {
            unsigned char byte = static_cast<unsigned char>(buffer[i]);             //This converts a pointer to normal char variable

            std::cout << "Byte: ";
            for (int bit = 7; bit >= 0; --bit) {                                    //Counts descending because bytes are being read from right to left instead of left to right
                std::cout << ((byte >> bit) &1);
                binStr.push_back('0' + ((byte >> bit) &1));
            }

            std::cout << ' ';
            std::cout << '\n';                                                      //Optional. Just a space for decorative purpouses

            if(formats[binutil::bintohex(binStr)] != ""){                           //WARNING: This may be a bit dangerous. Every time when format is not found a new element in std::map is being created. It can easlily cause errors!
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