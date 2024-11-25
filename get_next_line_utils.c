/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:44:47 by edelanno          #+#    #+#             */
/*   Updated: 2024/11/21 15:44:48 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s != NULL)
	{
		while (s[i])
			i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		j;

	new = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	i = 0;
	if (s1 != NULL)
	{
		while (s1[i])
		{
			new[i] = s1[i];
			i++;
		}
	}
	j = 0;
	if (s2 != NULL)
	{
		while (s2[j])
		{
			new[i + j] = s2[j];
			j++;
		}
	}
	new [i + j] = '\0';
	return (new);
}

char	*ft_strchr(const char *s, int c)
{
	if (s != NULL)
	{
		while (*s)
		{
			if (*s == (char)c)
				return ((char *)s);
			s++;
		}
		if ((char)c == '\0')
			return ((char *)s);
	}
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*new;
	int		i;

	new = malloc((ft_strlen(s) + 1) * sizeof(char));
	i = 0;
	if (new == NULL)
		return (NULL);
	if (s != NULL)
	{
		while (s[i])
		{
			new[i] = s[i];
			i++;
		}
	}
	new[i] = '\0';
	return (new);
}