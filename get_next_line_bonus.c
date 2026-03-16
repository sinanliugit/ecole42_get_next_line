/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siliu <siliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:41:54 by siliu             #+#    #+#             */
/*   Updated: 2026/01/07 16:48:10 by siliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 6
#endif

size_t	ft_strlen_mod(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*free_function(char *tab, char *str)
{
	if (tab)
		free(tab);
	if (str)
		free(str);
	return (NULL);
}

char	*read_function(int fd, char *tab)
{
	int		nbyte;
	char	*buf;

	if (!tab)
		tab = ft_calloc(1, 1);
	if (!tab)
		return (NULL);
	buf = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buf)
		return (free_function(tab, 0));
	nbyte = 1;
	while (nbyte != 0 && !(ft_strchr(buf, '\n')))
	{
		nbyte = read(fd, buf, BUFFER_SIZE);
		if (nbyte == -1)
			return (free_function(buf, tab));
		if (nbyte == 0 && ft_strlen(tab) == 0)
			return (free_function(buf, tab));
		if (nbyte == 0)
			break ;
		tab = ft_strjoin(tab, buf, nbyte);
		if (!tab)
			return (free_function(buf, 0));
	}
	return (free(buf), tab);
}

char	*find_newline(char *tab, int i)
{
	char	*newline;
	int		w;

	w = 0;
	newline = ft_calloc(((ft_strlen_mod(tab)) + 1), sizeof(char));
	if (!newline)
		return (free_function(tab, 0));
	while (tab[i] && tab[i] != '\n')
	{
		newline[w] = tab[i];
		i++;
		w++;
	}
	if (tab[i] == '\n')
		newline[w] = '\n';
	return (newline);
}

char	*get_next_line(int fd)
{
	static char	*tab[2048];
	char		*newline;
	char		*the_rest;

	if (fd < 0 || BUFFER_SIZE == 0)
		return (0);
	tab[fd] = read_function(fd, tab[fd]);
	if (!tab[fd])
		return (NULL);
	newline = find_newline(tab[fd], 0);
	if (!newline)
		return (NULL);
	the_rest = ft_strdup(&tab[fd][ft_strlen_mod(tab[fd])]);
	free(tab[fd]);
	tab[fd] = the_rest;
	return (newline);
}
