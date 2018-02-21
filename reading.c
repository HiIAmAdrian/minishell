/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 17:06:51 by adstan            #+#    #+#             */
/*   Updated: 2018/02/21 19:46:59 by adstan           ###   ########.fr       */
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
	g_pointer = g_history;
	if (!(str = (char*)ft_memalloc(sizeof(char) * i++)))
		error_exit("malloc: Allocation error!", 2);
	while ((ret = read(0, buf, 1)) && buf[0] != '\n')
	{
		if (!(str = ft_strjoin(str, buf)))
			error_exit("malloc: Allocation error!", 2);
		if (ft_strstr(str,"^[[A"))
		{
			ft_putstr_fd("lol",1);
			ft_putstr_fd(g_pointer->prev->str, 1);
			g_pointer = g_pointer->prev;
		}
		else if (ft_strstr(str,"^[[B"))
		{
			ft_putstr_fd(g_pointer->next->str, 1);
			g_pointer = g_pointer->next;
		}
	}
	if (!ret)
	{
		free(str);
		exit(0);
	}
	g_history->next = push(str, g_history);
	g_history = g_history->next;
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
