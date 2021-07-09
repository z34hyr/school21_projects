#pragma once

#include <cstring>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <sstream>
#include <utility>

#include "get_next_line.hpp"
#include "webserv.hpp"

/*
Name            FG  BG
Black           30  40
Red             31  41
Green           32  42
Yellow          33  43
Blue            34  44
Magenta         35  45
Cyan            36  46
White           37  47
Bright Black    90  100
Bright Red      91  101
Bright Green    92  102
Bright Yellow   93  103
Bright Blue     94  104
Bright Magenta  95  105
Bright Cyan     96  106
Bright White    97  107
*/

#define CYAN  "\033[36m" // Cyan
#define GREEN   "\033[32m" // Green
#define YELLOW "\033[33m" // Yellow
#define WHITE "\033[37m" // White
#define RED "\033[31m" // Red
#define RESET   "\033[0m"

static size_t line_counter = 0;
static char default_path[] = "config_parser/default.config";

inline std::vector<std::string> newSplitByDelimeter(std::string buffer, const char *delimeters)
{
    std::vector<std::string> lines;

    char char_req[buffer.length()];
    char *ptr = NULL;
    strcpy(char_req, buffer.c_str());
    ptr = strtok(char_req, delimeters);
	if (ptr)
    	lines.push_back(std::string(ptr));
    while((ptr = strtok(0, delimeters)))
	{
		if (ptr)
        	lines.push_back(std::string(ptr));
	}
    if (ptr)
        delete[] ptr;
    return lines;
}