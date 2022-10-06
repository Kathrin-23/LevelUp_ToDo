//
// Created by Dmitry Morozov on 6/10/22.
//

#include "main.hpp"
#include "commands.hpp"

#include <iostream>

int main(int argc, char *argv[]) {

//    std::cout << "argc: " << argc << std::endl;
//
//    for (int i = 0; i < argc; ++i) {
//        std::cout << i << " : " << argv[i] << std::endl;
//    }

    if (argc < 2) {
        std::cout << "Usage : " << argv[0] << " <command> " << " [Options]" << std::endl;
        return 1;
    }

    std::string command = argv[1];

    if (command == "add") {
        add_todo();
    } else if (command == "edit") {
        edit_todo();
    } else if (command == "del") {
        del_todo();
    } else if (command == "list") {
        list_todo();
    } else {
        std::cout << "Command not found ! " << std::endl;
        return 1;
    }

    std::cout << "Given Command :  " << command << std::endl;

    return 0;
}
