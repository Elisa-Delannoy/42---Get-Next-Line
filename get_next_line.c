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

int	ft_read(int fd)
{
	char 		*buffer; /*voir avec alain [BUFFER_SIZE + 1] dans while*/
	int 		m;
	static char	*newbuffer = NULL;
	char		*temp;

	
	buffer = malloc ((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (0);


	m = read (fd, buffer, BUFFER_SIZE);
	if (m == -1)
	{
		free(buffer);
		return (0);		
	}

	printf("buffer init=%s\n", buffer);
	temp = ft_strjoin(newbuffer, buffer);
	free (newbuffer);
	newbuffer = temp;
	printf("newbuffer init=%s\n", newbuffer);

	


	printf("buffer init=%s\n", newbuffer);
	while (m > 0 && ft_strchr(buffer, '\n') == NULL)
	{
		free (buffer);
		buffer = malloc ((BUFFER_SIZE + 1) * sizeof(char));
		if (buffer == NULL)
		{
			free (newbuffer);
			return (0);
		}
		m = read (fd, buffer, BUFFER_SIZE);
		if (m == -1)
		{
			free(buffer);
			free(newbuffer);
			return (0);	
		}
		printf("buffer boulce =%s\n", newbuffer);
		temp = ft_strjoin(newbuffer, buffer);
		free (newbuffer);
		newbuffer = temp;
	}
	free (buffer);	
	return (m);
}



// char	*get_next_line(int fd)
// {
// 	static char	*newbuffer = NULL;
// 	char 		*content;
// 	int			i;
	
	
// 	newbuffer = ft_strjoin(newbuffer, buffer);
// 	content = malloc ((ft_strlen(newbuffer) + 1) * sizeof(char));
// 	i = 0;
// 	while (newbuffer[i] && newbuffer[i] != '\n')
// 	{
// 		content[i] = newbuffer[i];
// 		i++;
// 	}
// 	if (newbuffer[i] == '\n' ||	!newbuffer[i])
// 	{
// 		newbuffer = (newbuffer + i);
// 		return (content);
// 	}
// 	if (m == 0)
// 		return (NULL);
		

// 	printf("content =%s\n", buffer);
// 	printf("buffer = %s\n", buffer);
// 	return (0);
// }

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>


// int main() 
// {
//     int fd = open("test.txt", O_RDONLY);
//     if (fd == -1) {
//         perror("Erreur lors de l'ouverture du fichier");
//         return 1;
//     }

//     // Lecture ligne par ligne avec get_next_line
//     char *line;
//     while ((line = get_next_line(fd)) != NULL) {
//         printf("%s", line);  // Affiche la ligne lue
//         free(line);  // Libère la mémoire allouée pour la ligne
//     }

//     // Si la lecture est terminée ou en cas d'erreur
//     if (line == NULL) {
//         printf("Fin du fichier ou erreur de lecture\n");
//     }

//     close(fd);  // Ferme le fichier après l'utilisation
//     return 0;
// }

int	main()
{
	int fd = open ("test.txt", O_RDONLY);
	
	int a = ft_read (fd);
	printf("%d\n", a);
	// printf("test join%s", ft_strjoin("hello", "bonjour"));
	close (fd);
}
	
// 	return (0);
// }
	// int i = 0;

	// while (i < 4)
	// {
		
		// i++;
	// }
// 	return (0);
// }