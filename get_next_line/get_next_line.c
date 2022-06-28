#include "get_next_line.h"

char *ft_strdup(char *str)
{
    int len = 0;
    while (str[len])
        len++;
    char *new_str = malloc(sizeof(char) * (len + 1));
    if (!new_str)
        return (0);
    int i = -1;
    while (++i < len)
        new_str[i] = str[i];
    new_str[i] = 0;
    return (new_str);
}

char* get_next_line(int fd) {
    char heap[6000000] = {0};
    char buff;
    int nbyte = 0;
    int i = 0;
    if (fd < 0)
        return (0);
    while ((nbyte = read(fd, &read, 1)) &&  nbyte > 0 ) {
        heap[i++] = buff;
        if (buff == '\n')
            break ;
    }
    heap[i] = '\0';
    if (nbyte <= 0 && i == 0)
        return (0);
    return ft_strdup(heap);
}