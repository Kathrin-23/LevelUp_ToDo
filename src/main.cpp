//
// Created by Dmitry Morozov on 6/10/22.
//

#include "main.hpp"
#include "commands.hpp"
#include "Db.hpp"

#include <iostream>
#include <map>

int main(int argc, char *argv[]) {
    std::map<std::string, void (*)()> command_handler = {
            {"add",  add_todo},
            {"list", list_todo},
            {"del",  del_todo},
            {"edit", edit_todo},
            {"size" , size_todo}
    };

    DB todo_db;


    if (argc < 2) {
        std::cout << "Usage : " << argv[0] << " <command> " << " [Options]" << std::endl;
        return 1;
    }

    std::string command = argv[1];

    if ( command_handler.find(command) != command_handler.end() ){
        command_handler[command]();
    } else {
        std::cout << "Unknown command ! " << std::endl;
    }

    return 0;
}
