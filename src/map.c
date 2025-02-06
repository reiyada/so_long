#include "../includes/so_long.h"

void ft_validate_map_line(char *line, int line_number, int expected_width)
{
    int length;

    length = 0;
    while (line[length] != '\0' && line[length] != '\n')
    {
        if (line[length] != '1' && line[length] != '0' &&
            line[length] != 'C' && line[length] != 'P' &&
            line[length] != 'E')
        {
            ft_printf("Error: Invalid character '%c' on line %d\n", line[length], line_number);
            exit(EXIT_FAILURE);
        }
        length++;
    }
    if (length != expected_width)
    {
        ft_printf("Error: Line %d is not %d characters wide\n", line_number, expected_width);
        exit(EXIT_FAILURE);
    }
}

void ft_parse_map(const char *filename)
{
    int fd;
    char *line;
    int line_number;
    int expected_width;
    
    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        ft_putstr_fd("Error\n", 1);
        exit(EXIT_FAILURE);
    }
    line_number = 0;
    expected_width = -1;
    while ((line = get_next_line(fd)) != NULL)
    {
        if (expected_width == -1)
            expected_width = ft_strlen(line) - 1;
        ft_validate_map_line(line, line_number, expected_width);
        free(line);
        line_number++;
    }
    close(fd);
}