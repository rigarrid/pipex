/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:36:05 by rigarrid          #+#    #+#             */
/*   Updated: 2023/05/17 14:35:56 by rigarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

/*
 * auxiliary function that extracts the first line from the character
 * string TEMP and shifts the TEMP pointer to the beginning of the next line.
 * It returns the extracted line or NULL if there are no more lines to extract.
*/

static char	*ft_next(char **tmp)
{
	char	*line;
	char	*ptr;

	ptr = *tmp;
	while (*ptr && *ptr != '\n')
		++ptr;
	ptr += (*ptr == '\n');
	line = ft_substr(*tmp, 0, (size_t)(ptr - *tmp));
	if (!line)
	{
		free (*tmp);
		return (NULL);
	}
	ptr = ft_substr(ptr, 0, ft_strlen (ptr));
	free(*tmp);
	*tmp = ptr;
	return (line);
}

/*
 * Auxiliary function that reads the file with the file descriptor FD 
 * and concatenates the read content to the TMP string, 
 * which holds the portion of the file that has already been read and 
 * not yet returned in previous calls. 
 * The funcion reads the file in buffers of size BUFFER_SIZE until a newline 
 * character is encountered or the end of the file is reached. 
 * It returns the updated TMP or NULL in case of an error.
*/

static char	*ft_get(char *tmp, int fd, char *buffer)
{
	int	br;

	br = 1;
	while (br && !ft_strchr(tmp, '\n'))
	{
		br = read(fd, buffer, BUFFER_SIZE);
		if (br == -1)
		{
			free(buffer);
			free(tmp);
			return (NULL);
		}
		buffer[br] = 0;
		tmp = ft_strjoin(tmp, buffer);
		if (!tmp)
		{
			free(buffer);
			return (NULL);
		}
	}
	free(buffer);
	return (tmp);
}

/*
 * Main function that is called from the program. The function checks 
 * for errors in the input arguments, initializes the static variable TEMP, 
 * and calls ft_get to read a line from the file.
 * After reading the line, it calls ft_next to extract the first line from 
 * the TEMP string and returns it. If there are no more lines to extract, 
 * it returns NULL.
*/

char	*get_next_line(int fd)
{
	static char	*tmp[OPEN_MAX];
	char		*buffer;

	if (fd == -1 || BUFFER_SIZE < 1)
		return (NULL);
	if (!tmp[fd])
		tmp[fd] = ft_strdup("");
	if (!tmp[fd])
		return (NULL);
	buffer = malloc(sizeof(*buffer) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		free (tmp[fd]);
		return (NULL);
	}
	tmp[fd] = ft_get(tmp[fd], fd, buffer);
	if (!tmp[fd])
		return (NULL);
	if (!*tmp[fd])
	{
		free (tmp[fd]);
		tmp[fd] = NULL;
		return (NULL);
	}
	return (ft_next(&tmp[fd]));
}

/*int main()
{
	int fd = open("prueba.txt", O_RDONLY);
	char *line;

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
	}

	close(fd);
	return 0;
}*/
