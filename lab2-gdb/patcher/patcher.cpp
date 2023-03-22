#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    std::string path;
    if (argc > 1){
        path = argv[1];
    }
    else{
        path = "hack_app";
    }
    // Open the binary file
    std::fstream file(path, std::ios::in | std::ios::out | std::ios::binary);

    if (!file)
    {
        // Handle error
        printf("Your file does not exist!\n");
        return 1;
    }

    // Seek to the position of the byte you want to change
    file.seekg(0x159e);
    char buf[5];

    file.read(buf, 1);
    // std::cout << std::hex << (int)buf[0] << std::endl;

    if (buf[0] == (char)0x74){
        printf("Your binary was already patched.\n");
        return 0;
    }


    // Write the new byte value
    file.seekp(0x159e);
    char new_byte = (char) 0x74;
    file.write(&new_byte, 1);

    // Close the file
    file.close();

    printf("You binary was patched. Enjoy using the program.\n");

    return 0;
}