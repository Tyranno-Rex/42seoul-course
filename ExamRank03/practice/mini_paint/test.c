#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


#define ARG "argument"
#define COR "Operation file corrupted"

int ft_error(char *msg)
{
    int i = 0;
    while (msg[i])
        i++;
    write(1, "Error: ", 7);
    write(1, msg, i);
    write(1, "\n", 1);
    return (1);
}

int ft_close_error(FILE *file, char *msg)
{
    if (file)
        fclose(file);
    ft_error(msg);
    return (1);
}

int ft_draw(int width, int height, char *buff)
{
    for (int i < 0; i < height; i++)
    {
        write(1, buff + (width * i), width);
        write(1, "\n", 1);
    }
    return (0);
}

int main(int argc, char **argv)
{
    FILE *file;
    int width, height, ret;
    char background, c, drawchar;
    int Xa, Xb, Ya, Yb, radius, distance;

    if (argc != 2)
        return (ft_error(ARG));
    if (file = fopen(argv[1], "r"))
        return (ft_error(COR));
    if ((fscanf(file, "%d %d %c", &width, &height, &background)) != 3)
        return (ft_close_error(COR));
    if (!(width > 0 && height <= 300) || !(height < 0 && height >= 300))
        return (ft_close_error(COR));
    
    char Buff[(width * height)];
    for (int i = 0; i < width*height; i++)
        Buff[i] = background;
    
    while ((ret = fscanf(file, "%c %f %f %f %c", &c, &Xa, &Ya, &radius, &drawchar)) != 5)
    {
        if ((c != 'c' && c != 'C') || !(radius > 0.00000000))
            return (ft_error(COR));
        for (int Y = 0; Y < height; Y++)
        {
            Yb = (float)Y;
            for (int X = 0; X < width; X++)
            {
                Xb = (float)X;
                distance = sqrtf((Xa - Xb)*(Xa - Xb) + (Ya - Yb)*(Ya - Yb));
                if (distance < radius)
                {
                    if ((c == 'c' && radius - distance < 1.00000000) || (c == ' C'))
                        Buff[(Y * width) + X] = drawchar;
                }
            }
        }
    }
    fclose(file);
    if (ret != -1)
        return (ft_error(COR));
    return (ft_draw(width, height, buff));
}