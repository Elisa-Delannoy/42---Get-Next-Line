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

char	*ft_read(int fd)
{
	char 		buffer[BUFFER_SIZE + 1];
	int 		m;
	static char	*newbuffer = NULL;
	char		*temp;
	char 		*content;
	int			i;

	
	// buffer = malloc ((BUFFER_SIZE + 1) * sizeof(char));
	// if (buffer == NULL)
	// 	return (0);


	// m = read (fd, buffer, BUFFER_SIZE);
	// if (m == -1)
	// {
	// 	free(buffer);
	// 	return (0);		
	// }

	// printf("buffer init=%s\n", buffer);
	// temp = ft_strjoin(newbuffer, buffer);
	// free (newbuffer);
	// newbuffer = temp;
	// printf("newbuffer init=%s\n", newbuffer);
	m = 1;
	buffer[0] = '\0';
	while (m > 0 && ft_strchr(newbuffer, '\n') == NULL)
	{
		m = read (fd, buffer, BUFFER_SIZE);
		buffer[m] = '\0';
		// printf("buffer apres boulce =%s\n", buffer);
		if (m == -1)
		{
			free(newbuffer);
			return (NULL);	
		}
		temp = ft_strjoin(newbuffer, buffer);
		free (newbuffer);
		newbuffer = temp;
		// printf("newbuffer boulce =%s\n", newbuffer);
	}	
	
	content = malloc ((ft_strlen(newbuffer) + 1) * sizeof(char));
	if (content == NULL)
		return (NULL);
	i = 0;
	while (newbuffer[i] && newbuffer[i] != '\n')
	{
		content[i] = newbuffer[i];
		i++;
	}
	// printf("content  =%s\n", content);
	if (newbuffer[i] == '\n' ||	!newbuffer[i])
	{
		newbuffer = ft_strdup(newbuffer + i + 1);
		printf("newbuffer raz =%s\n", newbuffer);
		return (content);
	}
	if (m == 0)
		return (NULL);
		

	// printf("content =%s\n", content);
	// printf("buffer = %s\n", newbuffer);
	return (NULL);
}



// char	*get_next_line(int fd)
// {
// 	static char	*newbuffer = NULL;
	
	
	
	
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
	
	int i = 0;

	while (i < 3)
	{
		printf("i = %i line = %s\n", i , ft_read (fd));
		i++;
	}
	// printf("test join%s", ft_strjoin("hello", "bonjour"));
	close (fd);
}
	
// 	return (0);
// }
	
		

// 	return (0);
// }