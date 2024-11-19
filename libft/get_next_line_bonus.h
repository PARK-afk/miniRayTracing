/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:17:21 by junsepar          #+#    #+#             */
/*   Updated: 2023/02/23 18:38:27 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256 
# endif

char		*read_line(int fd, char *buf, char *backup, int n);
char		*get_next_line(int fd);
char		*need_backup(char *line);
char		*ft_strdup(const char *s1);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char const *s1, char const*s2);
int			ft_strlcpy(char *dst, \
			const char *src, int dstsize);
int			ft_strlcat(char *dst, \
			const char *src, int dstsize);
int			ft_strlen(const char *s);

#endif
