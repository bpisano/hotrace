/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   word_manager.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/22 20:01:10 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/23 18:08:40 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "hotrace.h"

int		word_maths1(char *word)
{
	int		i;
	int		sum;

	i = 0;
	sum = 0;
	while (word[i])
	{
		if (i % 2 == 0)
			sum += (int)word[i];
		else
			sum -= (int)word[i];
		i++;
	}
	return (sum < 0 ? -sum : sum);
}

int		word_maths2(char *word)
{
	int		i;
	int		sum;

	i = 0;
	sum = 0;
	while (word[i])
	{
		if ((int)word[i] % 2 == 0)
			sum += (int)word[i] / 2;
		else
			sum += (int)word[i];
		i++;
	}
	return (sum);
}

int		index_maths(char *key)
{
	char	*r_key;
	int		result;
	int		i;

	r_key = "abcdefghijklmnopqrstuvwxyz";
	i = 0;
	result = 0;
	while (key[i])
	{
		result += ((unsigned int)key[i] + (unsigned int)r_key[i % 26]) % IND_M;
		i++;
	}
	return (result);
}

t_word	*new_word(char *key)
{
	t_word	*new;

	if (!key)
		return (NULL);
	if (!(new = (t_word *)ft_memalloc(sizeof(t_word))))
		return (NULL);
	new->key = key;
	new->value = NULL;
	new->v_len = 0;
	new->key1 = word_maths1(key) % KEY1_M;
	new->key2 = word_maths2(key) % KEY2_M;
	new->key3 = (new->key1 + new->key2) % KEY3_M;
	new->next = NULL;
	return (new);
}

void	add_word(t_word **words, t_word *new)
{
	if (!new)
		return ;
	new->next = *words;
	*words = new;
}

void	sort_word(t_word *****list, t_word *word)
{
	add_word(&(*list)[word->key1][word->key2][word->key3], word);
}
