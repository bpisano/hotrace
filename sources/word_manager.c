/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   word_manager.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/22 20:01:10 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/22 20:30:26 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "hotrace.h"

t_word	*new_word(char *key)
{
	t_word	*new;

	if (!key)
		return (NULL);
	if (!(new = (t_word *)ft_memalloc(sizeof(t_word))))
		return (NULL);
	new->key = key;
	new->value = NULL;
	new->begin = (unsigned int)key[0];
	new->len = ft_strlen(key);
	new->sum = 0;
	new->next = NULL;
	return (new);
}

void	add_word(t_word **words, t_word *new)
{
	new->next = *words;
	*words = new;
}

void	sort_word(t_word *****list, t_word *word)
{
	add_word(&(*list)[word->begin][word->sum][word->len], word);
}
