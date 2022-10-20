//
// Created by Dmitry Morozov on 6/10/22.
//
//FIXME: CMake sqlite lib path : C:\sqlite
#include "commands.hpp"
#include "Db.hpp"
#include "Helper.hpp"

#include <sqlite3.h>
#include <iostream>

struct TODO {
    int id;
    char date[20];
    std::string text;
    bool is_completed;
};


void add_todo(std::string new_todo) {

    std::cout << " I'm adding new TODO ! " << std::endl;
    DB db_handler;
    std::string table = "todo";

    DB::Sql_raw new_todo_raw = {
            {"created",     getDateToStr(time(nullptr))},
            {"todo_text",   new_todo},
            {"isCompleted", "false"}
    };

    //Debug only! Remove this!
    std::cout << " New todo : " << std::endl;

    for (auto &[column, value]: new_todo_raw) {
        std::cout << "Column : " << column << " : " << value << std::endl;
    }

    db_handler.insert(table, new_todo_raw);

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

