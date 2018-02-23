/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   maths.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/23 19:25:45 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/23 19:26:27 by bpisano     ###    #+. /#+    ###.fr     */
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
