/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 18:18:22 by adstan            #+#    #+#             */
/*   Updated: 2018/02/24 15:46:04 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int		search_env(char *str)
{
	int i;

	i = 0;
	while (g_env[i])
	{
		if (ft_strnequ(g_env[i], str, ft_strlen(str)))
			return (i);
		i++;
	}
	return (-1);
}

void	init_free_env(char *str)
{
	int i;

	i = search_env(str);
	if (i != -1)
	{
		if (g_env[i])
			free(g_env[i]);
		if (!(g_env[i] = ft_strdup(str)))
			error_exit(M_ERROR, 2);
		if (!(g_env[i] = ft_strjoin(g_env[i], "=")))
			error_exit(M_ERROR, 2);
	}
	else
	{
		i = 0;
		while (g_env[i])
			i++;
		g_env[i + 1] = NULL;
		if (!(g_env[i] = ft_strdup(str)))
			error_exit(M_ERROR, 2);
		if (!(g_env[i] = ft_strjoin(g_env[i], "=")))
			error_exit(M_ERROR, 2);
	}
}

void	put_env(char *str1, char *str2, int i)
{
	if (g_env[i])
		free(g_env[i]);
	if (!(g_env[i] = ft_strjoin(str1, "=")))
		error_exit(M_ERROR, 2);
	if (!(g_env[i] = ft_strjoin(g_env[i], str2)))
		error_exit(M_ERROR, 2);
}

void	setenv_builtin(char **arg)
{
	int i;

	if (arg[1] == NULL)
		env_builtin();
	else if (arg[2] == NULL)
		init_free_env(arg[1]);
	else if (arg[3] != NULL)
		ft_putendl_fd(S_ERROR, 2);
	else if ((i = search_env(arg[1])) != -1)
		put_env(arg[1], arg[2], i);
	else if (i == -1)
	{
		i = 0;
		while (g_env[i])
			i++;
		if (!(g_env[i] = ft_strjoin(arg[1], "=")))
			error_exit(M_ERROR, 2);
		if (!(g_env[i] = ft_strjoin(g_env[i], arg[2])))
			error_exit(M_ERROR, 2);
		g_env[i + 1] = NULL;
	}
}
