/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:56:13 by aelkhali          #+#    #+#             */
/*   Updated: 2022/12/03 14:54:42 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	*re_n_store(int fd, char *container)
{
	int		i_readed;
	char	*buf;

	i_readed = 1;
	buf = malloc (BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (i_readed != 0 && !ft_strchr(container, '\n'))
	{
		i_readed = (int )read(fd, buf, BUFFER_SIZE);
		if (i_readed == -1)
		{
			free(container);
			free(buf);
			return (NULL);
		}
		buf[i_readed] = '\0';
		container = ft_strjoin(container, buf);
	}
	free(buf);
	return (container);
}

static char	*line_extractor(char *str)
{
	unsigned int	len;
	char			*extracted_line;

	if (!*str)
		return (NULL);
	len = ft_strlen(str) - ft_strlen(ft_strchr(str, '\n')) + 1;
	extracted_line = ft_substr(str, 0, len);
	return (extracted_line);
}

static char	*extract_mod(char *str)
{
	char			*mod_extract;
	unsigned int	start;
	size_t			len;

	if (!ft_strchr(str, '\n'))
	{
		free(str);
		return (NULL);
	}
	len = ft_strlen(ft_strchr(str, '\n')) - 1;
	start = (unsigned int )(ft_strlen(str) - (len + 1));
	mod_extract = ft_substr(str, start + 1, len);
	free(str);
	return (mod_extract);
}

char	*get_next_line(int fd)
{
	static char	*container;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= SIZE_MAX)
		return (NULL);
	container = re_n_store(fd, container);
	if (!container)
		return (NULL);
	line = line_extractor(container);
	container = extract_mod(container);
	return (line);
}
