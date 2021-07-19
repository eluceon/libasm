#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>


size_t ft_strlen(const char *s);
char *ft_strcpy(char *dest, const char *src);
int ft_strcmp(const char *s1, const char *s2);
ssize_t ft_write(int fd, const void *buf, size_t count);
ssize_t ft_read(int fd, void *buf, size_t count);
char *ft_strdup(const char *s);

void check_strlen()
{
	char *empty = "";
	char *hello_world = "Hello world !";
	char *alphabet = "abcdefghijklmnopqrstuvwxyz";

	printf("\n================================\n");
	printf("========== FT_STRLEN ===========\n");
	printf("================================\n\n");
	printf("%-20s: \"%s\"\n", "char *", empty);
	printf("%-20s: 0\n", "expected lenght");
	printf("%-20s: %zu\n", "libc", strlen(empty));
	printf("%-20s: %zu\n", "libasm", ft_strlen(empty));
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", hello_world);
	printf("%-20s: 0\n", "expected lenght");
	printf("%-20s: %zu\n", "libc", strlen(hello_world));
	printf("%-20s: %zu\n", "libasm", ft_strlen(hello_world));
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", alphabet);
	printf("%-20s: 0\n", "expected lenght");
	printf("%-20s: %zu\n", "libc", strlen(alphabet));
	printf("%-20s: %zu\n", "libasm", ft_strlen(alphabet));
	printf("\n");

	// ------- NULL = SEGFAULT
	// printf("%-20s: \"%s\"\n", "char *", alphabet);
	// printf("%-20s: 0\n", "expected lenght");
	// printf("%-20s: %zu\n", "libc", strlen(NULL));
	// printf("%-20s: %zu\n", "libasm", ft_strlen(NULL));
	// printf("\n");
}

void clear_buffer(char *buffer, int size)
{
	int i = 0;
	while (i < size)
		buffer[i++] = 0;
}

void check_strcpy()
{
	char buffer[30];

	char *empty = "";
	char *hello_world = "Hello world !";
	char *alphabet = "abcdefghijklmnopqrstuvwxyz";

	printf("\n================================\n");
	printf("========== FT_STRCPY ===========\n");
	printf("================================\n\n");
	printf("%-20s: \"%s\"\n", "char []", empty);
	printf("%-20s: buffer[50]\n", "copy to");
	printf("%-20s: \"%s\"\n", "libc", strcpy(buffer, empty));
	clear_buffer(buffer, 30);
	printf("%-20s: \"%s\"\n", "libasm", ft_strcpy(buffer, empty));
	clear_buffer(buffer, 30);
	printf("\n");
	printf("%-20s: \"%s\"\n", "char []", hello_world);
	printf("%-20s: buffer[50]\n", "copy to");
	printf("%-20s: \"%s\"\n", "libc", strcpy(buffer, hello_world));
	clear_buffer(buffer, 30);
	printf("%-20s: \"%s\"\n", "libasm", ft_strcpy(buffer, hello_world));
	clear_buffer(buffer, 30);
	printf("\n");
	printf("%-20s: \"%s\"\n", "char []", alphabet);
	printf("%-20s: buffer[50]\n", "copy to");
	printf("%-20s: \"%s\"\n", "libc", strcpy(buffer, alphabet));
	clear_buffer(buffer, 30);
	printf("%-20s: \"%s\"\n", "libasm", ft_strcpy(buffer, alphabet));
	clear_buffer(buffer, 30);
	printf("\n");

	// ------- NULL = SEGFAULT
	// printf("%-20s: \"%s\"\n", "char []", alphabet);
	// printf("%-20s: buffer[50]\n", "copy to");
	// printf("%-20s: \"%s\"\n", "libc", strcpy(NULL, NULL));
	// clear_buffer(buffer, 30);
	// printf("%-20s: \"%s\"\n", "libasm", ft_strcpy(NULL, NULL));
	// clear_buffer(buffer, 30);
	// printf("\n");
}

void check_strcmp()
{
	char *empty = "";
	char *hello_world = "Hello world !";
	char *hello_human = "Hello human !";
	char *hello_world2 = "Hello world !";

	printf("\n================================\n");
	printf("========== FT_STRCMP ===========\n");
	printf("================================\n\n");
	printf("%-20s: \"%s\"\n", "char *", hello_world);
	printf("%-20s: \"%s\"\n", "compared to", hello_human);
	printf("%-20s: \"%d\"\n", "libc", strcmp(hello_world, hello_human));
	printf("%-20s: \"%d\"\n", "libasm", ft_strcmp(hello_world, hello_human));
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", hello_world);
	printf("%-20s: \"%s\"\n", "compared to", hello_world2);
	printf("%-20s: \"%d\"\n", "libc", strcmp(hello_world, hello_world2));
	printf("%-20s: \"%d\"\n", "libasm", ft_strcmp(hello_world, hello_world2));
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", hello_world2);
	printf("%-20s: \"%s\"\n", "compared to", empty);
	printf("%-20s: \"%d\"\n", "libc", strcmp(hello_world2, empty));
	printf("%-20s: \"%d\"\n", "libasm", ft_strcmp(hello_world2, empty));
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", "hello_human");
	printf("%-20s: \"%s\"\n", "compared to", "hello_xorld");
	printf("%-20s: \"%d\"\n", "libc", strcmp("hello_human", "hello_xorld"));
	printf("%-20s: \"%d\"\n", "libasm", ft_strcmp("hello_human", "hello_xorld"));
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", "hell");
	printf("%-20s: \"%s\"\n", "compared to", "hello_xorld");
	printf("%-20s: \"%d\"\n", "libc", strcmp("hell", "hello_xorld"));
	printf("%-20s: \"%d\"\n", "libasm", ft_strcmp("hell", "hello_xorld"));
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", "hello_xorld");
	printf("%-20s: \"%s\"\n", "compared to", "hell");
	printf("%-20s: \"%d\"\n", "libc", strcmp("hello_xorld", "hell"));
	printf("%-20s: \"%d\"\n", "libasm", ft_strcmp("hello_xorld", "hell"));
	printf("\n");

	// ------- NULL = SEGFAULT
	// printf("%-20s: \"%s\"\n", "char *", hello_world2);
	// printf("%-20s: %s\n", "compared to", "NULL");
	// printf("%-20s: \"%d\"\n", "libc", strcmp(NULL, hello_world2));
	// printf("%-20s: \"%d\"\n", "libasm", ft_strcmp(NULL, empty));
	// printf("\n");
}

void check_write()
{
	char *hello_world = "Coucou\n";
	char *empty = "";

	printf("\n================================\n");
	printf("========== FT_WRITE ============\n");
	printf("================================\n\n");
	printf("%-20s: \"%s\"\n", "char *", hello_world);
	printf("%-20s: \"Libc:%zu\"\n", "libc", write(1, hello_world, 7));
	// printf("\n");
	printf("%-20s: \"Libasm:%zu\"\n", "libasm", ft_write(1, hello_world, 7));
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", empty);
	printf("%-20s: \"Libc:%zu\"\n", "libc", write(1, empty, 0));
	// printf("\n");
	printf("%-20s: \"Libasm:%zu\"\n", "libasm", ft_write(1, empty, 0));


	printf("%-20s: \"%s\"\n", "char *", "#c#s#p#x#X#e#f#g");
	printf("%-20s: \"Libc:%zu\"\n", "libc", ft_write(1, "#c#s#p#x#X#e#f#g", 17));
	printf("%-20s: \"Libc:%zu\"\n", "libc", ft_write(1, "#c#s#p#x#X#e#f#g", 17));

	printf("\n");
	// printf("%-20s: \"Libasm:%zu\"\n", "libasm", ft_write(1, "#c#s#p#x#X#e#f#g", 17));

	printf("\nLibasm: Value of errno: %d\n ", errno);
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", hello_world);
	printf("%-20s: \"Libasm:%zd\"\n", "libasm", ft_write(-7, NULL, 7));
	printf("\nLibasm: Value of errno: %d\n ", errno);
	// printf("\n");
	// printf("%-20s: \"Libc:%zd\"\n", "libc", write(-7, NULL, 7));
	// printf("\nLibc: Value of errno: %d\n ", errno);
	// printf("\n");
}
void fill_zero(char	*str, int i)
{
	while (i > 0)
		str[--i] = 0;
}
void check_read()
{
	int fd = open("test.c", O_RDONLY);
	char buff1[891];
	int ret = 1;
	printf("\n================================\n");
	printf("========== FT_READ =============\n");
	printf("================================\n\n");
	printf("%-20s: \n", "header test.c | libc ");
	fill_zero(buff1, 891);
	ret = read(fd, buff1, 890);
	printf("[return : %d]\n|%s|\n", ret, buff1);
	printf("\n");
	close(fd);
	fd = open("test.c", O_RDONLY);
	clear_buffer(buff1, 891);
	printf("%-20s: \n", "header test.c | libasm ");
	fill_zero(buff1, 891);
	ret = ft_read(fd, buff1, 890);
	printf("[return : %d]\n|%s|\n", ret, buff1);
	printf("\n");
	clear_buffer(buff1, 891);
	close(fd);

	fd = open("test", O_RDONLY);
	printf("%-20s: \n", "file test | libc ");
	fill_zero(buff1, 891);
	ret = read(fd, buff1, 890);
	printf("[return : %d]\n|%s|\n", ret, buff1);
	printf("\n");
	close(fd);
	fd = open("test", O_RDONLY);
	clear_buffer(buff1, 891);
	printf("%-20s: \n", "file test | libasm ");
	fill_zero(buff1, 891);
	ret = ft_read(fd, buff1, 890);
	printf("[return : %d]\n|%s|\n", ret, buff1);
	printf("\n");
	clear_buffer(buff1, 891);
	close(fd);

	fd = open("wrong", O_RDONLY);
	printf("%-20s: \n", "wrong | libc ");
	fill_zero(buff1, 891);
	ret = read(fd, buff1, 890);
	printf("[return : %d]\n|%s|\n", ret, buff1);
	printf("\n");
	close(fd);
	fd = open("wrong", O_RDONLY);
	clear_buffer(buff1, 891);
	printf("%-20s: \n", "wrong | libasm ");
	fill_zero(buff1, 891);
	ret = ft_read(fd, buff1, 890);
	printf("\nfd = %d", ret);
	printf("[return : %d]\n|%s|\n", ret, buff1);
	printf("\n");
	clear_buffer(buff1, 891);
	printf("\nValue of errno = %d",errno);
	close(fd);
}

void check_strdup()
{
	char *hello_world = "Hello world !";
	char *empty = "";
	char *save;
	char *save2;

	printf("\n================================\n");
	printf("========== FT_STRDUP ===========\n");
	printf("================================\n\n");
	printf("%-20s: \"%s\"\n", "char *", hello_world);
	save = strdup(hello_world);
	printf("%-20s: \"%s\"\n", "libc", save);
	free(save);
	save = NULL;
	save2 = ft_strdup(hello_world);
	printf("%-20s: \"%s\"\n", "libasm", save2);
	free(save2);
	save2 = NULL;
	printf("\n");

	printf("%-20s: \"%s\"\n", "char *", empty);
	save = strdup(empty);
	printf("%-20s: \"%s\"\n", "libc", save);
	free(save);
	save = NULL;
	save2 = ft_strdup(empty);
	printf("%-20s: \"%s\"\n", "libasm", save2);
	free(save2);
	save2 = NULL;
	printf("\n");

	// ------- NULL = SEGFAULT
	// printf("%-20s: NULL\n", "char *");
	// save = strdup(NULL);
	// printf("%-20s: \"%s\"\n", "libc", save);
	// free(save);
	// save = NULL;
	// save2 = ft_strdup(NULL);
	// printf("%-20s: \"%s\"\n", "libasm", save2);
	// free(save2);
	// save2 = NULL;
	// printf("\n");
}

int	main(void)
{

	// check_strlen();
	// check_strcpy();
	// check_strcmp();
	check_write();
	// check_read();
	// check_strdup();



	return (0);
}
