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
#include <unistd.h>
#include <stdio.h>

// char	*get_next_line(int fd)
// {

// }

// size_t read(int fd, void *buf, size_t nbytes);


// # include <sys/types.h>
// # include <sys/stat.h>
# include <fcntl.h>
int	main()
{
	char buffer[BUFFER_SIZE + 1];

	int fd = open ("test.txt", O_RDONLY);
	read (fd, buffer, BUFFER_SIZE);
	printf("%s", buffer);
	return (0);
}