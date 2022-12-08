/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 23:25:50 by aelkhali          #+#    #+#             */
/*   Updated: 2022/12/03 14:55:22 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strchr(char *s, int c)
{
	char	c_c;
	int		i;

	c_c = (char )c;
	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != c_c)
		i++;
	if (s[i] == '\0' && s[i] != c)
		return (NULL);
	return ((char *)&s[i]);
}
