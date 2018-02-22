/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hotrace.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/22 16:37:28 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/22 21:02:00 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "hotrace.h"

t_word		****new_list()
{
	int		i;
	int		j;
	t_word	****list;

	if (!(list = (t_word ****)ft_memalloc(sizeof(t_word ***) * 255)))
		return (NULL);
	i = 0;
	while (i < 255)
	{
		j = 0;
		if (!(list[i] = (t_word ***)ft_memalloc(sizeof(t_word **) * 100)))
			return (NULL);
		while (j < 100)
		{
			if (!(list[i][j] = (t_word **)ft_memalloc(sizeof(t_word *) * 100)))
				return (NULL);
			j++;
		}
		i++;
	}
	return (list);
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
