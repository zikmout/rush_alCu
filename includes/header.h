/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 10:05:44 by ssicard           #+#    #+#             */
/*   Updated: 2015/12/21 16:50:37 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# define BUFF_SIZE 1
# include <string.h>

/*
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
*/
void				ft_putchar(char c);
void				ft_putnbr(int nb);
void				ft_putstr(char *str);
int					ft_atoi(char *str);
char				*ft_strcpy(char *dst, char *src);
char				*ft_strdup(char *s1);
size_t				ft_strlen(const char *s);

typedef struct		s_list
{
	int				content;
	struct s_list	*next;
}					t_list;
t_list				*new_node(int bytes);
t_list				*ft_lstlast(t_list *first);
int					ft_open(char *name);
void				ft_putstr_fd(const char *str, int fd);
void				ft_print_matches(t_list *first);
int					ft_game_match(t_list *first);
char				ft_tolower(char c);
char				*ft_strlower(char *str);
int					*ft_strcmp(const char *s1, const char *s2);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_read_user(void);
void				ft_lstdel_zero(t_list *first);
int					ft_len_list(t_list *first);
int					ft_solve_matches(t_list *first, int nbrline);
int					ft_isdigit(int c);
int					ft_let_choice();
void				ft_ask_user(int time);

#endif
