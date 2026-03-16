/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siliu <siliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:50:34 by siliu             #+#    #+#             */
/*   Updated: 2026/01/07 17:06:10 by siliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int fd;
	char *test;
	int i;

	i = 0;

	fd = open("get_next_line.c", O_RDONLY);
	test = get_next_line(fd);
	while (test)
	{
		printf("%s", test);
		if (test)
			free(test);
		test = get_next_line(fd);
	}
	close(fd);
	return(0);
}