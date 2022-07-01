#include "get_next_line.h"

char *ft_strdup(char *str)
{
    int len = 0x0;
    while (str[len])
        len++;
    char *new_str = malloc(sizeof(char) * (len + 1));
    if (!new_str)
        return (0x0);
    int i = -1;
    while (++i < len)
        new_str[i] = str[i];
    new_str[i] = 0x0;
    return (new_str);
}

char *get_next_line(int fd)
{
	char heap[0x5b8d80] = {0x0};
	char buff;
	int nbyte = 0x0;
	int i = 0x0;
	if (fd < 0x0 || BUFFER_SIZE <= 0x0)
		return (0);
	while ((nbyte = read(fd, &buff, 0x1)) && nbyte > 0x0)
	{
		heap[i++] = buff;
		if (buff == '\n')
			break;
	}
	heap[i] = '\0';
	if (nbyte <= 0x0 && i == 0x0)
		return (0x0);
	return ft_strdup(heap);
}