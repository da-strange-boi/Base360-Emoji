#ifndef BASE360_H
#define BASE360_H

#include <string>

std::string base360_encode(int number);
int         base360_decode(std::string base360);
void        base360_init();

#endif