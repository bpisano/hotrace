/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hotrace.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/22 16:37:28 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/23 13:07:56 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "hotrace.h"

t_word		****new_list()
{
	int		i;
	int		j;
	t_word	****l;

	if (!(l = (t_word ****)ft_memalloc(sizeof(t_word ***) * BEGIN_M)))
		return (NULL);
	i = 0;
	while (i < BEGIN_M)
	{
		j = 0;
		if (!(l[i] = (t_word ***)ft_memalloc(sizeof(t_word **) * LEN_M)))
			return (NULL);
		while (j < LEN_M)
		{
			if (!(l[i][j] = (t_word **)ft_memalloc(sizeof(t_word *) * SUM_M)))
				return (NULL);
			j++;
		}
		i++;
	}
	return (l);
}

void	get_input(t_search **search, t_word *****list)
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
		{
			s = 1;
			continue ;
		}
		if (!s && i % 2 == 0)
			word = new_word(line);
		else if (!s && i % 2 != 0)
		{
			word->value = line;
			sort_word(list, word);
		}
		else
			add_search(search, new_search(line));
		i++;
	}
}

int		main(void)
{
	t_search	*search;
	t_word		****list;

	search = NULL;
	list = new_list();
	get_input(&search, &list);
	get_value(&list, &search);
	free(list);
	return (0);
}
