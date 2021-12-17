/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaquier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:17:47 by tpaquier          #+#    #+#             */
/*   Updated: 2021/12/17 14:17:49 by tpaquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*mem2;
	size_t	i;
	size_t	j;

	mem2 = NULL;
	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	mem2 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!mem2)
		return (NULL);
	while (s1[j])
	{
		mem2[i++] = s1[j];
		j++;
	}
	j = 0;
	while (s2[j])
	{
		mem2[i++] = s2[j];
		j++;
	}
	mem2[i] = '\0';
	return (mem2);
}

char	*get_file_for_resul(int fd, int taille, char *mem, int n)
{
	char	*buff;

	buff = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!mem)
		mem = ft_strdup("");
	while (n == 0 && taille != 0 && taille != -1)
	{
		taille = read(fd, buff, BUFFER_SIZE);
		if (taille == -1)
		{
			free(mem);
			free(buff);
			return (NULL);
		}
		if (taille != 0 && taille != -1)
		{
			buff[taille] = '\0';
			mem = get_strjoin(mem, buff);
		}
		n = get_back_n(mem);
	}
	free(buff);
	return (mem);
}

char	*get_resul(char *mem)
{
	int		j;
	int		i;
	char	*temp;

	temp = NULL;
	j = 0;
	i = 0;
	while (mem[i])
	{
		if (mem[i] == '\n')
			break ;
		i++;
	}
	temp = malloc(i + 2);
	if (!temp)
		return (NULL);
	while (i >= 0)
	{
		temp[j] = mem[j];
		j++;
		i--;
	}
	temp[j] = '\0';
	mem = NULL;
	return (temp);
}

char	*get_newmem(char *mem, int j, int i)
{
	char	*newmem;

	newmem = NULL;
	while (mem[j])
	{
		if (mem[j] == '\n')
			break ;
		j++;
	}
	j++;
	if ((ft_strlen(mem) - j + 1) > 1)
	{
		newmem = malloc(ft_strlen(mem) - j + 1);
		if (!newmem)
			return (NULL);
		while (mem[j])
			newmem[i++] = mem[j++];
		newmem[i] = '\0';
	}
	free(mem);
	mem = NULL;
	return (newmem);
}
