/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/23 17:59:10 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/23 19:23:40 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "hotrace.h"

void	print_not_found(char *key)
{
	write(1, key, ft_strlen(key));
	write(1, ": Not found.\n", 13);
}

void	print_value(t_word *v)
{
	write(1, v->value, v->v_len);
	write(1, "\n", 1);
}
