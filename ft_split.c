/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 18:10:05 by ewolfghe          #+#    #+#             */
/*   Updated: 2022/09/11 23:51:36 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_alloc_strs(char **res, char *s, char c, size_t strs);

static size_t	ft_count_strs(char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	strs;

	strs = ft_count_strs(s, c);
	res = (char **)malloc(sizeof(char *) * (strs + 1));
	if ((!s && s[0] == '\0') || !res)
		return (NULL);
	ft_alloc_strs(res, (char *)s, c, strs);
	res[strs] = NULL;
	return (res);
}

static size_t	ft_count_strs(char const *s, char c)
{
	size_t	strs;
	size_t	is_str;
	size_t	i;

	strs = 0;
	is_str = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && is_str)
		{
			is_str = 0;
			strs++;
		}
		else if (s[i] == c)
			is_str = 1;
		i++;
	}
	return (strs);
}

static void	ft_alloc_strs(char **res, char *s, char c, size_t strs)
{
	size_t	start;
	size_t	end;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (j < strs)
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i])
		{
			if (s[i + 1] == c || s[i + 1] == '\0')
				end = i;
			i++;
		}
		res[j] = ft_substr(&s[start], 0, (end - start + 1));
		j++;
	}
}

//////////////////////////////////////////////////////////////////////

	/* 
	Allocates (with malloc(3)) and returns an array of strings obtained by 
	splitting ’s’ using the character ’c’ as a delimiter. The array must be
	ended by a NULL pointer.
	PARAMETERS
	#1. The string to be split.
	#2. The delimiter character.
	RETURN VALUES
	The array of new strings resulting from the split. 
	NULL if the allocation fails. 
	*/

	/* 
	Perhaps I can substitute the delimiter char by '\0' and try to allocate the
	strings in the array like this
	 */
