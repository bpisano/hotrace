/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hotrace.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ratroncy <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/22 15:57:31 by ratroncy     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/22 16:58:31 by bpisano     ###    #+. /#+    ###.fr     */
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
	char			begin;
	int				len;
	int				sum;

	struct word		*next;
}					t_word;

#endif
