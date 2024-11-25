/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:44:30 by edelanno          #+#    #+#             */
/*   Updated: 2024/11/21 15:44:32 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_temp(char *newbuffer, char *buffer, int i)
{
	char	*temp;

	// if (newbuffer == NULL)
	// 	return (NULL);
	if (i < 0)
	{
		temp = ft_strjoin(newbuffer, buffer);
		free (newbuffer);
		newbuffer = temp;
	}
	if (i >= 0)
	{
		temp = ft_strdup(newbuffer + i + 1);
		free(newbuffer);
		newbuffer = temp;
	}
	if (newbuffer == NULL)
		return (NULL);
	return (newbuffer);
}

char	*ft_read(int fd, char *buffer, char *newbuffer)
{
	int	m;

	m = 1;
	// buffer[0] = '\0';

	while (m > 0 && ft_strchr(newbuffer, '\n') == NULL)
	{
		m = read (fd, buffer, BUFFER_SIZE);
		if (m == -1)
		{
			free(newbuffer);
			return (0);
		}
		buffer[m] = '\0';
		newbuffer = ft_temp(newbuffer, buffer, -1);
	}
	if (m == 0 && !newbuffer)
	{
		free(newbuffer);	
		return (NULL);
	}
	return (newbuffer);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*newbuffer = NULL;
	char		*content;
	int			i;

	buffer[0] = '\0';
	newbuffer = ft_read(fd, buffer, newbuffer);
	content = malloc ((ft_strlen(newbuffer) + 1) * sizeof(char));
	if (content == NULL || newbuffer == NULL)
	{
		free (newbuffer);
		return (NULL);
	}
	i = - 1;
	while (newbuffer[++i] && newbuffer[i] != '\n')
		content[i] = newbuffer[i];
	if (newbuffer[i] == '\n') /*|| newbuffer[i] == '\0')*/
	{
		newbuffer = ft_temp(newbuffer, newbuffer, i);
		content[i] = '\n';
		return (content);
	}
	content[++i] = '\0';
	// if (newbuffer[i] == '\0')
	// {
	// 	// free (newbuffer);
	// 	return (content);

	// free (content);
	return (content);
}

// # include <sys/types.h>
// # include <sys/stat.h>
// # include <fcntl.h>

// int	main()
// {
// 	int fd = open ("test.txt", O_RDONLY);
// 	int i = 0;

// 	while (i < 3)
// 	{
// 		printf("i = %i line = %s\n", i , get_next_line(fd));
// 		i++;
// 	}
// 	close (fd);
// }
