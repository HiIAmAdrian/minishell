/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 17:06:51 by adstan            #+#    #+#             */
/*   Updated: 2018/02/19 18:51:43 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*read_stdin(void)
{
	int		i;
	char	buf[2];
	char	*str;
	int		ret;

	i = 1;
	buf[1] = 0;
	if (!(str = (char*)ft_memalloc(sizeof(char) * i++)))
		error_exit("malloc: Allocation error!", 2);
	while ((ret = read(0, buf, 1)) && buf[0] != '\n')
		if (!(str = ft_strjoin(str, buf)))
			error_exit("malloc: Allocation error!", 2);
	if (!ret)
	{
		free(str);
		exit(0);
	}
	return (str);
}

char	**parse_stdin(char *str)
{
	char	**arg;
	int		i;

	i = 0;
	if (!(arg = ft_strsplit(str,';')))
		error_exit("malloc: Allocation error!", 2);
	while (arg[i])
	{
		if (!(arg[i] = ft_strtrim(arg[i])))
			error_exit("malloc: Allocation error!", 2);
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
		error_exit("malloc: Allocation error!", 2);
	i = 0;
	while (arg[i])
	{
		if (!(tri[i] = ft_strsplit(arg[i], ' ')))
			error_exit("malloc: Allocation error!", 2);
		i++;
	}
	return (tri);
}
