/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   search_manager.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/22 19:39:15 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/23 18:25:48 by bpisano     ###    #+. /#+    ###.fr     */
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
	new->prev = NULL;
	return (new);
}

void	add_search(t_search **search, t_search *new)
{
	if (!new)
		return ;
	new->next = *search;	
	if (*search)
		(*search)->prev = new;
	*search = new;
}

t_word	*word(t_word *****list, char *key)
{
	int		key1;
	int		key2;
	int		key3;
	t_word	*current;

	key1 = word_maths1(key) % KEY1_M;
	key2 = word_maths2(key) % KEY2_M;
	key3 = (key1 + key2) % KEY3_M;
	current = (*list)[key1][key2][key3];
	if (!current)
		return (NULL);
	while (current)
	{
		if (ft_strcmp(current->key, key) == 0)
			return (current);
		current = current->next;
	}
	return (NULL);
}

int		can_find(int **indexes, char *key)
{
	int		maths;

	maths = index_maths(key);
	return ((*indexes)[maths]);
}

void	get_value(t_word *****list, t_search **search, int **indexes)
{
	t_search	*current;
	t_word		*v;

	if (!(*search))
		return ;
	current = *search;	
	while (current->next)
		current = current->next;
	while (current)
	{
		if (!can_find(indexes, current->key))
			print_not_found(current->key);
		else if (!(v = word(list, current->key)))
			print_not_found(current->key);
		else
			print_value(v);
		current = current->prev;
	}
}
