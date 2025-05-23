/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpico-co <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:15:12 by gpico-co          #+#    #+#             */
/*   Updated: 2024/10/15 11:02:09 by gpico-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**memal(size_t words)
{
	char	**res;

	res = (char **)malloc((words + 1) * sizeof (char *));
	if (res == NULL)
		return (NULL);
	res[words] = ((void *)0);
	return (res);
}

static char	**memfree(char **res, size_t words)
{
	while (words > 0)
	{
		free(res[--words]);
	}
	free(res);
	return (NULL);
}

static size_t	word_count(char const *s, char c)
{
	size_t	counter;
	short	in_word;

	counter = 0;
	in_word = 0;
	while (*s)
	{
		if (*s == c)
			in_word = 0;
		else if (!in_word)
		{
			counter++;
			in_word = 1;
		}
		s++;
	}
	return (counter);
}

static char	**split(char const *s, char c, char **res)
{
	size_t	i;
	size_t	j;
	char	*buf;
	size_t	word_counter;

	word_counter = 0;
	i = 0;
	while (s[i] != '\0')
	{
		j = i;
		while (s[j] != '\0' && s[j] != c)
			j++;
		if (j != i)
		{
			buf = ft_substr(s, i, (j - i));
			if (buf == NULL)
				return (memfree(res, word_counter));
			res[word_counter++] = buf;
		}
		while (s[j] != '\0' && s[j] == c)
			j++;
		i = j;
	}
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s && !c)
		return (NULL);
	result = memal(word_count(s, c));
	if (result == NULL)
		return (NULL);
	result = split(s, c, result);
	if (result == NULL)
		return (NULL);
	return (result);
}
