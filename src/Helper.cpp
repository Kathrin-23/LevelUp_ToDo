//
// Created by Dmitry Morozov on 20/10/22.
//

#include "Helper.hpp"

std::string getDateToStr(time_t now) {

    struct tm *now_tm = localtime(&now);
    char date[20];
    strftime(date, 20, "%Y-%m-%d", now_tm);

    return date;
}
