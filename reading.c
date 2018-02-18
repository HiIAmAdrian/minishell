/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 17:06:51 by adstan            #+#    #+#             */
/*   Updated: 2018/02/18 18:20:58 by adstan           ###   ########.fr       */
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
	str = (char*)ft_memalloc(sizeof(char) * i++);
	while ((ret = read(0, buf, 1)) && buf[0] != '\n')
		str = ft_strjoin(str, buf);
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
	arg = ft_strsplit(str,';');
	while (arg[i])
	{
		arg[i] = ft_strtrim(arg[i]);
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
	tri = (char***)ft_memalloc(sizeof(char**) * (i + 1));
	i = 0;
	while (arg[i])
	{
		tri[i] = ft_strsplit(arg[i], ' ');
		i++;
	}
	return (tri);
}
