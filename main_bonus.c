/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siliu <siliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:01:53 by siliu             #+#    #+#             */
/*   Updated: 2026/01/07 16:35:41 by siliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	main(void)
{
	int fd1 = open("test1.txt", O_RDONLY);
	int fd2 = open("test2.txt", O_RDONLY);
	int fd3 = open("test3.txt", O_RDONLY);
	char *test1 = get_next_line(fd1);
	char *test2 = get_next_line(fd2);
	char *test3 = get_next_line(fd3);

	int i = 0;

	while (test1 && i < 10)
	{
		printf("test[%i]=%s", i, test1);
		if (test1)
			free(test1);
		test1 = get_next_line(fd1);
		i++;
	}
	write(1, "\n", 1);
	
	i = 0;
	while (test2 && i < 10)
	{
		printf("test[%i]=%s", i, test2);
		if (test2)
			free(test2);
		test2 = get_next_line(fd2);
		i++;
	}
	write(1, "\n", 1);
	
	i = 0;
	while (test3 && i < 10)
	{
		printf("test[%i]=%s", i, test3);
		if (test3)
			free(test3);
		test3 = get_next_line(fd3);
		i++;
	}
	write(1,"\n",1);

	close(fd1);
	close(fd2);
	close(fd3);
	return(0);
}