//
// Created by Dmitry Morozov on 19/10/22.
//

#ifndef LEVELUP_TODO_KATERIN_MAIN_DB_HPP
#define LEVELUP_TODO_KATERIN_MAIN_DB_HPP

#include <sqlite3.h>
#include <string>

class DB {
public:
    DB();

    ~DB();


private:
    std::string db_path = "../db/todo.db";

    sqlite3 *db_handler;

    void closeDB();

    void initDB();

    bool isDBExist();

    sqlite3 *openDB();

};


#endif //LEVELUP_TODO_KATERIN_MAIN_DB_HPP
