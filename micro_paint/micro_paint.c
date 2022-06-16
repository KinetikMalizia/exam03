#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int	WIDTH, HEIGHT;
char	BACKGROUND;
char	*MAP;

typedef struct

int	ft_close(FILE *fd, int errcode)
{
	if (errcode == 1)
		write(1, "Error: argument\n", 13);
	else if (errcode == 2 && (errcode = 1))
		write(1, "Error: Operation file corrupted \n", 32);
	else
	{
		for (int i = 0; i < TOTAL; i++)
		{
			write(1, &MAP[i], 1);
			if((i + 1) % WIDTH == 0 && i != 0)
				write(1, "\n", 1);
		}
	}
	if (fd)
		fclose(fd);
	return (errcode);
}