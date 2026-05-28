/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efiguere <efiguere@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 15:55:19 by efiguere          #+#    #+#             */
/*   Updated: 2026/04/29 18:22:58 by efiguere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c);
static int	word_len(const char *s, char c, size_t pos);
static void	*free_all(char **s, int i);

char	**ft_split(const char *s, char c)
{
	char	**dest;
	int		i;
	int		j;
	int		words;
	int		len_word;

	i = 0;
	j = 0;
	words = count_words(s, c);
	dest = malloc((words + 1) * sizeof(char *));
	if (!dest)
		return (NULL);
	while (i < words)
	{
		while (s[j] == c)
			j++;
		len_word = word_len(s, c, j);
		dest[i] = ft_substr(s, j, len_word);
		if (!dest[i])
			return (free_all(dest, i));
		j = j + len_word;
		i++;
	}
	dest[i] = NULL;
	return (dest);
}

static int	count_words(const char *s, char c)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static int	word_len(const char *s, char c, size_t pos)
{
	int		count;

	count = 0;
	while (s[pos] != c && s[pos] != '\0')
	{
		pos++;
		count++;
	}
	return (count);
}

static void	*free_all(char **s, int i)
{
	while (i > 0)
	{
		i--;
		free(s[i]);
	}
	free(s);
	return (NULL);
}
