/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhebert <anhebert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 12:37:52 by anhebert          #+#    #+#             */
/*   Updated: 2022/05/03 08:43:47 by anhebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*create_stash(char *stash, char *buffer);
char	*create_buffer(char *stash, int fd);
char	*create_new_line(char *stash);
char	*stash_trim(char *stash);
int		ft_strchr(char *str, char ch);
size_t	ft_strlen(char *stash);
void	*ft_calloc(size_t num, size_t size);
void	ft_bzero(void *str, size_t n);

#endif