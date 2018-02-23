/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lib2.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ratroncy <ratroncy@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/23 12:57:16 by ratroncy     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/23 13:01:00 by ratroncy    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "hotrace.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char const *s, int fd)
{
	int		i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

void	ft_putstr(char const *s)
{
	ft_putstr_fd(s, 1);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	int		i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && (unsigned char)s1[i] == (unsigned char)s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

size_t	ft_strlen(const char *str)
{
	size_t		i;

	if (!(*str))
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}