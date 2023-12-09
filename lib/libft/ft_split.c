/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:19:16 by seozkan           #+#    #+#             */
/*   Updated: 2022/12/15 16:29:36 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	word_count(const char *s, char c)
{
	int	i;
	int	count;
	int	toggle;

	i = 0;
	count = 0;
	toggle = 0;
	while (s[i])
	{
		if (s[i] != c && toggle == 0)
		{
			toggle = 1;
			count++;
		}
		else if (s[i] == c)
			toggle = 0;
		i++;
	}
	return (count);
}

char	*ft_createstr(const char *s, char c, size_t i)
{
	size_t	len;
	size_t	tmp;

	len = 0;
	tmp = i;
	while (s[tmp] != c && s[tmp])
	{
		tmp++;
		len++;
	}
	return (ft_substr(s, i, len));
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**str;

	if (!s)
		return (0);
	str = (char **)malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			str[j++] = ft_createstr(s, c, i);
		while (s[i] && s[i] != c)
			i++;
	}
	str[j] = 0;
	return (str);
}
