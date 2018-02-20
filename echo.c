/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 14:53:12 by adstan            #+#    #+#             */
/*   Updated: 2018/02/19 18:34:10 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_char_rm(char *str, char c)
{
	int		i;
	int		nr;
	char	*new;

	i = 0;
	nr = 0;
	while (str[i])
	{
		if (str[i] == c)
			nr++;
		i++;
	}
	if (!(new = (char*)ft_memalloc(sizeof(char) * (i + 1 - nr))))
		error_exit("malloc: Allocation error!", 2);
	i = 0;
	nr = 0;
	while (str[i])
	{
		if (str[i] != c)
			new[nr++] = str[i];
		i++;
	}
	return (new);
}


void	echo_builtin(char **arg)
{
	int i;

	i = 1;
	if (arg[i] == NULL)
		write(1,"\n",1);
	else
	{
		while (arg[i])
		{
			arg[i] = ft_char_rm(arg[i], '"');
			i++;
		}
		i = 1;
		while (arg[i])
		{
			ft_putstr(arg[i]);
			ft_putchar(' ');
			i++;
		}
		ft_putchar('\n');
	}
}



