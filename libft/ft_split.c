/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnascime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 17:38:50 by mnascime          #+#    #+#             */
/*   Updated: 2022/04/03 17:38:52 by mnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "libft.h"

static size_t	beg_trim(const char *s1, char c, size_t i)
{
	while (s1[i] != '\0' && s1[i] != c)
		i++;
	return (i);
}

static char	*strs(const char *s, size_t i, size_t f)
{
	char	*str;
	size_t	j;

	j = 0;
	str = malloc(sizeof(char) * (f - i + 1));
	if (!str)
		return (NULL);
	while (s[i] && i < f)
	{
		str[j] = s[i++];
		j++;
	}
	str[j] = '\0';
	return (str);
}

static int	count_c(const char *s, char c)
{
	int	f;
	int	i;

	f = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		i = beg_trim(s, c, i);
		f++;
	}
	return (f);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**ptrs;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	ptrs = malloc(sizeof(char *) * (count_c (s, c) + 1));
	if (!ptrs)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		ptrs[j++] = strs(s, i, beg_trim(s, c, i));
		i = beg_trim(s, c, i);
	}
	ptrs[j] = 0;
	return (ptrs);
}
