#include <stdio.h>
#include "get_next_line.h"

void DumpHex(const void* data, size_t size) 
{
	char ascii[17];
	size_t i, j;
	ascii[16] = '\0';
	for (i = 0; i < size; ++i) {
		printf("%02X ", ((unsigned char*)data)[i]);
		if (((unsigned char*)data)[i] >= ' ' && ((unsigned char*)data)[i] <= '~') {
			ascii[i % 16] = ((unsigned char*)data)[i];
		} else {
			ascii[i % 16] = '.';
		}
		if ((i+1) % 8 == 0 || i+1 == size) {
			printf(" ");
			if ((i+1) % 16 == 0) {
				printf("|  %s \n", ascii);
			} else if (i+1 == size) {
				ascii[(i+1) % 16] = '\0';
				if ((i+1) % 16 <= 8) {
					printf(" ");
				}
				for (j = (i+1) % 16; j < 16; ++j) {
					printf("   ");
				}
				printf("|  %s \n", ascii);
			}
		}
	}
}

int	main(void)
{
	char	*z;
	int		fd;
	int		result;
	int		i;

	result = -2;
	i = 0;
	printf("going into get_next_line function\n");
	fd = open("./test_files/test_empty.txt", O_RDONLY);
	//fd = -1;
	while (1)
	{
		result = get_next_line(fd, &z);
		printf("ret_res = %d, STRING #%d:\n", result, i + 1);
		printf("\033[0;32m");
		printf("%s", z);
		printf("\033[0m");
		if (result >= 0)
		{
			free(z);
			z = NULL;
		}
		if (result == 0 || result == -1)
			break ;
		i += 1;
	}
}
