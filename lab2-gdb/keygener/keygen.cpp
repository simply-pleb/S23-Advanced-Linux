#include <iostream>
#include "md5.h"

int main(){
    
    std::string hwid;

    std::cout << "input your HWID: ";
    std::cin >> hwid;  
    
    auto encrypted = md5(hwid);
    char key[80];

    for(int i=0; i<16; i++){
        // sprintf(key + i*2, "%02x",(ulong)(char)encrypted[15 - i]);
        sprintf(key + i*2, "%c%c", encrypted[31 - i*2-1], encrypted[31 - i*2]);
    } 

    std::cout << "key: " << key << std::endl;
}