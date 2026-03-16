/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siliu <siliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:42:45 by siliu             #+#    #+#             */
/*   Updated: 2026/01/07 15:50:16 by siliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void			*str;
	unsigned char	*ptr;
	size_t			i;

	str = malloc(count * size);
	if (!str)
		return (NULL);
	ptr = (unsigned char *)str;
	i = 0;
	while (i < count * size)
	{
		ptr[i] = '\0';
		i++;
	}
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (unsigned char)c)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dup;
	int		size;

	i = 0;
	size = ft_strlen(s1);
	dup = malloc(sizeof(char) * (size + 1));
	if (!dup)
		return (NULL);
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char *s1, char const *s2, int nbyte)
{
	char	*str;
	int		i;
	int		w;

	i = 0;
	w = 0;
	str = ft_calloc((ft_strlen(s1) + nbyte + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[w] && w < nbyte)
	{
		str[i + w] = s2[w];
		w++;
	}
	free(s1);
	return (str);
}
