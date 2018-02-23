/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lib3.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ratroncy <ratroncy@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/23 13:01:23 by ratroncy     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/23 13:36:01 by ratroncy    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "hotrace.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*s;
	char	*d;

	i = 0;
	s = (char *)src;
	d = (char *)dst;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (src[i] && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	while (i < len)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}

char	*ft_strnew(size_t size)
{
	char	*str;

	if (!(str = (char *)ft_memalloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_bzero(str, size + 1);
	return (str);
}

void	ft_putendl_fd(char const *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

void	ft_putendl(char const *s)
{
	ft_putendl_fd(s, 1);
}
