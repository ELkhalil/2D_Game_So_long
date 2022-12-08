/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:19:09 by aelkhali          #+#    #+#             */
/*   Updated: 2022/12/03 14:51:01 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	**memory_free(char **strs, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(strs[i]);
		i++;
	}
	free (strs);
	return (NULL);
}

static int	wd_counter(char *str, char c)
{
	int	i;
	int	num_wd;

	i = 0;
	num_wd = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
		{
			num_wd++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (num_wd);
}

static char	**fill_strs(char **strs, char *s, char c, int wd_l)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			while (s[i] && s[i] != c)
			{
				wd_l++;
				i++;
			}
			strs[j] = ft_substr(s, (i - wd_l), wd_l);
			if (!strs[j])
				return (memory_free(strs, j));
			wd_l = 0;
			j++;
		}
	}
	return (strs);
}

char	**ft_split(char *s, char c)
{
	char	**spl_strs;
	int		retu_count;
	int		wd_len;

	if (!s)
		return (NULL);
	wd_len = 0;
	retu_count = wd_counter(s, c);
	spl_strs = malloc(sizeof(char *) * (retu_count + 1));
	if (!spl_strs)
		return (NULL);
	spl_strs[retu_count] = NULL;
	if (!fill_strs(spl_strs, s, c, wd_len))
		return (NULL);
	return (spl_strs);
}
