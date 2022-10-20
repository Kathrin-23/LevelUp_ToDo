//
// Created by Dmitry Morozov on 19/10/22.
//

#ifndef LEVELUP_TODO_KATERIN_MAIN_DB_HPP
#define LEVELUP_TODO_KATERIN_MAIN_DB_HPP

#include <map>
#include <sqlite3.h>
#include <string>

class DB {
public:

    DB();
    ~DB();

    using Sql_raw = std::map <std::string, std::string>;


private:
    std::string db_path = "../db/todo.db";

    sqlite3 *db_handler;

    void createDB();

    void closeDB();

    void insert(std::string &,const  Sql_raw& );

    bool isDBExist();

    sqlite3 *openDB();

};


#endif //LEVELUP_TODO_KATERIN_MAIN_DB_HPP
