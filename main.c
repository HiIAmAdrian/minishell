/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 10:58:50 by adstan            #+#    #+#             */
/*   Updated: 2018/02/25 19:18:16 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_env(char **envp)
{
	int i;

	i = 0;
	while (envp[i])
		i++;
	if (!(g_env = (char**)ft_memalloc(sizeof(char*) * (i + 1))))
		error_exit(M_ERROR, 2);
	i = 0;
	while (envp[i])
	{
		if (!(g_env[i] = ft_strdup(envp[i])))
			error_exit(M_ERROR, 2);
		i++;
	}
}

void	signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_putstr("\n");
		display_prompt();
	}
}

void	init(char **envp)
{
	int		i;
	char	**clear;

	init_env(envp);
	i = search_env("HOME");
	g_home = ft_strsub(ft_strdup(g_env[i]), 5, ft_strlen(g_env[i]));
	clear = (char**)ft_memalloc(sizeof(clear));
	if (!(clear[0] = ft_strdup("clear")))
		ft_putchar('\n');
	clear[1] = NULL;
	bin_exec(clear);
	if (clear)
		ft_matrix_clear(clear);
}

int		white_space(char *str)
{
	int i;

	i = 0;
	while (str[i++])
		if (str[i] > ' ')
			return (i);
	return (0);
}

int		main(int argc, char **argv, char **envp)
{
	char	*line;
	char	**arguments;
	char	***tri;

	argc = 1;
	argv[0] = argv[0];
	init(envp);
	while (1)
	{
		signal(SIGINT, signal_handler);
		display_prompt();
		line = read_stdin();
		if ((white_space(line)))
		{
			line = str_replace(line, '\t', ' ');
			arguments = parse_stdin(line);
			if (line)
				free(line);
			tri = parse_arguments(arguments);
			if (arguments)
				ft_matrix_clear(arguments);
			run_commands(tri);
		}
	}
}
