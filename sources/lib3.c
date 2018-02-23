/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lib3.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ratroncy <ratroncy@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/23 13:01:23 by ratroncy     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/23 13:02:40 by ratroncy    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "hotrace.h"

void	ft_putendl_fd(char const *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

void	ft_putendl(char const *s)
{
	ft_putendl_fd(s, 1);
}