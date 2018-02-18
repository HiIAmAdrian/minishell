/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 18:18:22 by adstan            #+#    #+#             */
/*   Updated: 2018/02/18 19:02:44 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_env(char **envp)
{
	int i;

	i = 0;
	while (envp[i])
		i++;
	g_env = (char**)ft_memalloc(sizeof(char*) * (i + 1));
	i = 0;
	while (envp[i])
	{
		if (!(g_env[i] = strdup(envp[i])))
			exit(0);
		i++;
	}
}

void	env_builtin(void)
{
	int i;

	i = 0;
	while (g_env[i])
	{
		ft_putendl(g_env[i]);
		i++;
	}
}
