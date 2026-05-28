/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efiguere <efiguere@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 17:06:55 by efiguere          #+#    #+#             */
/*   Updated: 2026/05/04 16:30:28 by efiguere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_pos(const char *src, char c);
static char	*ft_trimmed(const char *src, size_t start, size_t end);

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;

	start = 0;
	end = ft_strlen(s1) - 1;
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	while (ft_pos(set, s1[start]))
		start++;
	while (ft_pos(set, s1[end]))
		end--;
	return (ft_trimmed(s1, start, end - start + 1));
}

static char	*ft_trimmed(const char *s1, size_t start, size_t end)
{
	char	*dest;
	size_t	i;

	if (end <= 0 || start >= ft_strlen(s1))
		return (ft_strdup(""));
	dest = malloc(end + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (i < end)
	{
		dest[i] = s1[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	ft_pos(const char *check, char c)
{
	int	i;

	i = 0;
	while (check[i])
	{
		if (c == check[i])
			return (1);
		i++;
	}
	return (0);
}

/*int main(void)
{
	char *src = "aaaabHola mundoabaaa";
	char *dest = ft_strtrim(src, "ab");
	printf("%s", dest);
	free(dest);
	return (0);
}*/
