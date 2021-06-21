
#include "get_next_line.h"
#include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int   main(int argc, char* argv[])
{
  char  *line;
  int   fd1;
  int   fd2;
	int i;

	i = argc;
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
	while ((i = get_next_line(fd1, &line)) > 0)
	{
		printf("|%s\n", line);
		free(line);
		get_next_line(fd2, &line);
		printf("|%s\n", line);
		free(line);
	}
	printf("|%s\n", line);
	free(line);
	close(fd1);
	close(fd2);
	return (0);
}
