/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hotrace.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/22 16:37:28 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/23 19:21:44 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "hotrace.h"

t_word		****new_list(void)
{
	int		i;
	int		j;
	t_word	****l;

	if (!(l = (t_word ****)ft_memalloc(sizeof(t_word ***) * KEY1_M)))
		return (NULL);
	i = 0;
	while (i < KEY1_M)
	{
		j = 0;
		if (!(l[i] = (t_word ***)ft_memalloc(sizeof(t_word **) * KEY2_M)))
			return (NULL);
		while (j < KEY2_M)
		{
			if (!(l[i][j] = (t_word **)ft_memalloc(sizeof(t_word *) * KEY3_M)))
				return (NULL);
			j++;
		}
		i++;
	}
	return (l);
}

void		get_input(t_search **search, t_word *****list, int **indexes)
{
	t_word	*word;
	char	*line;
	int		i;
	int		s;

	i = 0;
	s = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strlen(line) == 0)
			s = 1;
		else if (!s && i % 2 == 0)
			word = new_word(line);
		else if (!s && i % 2 != 0)
		{
			word->value = line;
			word->v_len = ft_strlen(line);
			sort_word(list, word);
			(*indexes)[index_maths(word->key)] = 1;
		}
		else
			add_search(search, new_search(line));
		i++;
	}
}

int			main(void)
{
	t_search	*search;
	t_word		****list;
	int			*indexes;

	search = NULL;
	if (!(list = new_list()))
		return (0);
	if (!(indexes = (int *)ft_memalloc(sizeof(int) * IND_M)))
		return (0);
	get_input(&search, &list, &indexes);
	get_value(&list, &search, &indexes);
	free(list);
	return (0);
}
