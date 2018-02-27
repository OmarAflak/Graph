#ifndef UTILS
#define UTILS

#include <sstream>

static int toInt(std::string str){
    std::stringstream ss(str);
    int n;
    ss >> n;
    return n;
}

#endif
