/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhebert <anhebert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 10:41:27 by anhebert          #+#    #+#             */
/*   Updated: 2022/05/03 08:58:52 by anhebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*stash_trim(char *stash)
{
	char	*trimmed;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (stash[0] == '\0')
	{
		free (stash);
		return (NULL);
	}
	while (stash[i] != '\n' && stash[i])
		i++;
	if (stash[i] == '\n')
		i++;
	trimmed = ft_calloc(sizeof(char), ((ft_strlen(stash) - i) + 1));
	while (stash[i])
		trimmed[j++] = stash[i++];
	free (stash);
	return (trimmed);
}

char	*create_new_line(char *stash)
{
	char	*new_line;
	int		i;
	int		j;

	i = 0;
	if (stash[0] == '\0')
		return (NULL);
	while (stash[i] != '\n' && stash[i])
		i++;
	if (stash[i] == '\n')
		i++;
	new_line = ft_calloc(sizeof(char), (i + 1));
	j = 0;
	while (j < i)
	{
		new_line[j] = stash[j];
		j++;
	}
	return (new_line);
}

char	*create_stash(char *stash, char *buffer)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	temp = ft_calloc(sizeof(char), (ft_strlen(stash) + ft_strlen(buffer) + 1));
	while (stash[i])
	{
		temp[i] = stash[i];
		i++;
	}
	while (buffer[j])
		temp[i++] = buffer[j++];
	free (stash);
	return (temp);
}

int	ft_strchr(char *str, char ch)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (ch))
			return (1);
		i++;
	}
	return (0);
}
