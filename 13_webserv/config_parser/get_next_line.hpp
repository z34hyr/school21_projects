#pragma once

#include <cstring>
#include <fcntl.h>
#include <iostream>
#include <string>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#define GNL_BUF_SIZE 10000

size_t	ft_strlen(const char *s);
int		fget_next_line(int fd, char *buff, char **line, char *temp_line);