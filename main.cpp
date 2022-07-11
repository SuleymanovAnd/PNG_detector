#include <iostream>
#include <fstream>

int main() {
    std::cout << "Enter the path to the file:" << std::endl;
    std::string path;
    std::getline (std::cin,path);
    std::ifstream file;

    file.open (path, std::ios::binary);
    while (!file.is_open()){
        std::cout << "Enter the correct path to the file:" << std::endl;
        std::getline (std::cin,path);
        file.open (path, std::ios::binary);
    }

    if (path.substr (path.size()-3,3) == "png"||path.substr (path.size()-3,3) == "PNG") {
        char buffer [4];
        file.read (buffer,4);
        bool isPng = true;
        if (buffer[0] != -119 && buffer [1] != 'P'&& buffer[2]!= 'N'&& buffer[3] != 'G'){isPng = false;}
        if (isPng) {std::cout <<"File is PNG!!!" << std::endl;}
        else {std::cout << "File is NOT - PNG"<< std::endl;}
    }else {
        std::cout << "file is NOT - PNG"<< std::endl;
    }
    file.close();
}
