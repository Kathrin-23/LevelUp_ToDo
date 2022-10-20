//
// Created by Dmitry Morozov on 6/10/22.
//

#include "main.hpp"
#include "commands.hpp"
#include "Db.hpp"

#include <iostream>
#include <map>

int main(int argc, char *argv[]) {
    std::map<std::string, void (*)( std::string)> command_handler = {
            {"add",  add_todo},
//            {"list", list_todo},
//            {"del",  del_todo},
//            {"edit", edit_todo},
//            {"size" , size_todo}
    };



    if (argc < 2) {
        std::cout << "Usage : " << argv[0] << " <command> " << " [Options]" << std::endl;
        return 1;
    }

    std::string command = argv[1];

    std::string argument ;

    for ( int i = 2; i < argc; ++i){
        argument += argv[i] ;
        argument += " ";
    }

    argument.pop_back();


    if ( command_handler.find(command) != command_handler.end() ){
        command_handler[command]( argument);
    } else {
        std::cout << "Unknown command ! " << std::endl;
    }

    return 0;
}
