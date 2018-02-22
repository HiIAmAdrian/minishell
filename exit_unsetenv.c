/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_unsetenv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 18:55:31 by adstan            #+#    #+#             */
/*   Updated: 2018/02/22 20:27:00 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_sh(void)
{
	char **clear;

	clear = (char**)ft_memalloc(sizeof(clear));
	if(!(clear[0] = ft_strdup("clear")))
		exit(0);
	clear[1] = NULL;
	free(g_home);
	ft_putendl("\n\x1B[31mExiting...\x1B[0m\n");
	sleep(1);
	bin_exec(clear);
	ft_matrix_clear(clear);
	exit(0);
}

void    error_exit(char *str, int fd)
{
	ft_matrix_clear(g_env);
	free(g_home);
	ft_putendl_fd(str,fd);
	exit(0);
}

void    unsetenv_builtin(char **arg)
{
	int i;

	if (!arg[1])
		ft_putendl_fd("unsetenv: Too few arguments!", 2); 
	else if (arg[2])
		ft_putendl_fd("unsentev: Too many arguments!", 2); 
	else
	{   
		i = search_env(arg[1]);
		while (g_env[i + 1]) 
		{   
			free(g_env[i]);
			if(!(g_env[i] = ft_strdup(g_env[i + 1])))
				error_exit("malloc: Allocation error!", 2); 
			i++;
		}   
		free(g_env[i + 1]);
		g_env[i] = NULL;
	}   
}
