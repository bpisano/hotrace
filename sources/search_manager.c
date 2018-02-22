/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   search_manager.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/22 19:39:15 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/22 20:02:01 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "hotrace.h"

t_search	*new_search(char *search)
{
	t_search	*new;

	if (!search)
		return (NULL);
	if (!(new = (t_search *)ft_memalloc(sizeof(t_search))))
		return (NULL);
	new->key = search;
	new->next = NULL;
	return (new);
}

void	add_search(t_search **search, t_search *new)
{
	new->next = *search;
	*search = new;
}
