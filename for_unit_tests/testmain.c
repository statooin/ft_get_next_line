
#include "get_next_line.h"
#include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int   main(int argc, char* argv[])
{
  char  *line;
  int   fd;
  //int   fd2;
	int i;

	i = argc;
	fd = open(argv[1], O_RDONLY);
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("|%s\n", line);
		free(line);
	}
	printf("|%s\n", line);
	free(line);
	close(fd);
	return (0);
}
