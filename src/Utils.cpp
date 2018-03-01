#include "../include/Utils.h"

int toInt(std::string str){
    std::stringstream ss(str);
    int n;
    ss >> n;
    return n;
}
