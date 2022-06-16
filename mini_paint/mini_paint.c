# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>

int	ft_close(FILE *fd, int err_code);

int	WIDTH;
int	HEIGHT;
int TOTAL;
char	BACKGROUND;
char	*MAP;

int	ft_close(FILE *fd, int err_code)
{
	if (err_code == 1)
		write(1, "Error: argument\n", 16);
	else if (err_code == 2 && (err_code = 1))
		write(1, "Error: Operation file corrupted\n", 32);
	else
	{
		for (int i = 0; i < TOTAL; i++)
		{
			write(1, &MAP[i], 1);
			if ((i + 1) % WIDTH == 0 && i != 0)
				write(1, "\n", 1);
		}
	}
	if (fd)
		fclose(fd);
	return (err_code);
}

int	main(int ac, char **av)
{
	char	c_char, draw_char;
	float	x_cerc, y_cerc, radius, dist;
	int		scan_ret;
	FILE	*fd;

	fd = NULL;
	if (ac != 2)
		return ft_close(fd, 1);
	if ((fd = fopen(av[1], "r")))
	{
		if ((scan_ret = fscanf(fd, "%d %d %c ", &WIDTH, &HEIGHT, &BACKGROUND)) == 3)
		{
			if (WIDTH > 0 && WIDTH <= 300 && HEIGHT > 0 && HEIGHT <= 300)
			{
				TOTAL = HEIGHT * WIDTH;
				MAP = malloc(sizeof(char) * TOTAL);
				memset(MAP, BACKGROUND, TOTAL);
                while(1)
                {
                    scan_ret = fscanf(fd, "\n%c %f %f %f %c", &c_char, &x_cerc, &y_cerc, &radius, &draw_char);
                    if (scan_ret == -1)
                        return(ft_close(fd, 0)); //success
                    if (scan_ret != 5 || radius <= 0 || (c_char != 'c' && c_char != 'C'))
                        break;
                    for (int y = 0; y < HEIGHT; y++)
                    {
                        for (int x = 0; x < WIDTH; x++)
                        {
                            dist = sqrt(powf(x - x_cerc, 2) + powf(y - y_cerc, 2));
                            if (dist <= radius)
                                if (c_char == 'C' || (dist + 1 > radius))
                                    MAP[y * WIDTH + x] = draw_char;
                        }
                    }
                }
            }
		}
	}
	return (ft_close(fd, 2));
}
