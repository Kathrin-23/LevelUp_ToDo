//
// Created by Dmitry Morozov on 6/10/22.
//

#include "commands.hpp"

#include <sqlite3.h>

#include <iostream>

void add_todo() {

    std::cout << " I'm adding new TODO ! " << std::endl;
}

void edit_todo() {

    std::cout << "I'm editing TODO " << std::endl;
}

void del_todo() {

    std::cout << "I'm deleting TODO " << std::endl;
}

void list_todo() {

    std::cout << "Showing TODO list " << std::endl;
}

void size_todo() {

    std::cout << " We have 5 TODO" << std::endl;
}

