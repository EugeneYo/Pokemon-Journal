#ifndef COLOR_H
#define COLOR_H

#include <iostream>

#include <windows.h>
#include <color.h>

static HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

void printColor(std::string str, int k);

#endif
