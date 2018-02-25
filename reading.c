/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 17:06:51 by adstan            #+#    #+#             */
/*   Updated: 2018/02/25 19:09:51 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		put_stdin(unsigned int key)
{
	if (key == K_TAB)
	{
		key = -key;
		key = -key;
	}
	if (key == K_ENTER)
		return (0);
	return (1);
}

char	*read_stdin(void)
{
	char	buf[2];
	char	*str;
	int		ret;

	buf[1] = 0;
	if (!(str = (char*)ft_memalloc(sizeof(char))))
		error_exit(M_ERROR, 2);
	while ((ret = read(0, buf, 1)) && (put_stdin((unsigned int)*buf)))
	{
		if (!(str = ft_strjoin(str, buf)))
			error_exit(M_ERROR, 2);
	}
	if (!ret)
	{
		if (str)
			free(str);
		exit(0);
	}
	return (str);
}

char	*str_replace(char *str, char c, char r)
{
	int i;

	i = 0;
	while (str[i++])
		if (str[i] == c)
			str[i] = r;
	return (str);
}

char	**parse_stdin(char *str)
{
	char	**arg;
	int		i;

	i = 0;
	if (!(arg = ft_strsplit(str, ';')))
		error_exit(M_ERROR, 2);
	while (arg[i])
	{
		if (!(arg[i] = ft_strtrim(arg[i])))
			error_exit(M_ERROR, 2);
		i++;
	}
	return (arg);
}

char	***parse_arguments(char **arg)
{
	int		i;
	char	***tri;

	i = 0;
	while (arg[i])
		i++;
	if (!(tri = (char***)ft_memalloc(sizeof(char**) * (i + 1))))
		error_exit(M_ERROR, 2);
	i = 0;
	while (arg[i])
	{
		if (!(tri[i] = ft_strsplit(arg[i], ' ')))
			error_exit(M_ERROR, 2);
		i++;
	}
	return (tri);
}
