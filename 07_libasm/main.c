#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <error.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dest, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t ft_read(int fd, void *buf, size_t count);
ssize_t ft_write(int fd, const void *buf, size_t count);
char	*ft_strdup(const char *s);

void colored_printf(char *str)
{
	printf("\033[0;32m");
	printf("%s\n", str);
	printf("\033[0m");
}

void test_strlen(char *str)
{
	int i=0;
	int j=0;

	printf("	===call of test_strlen===\n");
	i = ft_strlen(str);
	j = strlen(str);
	printf("%d - res of my strlen\n%d - res of std function\n", i, j);
}

void test_strcpy(char *str)
{
	int i=0;
	char *z, *y;

	printf("	===call of test_strcpy===\n");
	z = (char*)malloc(sizeof(char) * (strlen(str) + 1));
	y = (char*)malloc(sizeof(char) * (strlen(str) + 1));
	z = ft_strcpy(z, str);
	y = strcpy(y, str);
	i = strcmp(z, y);
	printf("difference btw ft_strcpy & strcpy: %d\n", i);
	free(z);
	free(y);
}

void test_strcmp(char *s1, char *s2)
{
	int i=0;
	int j=0;

	printf("	===call of test_strcmp===\n");
	i = ft_strcmp(s1, s2);
	j = strcmp(s1,s2);
	printf("%-10d - result of ft_strcmp\n", i);
	printf("%-10d - result of strcmp\n\n", j);
}

void test_write(int fd1, int fd2, char *str, int count)
{
	int i;
	int j;

	printf("	===call of test_write===\n");
	errno = 0;
	i = ft_write(fd1,str,count);
	printf("%d - result of ft_write\n%s\n", i, strerror(errno));
	errno = 0;
	j = write(fd2,str,count);
	printf("%d - result of write\n%s\n\n", j, strerror(errno));
}

void test_file_read(char *file_name)
{
	int i;
	int j;
	int k=0;
	int fd1;
	char s1[2000];
	char s2[2000];

	printf("	===call of test_file_read===\n");
	fd1 = open(file_name, O_RDONLY);
	errno = 0;
	i = ft_read(fd1,s1,2000);
	s1[i] = '\0';
	printf("%d - result of ft_read\n%s\n", i, strerror(errno));
	close(fd1);
	fd1 = open(file_name, O_RDONLY);
	errno = 0;
	j = read(fd1,s2,2000);
	s2[j] = '\0';
	printf("%d - result of read\n%s\n\n", j, strerror(errno));
	close(fd1);
	if (!errno && i == j)
	{
		k = strncmp(s1,s2,i);
		printf("%d - result of strcmp s1 & s2\n",k);
	}
}

void test_stdin(void)
{
	int i=0;
	int j=0;
	char s1[2000];
	char s2[2000];

	printf("	===call of test_stdin===\n");
	i = ft_read(0,s1,2000);
	write(1, s1, i);
}

void test_strdup(char *str)
{
	char *dest;
	char *std_dest;
	char *std_new_str;

	std_new_str = (char*)malloc(sizeof(char) * (strlen(str) + 1));
	std_new_str = strcpy(std_new_str,str);
	dest = ft_strdup(std_new_str);
	std_dest = strdup(std_new_str);
	free(std_new_str);
	printf("src is freed, dest:\n%s\n", dest);
	printf("\n%d - result of strcmp s1 & s2\n",strcmp(dest,std_dest));
}

int	main(void)
{
	char a[] = "";
	char b[] = "abcdefghijklmnopqrstuvwxyz123456789[]/!@#$^%&*()abcdefghijklmnopqrstuvwxyz123456789[]/!@#$^%&*()abcdefghijklmnopqrstuvwxyz123456789[]/!@#$^%&*()abcdefghijklmnopqrstuvwxyz123456789[]/!@#$^%&*()abcdefghijklmnopqrstuvwxyz123456789[]/!@#$^%&*()abcdefghijklmnopqrstuvwxyz123456789[]/!@#$^%&*()abcdefghijklmnopqrstuvwxyz123456789[]/!@#$^%&*()abcdefghijklmnopqrstuvwxyz123456789[]/!@#$^%&*()abcdefghijklmnopqrstuvwxyz123456789[]/!@#$^%&*()abcdefghijklmnopqrstuvwxyz123456789[]/!@#$^%&*()abcdefghijklmnopqrstuvwxyz123456789[]/!@#$^%&*()abcdefghijklmnopqrstuvwxyz123456789[]/!@#$^%&*()abcdefghijklmnopqrstuvwxyz123456789[]/!@#$^%&*()abcdefghijklmnopqrstuvwxyz123456789[]/!@#$^%&*()abcdefghijklmnopqrstuvwxyz123456789[]/!@#$^%&*()abcdefghijklmnopqrstuvwxyz123456789[]/!@#$^%&*()abcdefghijklmnopqrstuvwxyz123456789[]/!@#$^%&*()abcdefghijklmnopqrstuvwxyz123456789[]/!@#$^%&*()abcdefghijklmnopqrstuvwxyz123456789[]/!@#$^%&*()abcdefghijklmnopqrstuvwxyz123456789[]/!@#$^%&*()abcdefghijklmnopqrstuvwxyz123456789[]/!@#$^%&*()";
	char b1[] = "abcdefghijklmnopqrstuvwxyz123456789[]/!@#$^%&*()abcdefghijklmnopqrstuvwxyz123456789[]/!@#$^%&*()abcdefghijklmnopqrstuvwxyz123456789[]/!@#$^%&*()abcdefghijklmnopqrstuvwxyz123456789[]/!@#$^%&*()abcdefghijklmnopqrstuvwxyz123456789[]/!@#$^%&*()abcdefghijklmnopqrstuvwxyz123456789[]/!@#$^%&*()abcdefghijklmnopqrstuvwxyz123456789[]/!@#$^%&*()abcdefghijklmnopqrstuvwxyz123456789[]/!@#$^%&*()abcdefghijklmnopqrstuvwxyz123456789[]/!@#$^%&*()abcdefghijklmnopqrstuvwxyz123456789[]/!@#$^%&*()abcdefghijklmnopqrstuvwxyz123456789[]/!@#$^%&*()abcdefghijklmnopqrstuvwxyz123456789[]/!@#$^%&*()abcdefghijklmnopqrstuvwxyz123456789[]/!@#$^%&*()abcdefghijklmnopqrstuvwxyz123456789[]/!@#$^%&*()abcdefghijklmnopqrstuvwxyz123456789[]/!@#$^%&*()abcdefghijklmnopqrstuvwxyz123456789[]/!@#$^%&*()abcdefghijklmnopqrstuvwxyz123456789[]/!@#$^%&*()abcdefghijklmnopqrstuvwxyz123456789[]/!@#$^%&*()abcdefghijklmnopqrstuvwxyz123456789[]/!@#$^%&*()abcdefghijklmnopqrstuvwxyz123456789[]/!@#$^%&*()abcdefghijklmnopqrstuvwxyz123456789[]/!@#$^%&*()";
	char eq[] = "aaa";
	char a1[] = "";
	char a2[] = "a";

	char fixed_str[] = "Hello my friend!";
	int fd1,fd2,fd3;
	char *my_new_str;
	char *std_new_str;

	/*test ft_strlen*/
	colored_printf("==ft_strlen==");
	test_strlen(a);
	test_strlen(b);
	/*test ft_strcpy*/
	colored_printf("==ft_strcpy==");
	test_strcpy(a);
	test_strcpy(b);
	/*test ft_strcmp*/
	colored_printf("==ft_strcmp==");
	test_strcmp(b,b1);
	test_strcmp(a,a1);
	test_strcmp(a,b1);
	test_strcmp(eq,b1);
	test_strcmp(b1,eq);
	/*test ft_write*/
	colored_printf("==ft_write==");
	fd1 = open("test.txt", O_CREAT | O_WRONLY, S_IREAD|S_IWRITE);
	fd2 = open("wrong_test.txt", O_WRONLY);
	fd3 = open("test.txt", O_RDONLY);
	test_write(fd1,fd1,b,strlen(b));
	test_write(fd2,fd2,"test_string\n",12);
	test_write(fd2,fd2,"cantwrite\n",10);
	test_write(1,1,"hello\n",7);
	test_write(55,55,"hello\n",7);
	close(fd1);
	/*test ft_strdup*/
	colored_printf("==ft_strdup==");
	test_strdup(b);
	test_strdup("");
	/*test ft_read*/
	colored_printf("==ft_read==");
	test_file_read("test.txt");
	test_file_read("some_strange.txt");
	test_stdin();
}
