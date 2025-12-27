#include <iostream>
#include <fstream>

int main(){
    std::ifstream is("testimage.jpg", std::ios::binary);
    int length = 10;

    //TODO: Implement conversion from bytes to hexadecimal numbers 

    if (is) {
        std::cout << "opened the file successfully" << std::endl;
        char * buffer = new char[length]; //Raw bytes are being stored here
        is.read(buffer, length);
        std::cout << buffer; //If the bytes are not converted to hexadecimal, this will output ASCII nonsense
    }
    else{
        std::cout << "failed to open the file!" << std::endl;
    }

    return 0;
}