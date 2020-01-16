/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajuncosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 10:30:48 by ajuncosa          #+#    #+#             */
/*   Updated: 2020/01/16 17:53:00 by ajuncosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_count_pieces(char const *s, char c)
{
	size_t	i;
	size_t	count;
	
	i = 0;
	count = 0;
	while (i < ft_strlen(s))
	{
		while (s[i] == c && i < ft_strlen(s))
			i++;
		while (s[i] != c && i < ft_strlen(s))
			i++;
		if (i != ft_strlen(s))
			count++;
	}
	return (count);
}

size_t			ft_len_pieces(char const *s, char c, size_t piece)
{
	size_t	len;
	size_t	y;
	size_t	i;

	i = 0;
	y = 0;
	while (y <= piece)
	{
		len = 0;
		while (s[i] == c && i < ft_strlen(s))
			i++;
		while (s[i] != c && i < ft_strlen(s))
		{
			len++;
			i++;
		}
		y++;
	}
	return (len);
}

char			**ft_split(char const *s, char c)
{
	size_t	pieces;
	size_t	len;
	size_t	i;
	char	**tab;

	pieces = ft_count_pieces(s, c);
	if (!(tab = malloc((pieces + 1) * sizeof(char *))))
		return (NULL);
	i = 0;
	while (i < pieces)
	{
		len = ft_len_pieces(s, c, i);
		if (!(tab[i] = malloc((len + 1) * sizeof(char))))
			return (NULL);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

int main()
{
	printf("%zu", ft_len_pieces("   hola    que tal  ", ' ', 3));
}
