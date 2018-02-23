/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   search_manager.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/22 19:39:15 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/23 12:59:50 by bpisano     ###    #+. /#+    ###.fr     */
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
	t_search	*current;

	if (!(*search))
	{
		*search = new;
		return ;
	}
	current = *search;
	while (current->next)
		current = current->next;
	current->next = new;
}

char	*value(t_word *****list, char *key)
{
	int		begin;
	int		len;
	int		sum;
	t_word	*current;

	begin = (unsigned int)key[0] % 10;
	len = ft_strlen(key) % 100;
	sum = word_sum(key) % 100;
	current = (*list)[begin][sum][len];
	if (!current)
		return (NULL);
	while (current)
	{
		if (ft_strcmp(current->key, key) == 0)
			return (current->value);
		current = current->next;
	}
	return (NULL);
}

void	get_value(t_word *****list, t_search **search)
{
	char		*v;
	t_search	*current;

	if (!(*search))
		return ;
	current = *search;
	while (current)
	{
		if (!(v = value(list, current->key)))
			ft_putstr("No result\n");
		else
			ft_putendl(v);
		current = current->next;
	}
}
