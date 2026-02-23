/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finorako <finorako@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 07:33:10 by finorako          #+#    #+#             */
/*   Updated: 2026/02/06 10:30:58 by finorako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef MAX_FD
#  define MAX_FD 4096
# endif

# include <stddef.h>

typedef struct s_line_list
{
	struct s_line_list	*next;
	char				*content;
}					t_line_list;

typedef struct s_line
{
	char	*value;
	int		i;
	int		j;
}					t_line;

typedef struct s_current
{
	t_line_list	*temp;
	int			start;
	int			len;
}					t_current;

typedef struct s_start
{
	t_line_list	*lst;
	char		*val;
	char		last[BUFFER_SIZE + 1];
	int			b_read;
}					t_start;

char				*get_next_line(int fd);

int					line_size(t_line_list *lst);

void				lstadd(t_line_list **lst, char *content);

int					found_endl(t_line_list *lst);

void				*ft_memmove(void *dest, const void *src, size_t size);

int					get_next(char *content);
#endif
