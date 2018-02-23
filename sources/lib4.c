/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lib4.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ratroncy <ratroncy@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/23 13:22:39 by ratroncy     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/23 13:36:03 by ratroncy    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "hotrace.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int		i;
	int		j;

	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (s2[j])
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}

char	*ft_strcpy(char *dst, const char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strsub(char const *s, unsigned int start, size_t size)
{
	char			*str;
	char			*cpy;

	if (!s)
		return (NULL);
	if (!(cpy = ft_strnew(size)))
		return (NULL);
	str = (char *)s;
	ft_strncpy(cpy, str + start, size);
	return (cpy);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	if (!(join = ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	ft_strcpy(join, s1);
	ft_strcat(join, s2);
	return (join);
}

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if (!(new = (t_list *)ft_memalloc(sizeof(t_list))))
		return (NULL);
	new->content = content ? ft_memalloc(content_size) : NULL;
	new->content_size = content ? content_size : 0;
	new->next = NULL;
	if (content)
		ft_memcpy(new->content, content, content_size);
	return (new);
}
