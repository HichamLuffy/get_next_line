/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfhad <hfhad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:05:32 by hfhad             #+#    #+#             */
/*   Updated: 2024/11/16 17:43:08 by hfhad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*pk;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	pk = (char *) malloc(i + 1);
	if (!pk)
		return (NULL);
	while (s1[j] != '\0')
	{
		pk[j] = s1[j];
		j++;
	}
	pk[j] = '\0';
	return (pk);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	i;
	int		j;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	i = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (i + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		result[i++] = s2[j++];
	result[i] = '\0';
	return (result);
}

int	check_new_line(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*fill_fix_line(char **buf, int len)
{
	int		i;
	char	*line;
	char	*tmp_buf;

	line = malloc(sizeof(char) * (len + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = (*buf)[i];
		i++;
	}
	line[len] = '\n';
	line[len + 1] = '\0';
	tmp_buf = ft_strdup(&(*buf)[len + 1]);
	free(*buf);
	*buf = NULL;
	*buf = tmp_buf;
	return (line);
}
