// #include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd)
{
	int rd = 0;
	int i = 0;
	char	c;
	char	*line = malloc(100000);
	if ((rd = read(fd, &c, 1)) == 0)
		return (NULL);
	line[i++] = c;
	while ((rd = read(fd, &c, 1)) > 0 && c != '\n')
		line[i++] = c;
	if (c == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

// char *get_next_line(int fd)
// {
//     int 	i = 0;
//     int 	rd = 0;
//     char	character;
//     char 	*buffer = malloc(10000);

//     while ((rd = read(fd, &character, 1)) > 0)
//     {
//         buffer[i++] = character;
//         if (character == '\n')
//             break;
//     }
//     if ((!buffer[i - 1] && !rd) || rd == -1)
//     {
//         free(buffer);
//         return (NULL);
//     }
//     buffer[i] =  '\0';
//     return(buffer);
// }

#include <stdio.h>

int main() // main1.c
{
	char *line;
	line = get_next_line(0);
	while (line != NULL)
	{

		printf("%s", line);
		free (line);
		line = get_next_line(0);
	}
	return (0);
}
