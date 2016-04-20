#include "minishell.h"

void	ff()
{
	printf("hahah\n");
}

int main()
{
	int fd;

	fd = open("xx", O_WRONLY, S_IRWXU);
	dup2(fd, 1);
	close(fd);

	ff();
	return (0);
}
