//
// Created by Dmitry Morozov on 19/10/22.
//

#include "Db.hpp"

#include <iostream>

DB::DB() {

    std::cout << "DB Constructor is running" << std::endl;
    db_handler = openDB();
    if (!isDBExist()) {
        std::cout << " DB Not Found. Create a new one." << std::endl;
        createDB();
    }
}

DB::~DB() {

    std::cout << " DB Destructor running" << std::endl;


}

void DB::closeDB() {

    std::cout << "Closing DB " << std::endl;
    sqlite3_close(db_handler);

}

void DB::createDB() {

    std::cout << "Creating new DB" << std::endl;

    std::string SQL_request = "create table todo("
                              "id integer primary key,"
                              "created datetime, "
                              "todo_text text, "
                              "isCompleted boolean ); ";

    char *Errmsg = nullptr;

    int result = sqlite3_exec(db_handler, SQL_request.c_str(), nullptr, nullptr, &Errmsg);

    if (result != SQLITE_OK) {
        std::cerr << "SQL error " << Errmsg << std::endl;
        sqlite3_free(Errmsg);
    } else {
        std::cout << "DB is created. " << std::endl;
    }


}

bool DB::isDBExist() {

    std::cout << "Check that DB Exists " << std::endl;
    return false;
}

sqlite3 *DB::openDB() {

    sqlite3 *db;
    int result = sqlite3_open(db_path.c_str(), &db);

    if (result) {
        std::cerr << "Can't open DataBase : " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        exit(1);
    }

    return db;
}

void DB::insert(std::string &table, const DB::Sql_raw &data) {

    std::string SQL_request = "insert into " + table + " (";

    for (auto &[column, value]: data) {
        SQL_request += column + ", ";
    }

    SQL_request.pop_back();
    SQL_request.pop_back();

    SQL_request += ") values ('";

    for (auto &item: data) {
        SQL_request += item.second + "','";
    }
    SQL_request.pop_back();
    SQL_request.pop_back();

    SQL_request += ");";

    char *ErrorMsg = nullptr;
    int result = sqlite3_exec(db_handler, SQL_request.c_str(), nullptr, nullptr, &ErrorMsg);

    if (result != SQLITE_OK) {
        std::cerr << "SQLITE INSERT ERROR : " << ErrorMsg << std::endl;
        sqlite3_free(ErrorMsg);
    } else {
        std::cout << "New TODO ADDED! " << std::endl;
    }

}

