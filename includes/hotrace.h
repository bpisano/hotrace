/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hotrace.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ratroncy <ratroncy@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/22 15:57:31 by ratroncy     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/23 13:16:38 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <wchar.h>

# define BUFF_SIZE 64
# define BEGIN_M 10
# define LEN_M 100
# define SUM_M 100

typedef struct		s_word
{
	char			*key;
	char			*value;
	int				begin;
	int				len;
	int				sum;
	struct s_word	*next;
}					t_word;

typedef struct		s_search
{
	char			*key;
	struct s_search	*next;
}					t_search;

int					word_sum(char *word);
t_word				*new_word(char *key);
void				add_word(t_word **words, t_word *new);
void				sort_word(t_word *****list, t_word *word);

t_search			*new_search(char *search);
void				add_search(t_search **search, t_search *new);
void				get_value(t_word *****list, t_search **search);

void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memalloc(size_t size);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putstr(char const *s);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *str);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putendl(char const *s);

#endif
