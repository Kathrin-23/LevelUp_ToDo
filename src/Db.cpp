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
        initDB();
    }
}

DB::~DB() {

    std::cout << " DB Destructor running" << std::endl;


}

void DB::closeDB() {

    std::cout << "Closing DB " << std::endl;
    sqlite3_close(db_handler);

}

void DB::initDB() {

    std::cout << "Creating new DB" << std::endl;

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

