/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hotrace.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ratroncy <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/22 15:57:31 by ratroncy     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/22 20:00:52 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include "libft.h"

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

t_word				*new_word(char *key);
void				add_word(t_word **words, t_word *new);
void				sort_word(t_word *****list, t_word *word);
t_search			*new_search(char *search);
void				add_search(t_search **search, t_search *new);

#endif
