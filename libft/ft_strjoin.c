/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 08:29:44 by aelkhali          #+#    #+#             */
/*   Updated: 2022/12/03 14:55:13 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_sv;
	char	*recall;
	int		i;

	i = 0;
	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	new_sv = malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new_sv)
		return (NULL);
	recall = new_sv;
	while (s1[i])
		*new_sv++ = s1[i++];
	while (*s2)
		*new_sv++ = *s2++;
	*new_sv = '\0';
	free(s1);
	return (recall);
}
