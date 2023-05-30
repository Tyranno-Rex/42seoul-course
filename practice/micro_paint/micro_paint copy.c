#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ARG "argument"
#define CORRUPT "Operation file corrupted"

int ft_error(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	write(1, "Error: ", 7);
	write(1, str, i);
	write(1, "\n", 1);
	return (1);
}

int ft_draw(char *buff, int width, int height)
{
	for (int Y = 0; Y < height; Y++)
	{
		write(1, buff + (Y * width), width);
		write(1, "\n", 1);
	}
	return (0);
}

int ft_is_in_rect(float x, float y, float rect_x, float rect_y, float rect_width, float rect_height)
{
	if ((((x < rect_x) || (rect_x + rect_width < x)) || (y < rect_y)) || (rect_y + rect_height < y))
		return (0);
	if (((x - rect_x < 1.00000000) || ((rect_x + rect_width) - x < 1.00000000)) ||
		((y - rect_y < 1.00000000 || ((rect_y + rect_height) - y < 1.00000000))))
		return (2); 
	return (1); 
}

int main(int argc, char **argv)
{
	FILE *file;
	int width, height, ret; 
	char background, c, drawchar; 
	float Xtop, Ytop, Xcheck, Ycheck, fwidth, fheight;

	if (argc != 2)
		return (ft_error(ARG));
	if (!(file = fopen(argv[1], "r")))
		return (ft_error(CORRUPT));
	if ((fscanf(file, "%d %d %c", &width, &height, &background)) != 3)
		return (ft_error(CORRUPT));
	if (!(width > 0 && width <= 300) || !(height > 0 && height <= 300))
		return (ft_error(CORRUPT));

	char buff[(width * height)]; 
	for (int XY = 0; XY < (width * height); XY++)
		buff[XY] = background;
	
	fscanf(file, "%c %f %f %f %f %c", &c, &Xtop, &Ytop, &fwidth, &fheight, &drawchar);
	while ((ret = fscanf(file, "%c %f %f %f %f %c", &c, &Xtop, &Ytop, &fwidth, &fheight, &drawchar)) == 6)
	{
		if ((c != 'r' && c != 'R'))
			return (ft_error(CORRUPT));
		for(int Y = 0; Y < height; Y++)
		{
			Ycheck = (float)Y; 
			for(int X = 0; X < width; X++)
			{
				Xcheck = (float)X;
				if ((ft_is_in_rect(Xcheck, Ycheck, Xtop, Ytop, fwidth, fheight) == 2) || (ft_is_in_rect(Xcheck, Ycheck, Xtop, Ytop, fwidth, fheight) == 1 && (c == 'R')))
						buff[(Y * width) + X] = drawchar;
			}
		}
		fscanf(file, "%c %f %f %f %f %c", &c, &Xtop, &Ytop, &fwidth, &fheight, &drawchar);
	}
	if (ret != -1) 
		return (ft_error(CORRUPT));
	return (ft_draw(buff, width, height));
}