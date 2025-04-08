/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falakus <falakus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 19:23:54 by falakus           #+#    #+#             */
/*   Updated: 2025/03/27 19:26:19 by falakus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>

char	*i_have_one_line(int fd, char *buffer);
int		found_new_line(char *buffer);
int		_ft_strlen(char *str);
char	*_ft_strjoin(char *buffer, char *temp_buffer);
char	*get_new_line(char *buffer);
char	*get_new_buffer(char *buffer);
char	*get_next_line(int fd);

#endif