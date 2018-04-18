#ifndef UTILS
#define UTILS

#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>

void initRand();
int genNumber(int min, int max);
std::string genUid(int length=15);
int toInt(std::string str);

#endif
