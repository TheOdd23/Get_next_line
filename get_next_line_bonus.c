/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhebert <anhebert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 12:40:07 by anhebert          #+#    #+#             */
/*   Updated: 2022/05/03 09:01:15 by anhebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_bzero(void *str, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return ;
	while (i < n)
	{
		((char *)str)[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t num, size_t size)
{
	char	*new;

	new = malloc(num * size);
	if (new == NULL)
		return (NULL);
	ft_bzero(new, (num * size));
	return (new);
}

char	*get_next_line(int fd)
{	
	static char	*stash[1025];
	char		*new_line;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		free (stash[fd]);
		return (NULL);
	}
	if (!stash[fd])
		stash[fd] = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	stash[fd] = create_buffer(stash[fd], fd);
	new_line = create_new_line(stash[fd]);
	stash[fd] = stash_trim(stash[fd]);
	return (new_line);
}

char	*create_buffer(char *stash, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int		res;

	res = 1;
	while (res > 0 && ft_strchr(stash, '\n') == 0)
	{
		res = read(fd, buffer, BUFFER_SIZE);
		buffer[res] = '\0';
		stash = create_stash(stash, buffer);
	}
	return (stash);
}
