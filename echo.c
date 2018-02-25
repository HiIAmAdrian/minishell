/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 14:53:12 by adstan            #+#    #+#             */
/*   Updated: 2018/02/25 18:58:35 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo_builtin(char **arg)
{
	int i;

	i = -1;
	if (arg[1] == NULL)
		write(1, "\n", 1);
	else
	{
		while (arg[++i])
			arg[i] = ft_char_rm(arg[i], '"');
		i = 1;
		while (arg[i])
		{
			if (arg[i][0] == '$')
				if (search_env(&arg[i][1]) == -1)
					ft_putchar('\n');
				else
					ft_putstr(ft_strchr(g_env[search_env(&arg[i][1])], '=')
							+ 1);
			else
				ft_putstr(arg[i]);
			ft_putchar(' ');
			i++;
		}
		ft_putchar('\n');
	}
}
