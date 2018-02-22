/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 10:58:50 by adstan            #+#    #+#             */
/*   Updated: 2018/02/22 20:23:12 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_handler(int signo)
{
	//asta dc nu omoara procesul pe cand celalalt sig handler il omoara
	if (signo == SIGINT)
	{
		ft_putstr("\n");
		display_prompt();
	}
}

void	init(char **envp)
{
	char	**clear;
	int		i;

	init_env(envp);
	i = search_env("HOME");
	g_home = ft_strsub(ft_strdup(g_env[i]), 5, ft_strlen(g_env[i]));
	clear = (char**)ft_memalloc(sizeof(clear));
	if(!(clear[0] = ft_strdup("clear")))
		ft_putchar('\n');
	clear[1] = NULL;
	bin_exec(clear);
}


int		main(int argc, char **argv, char **envp)
{
	char	*line;
	char	**arguments;
	char	***tri;
	int		i;

	init(envp);
	while (1)
	{
		signal(SIGINT, signal_handler);
		display_prompt();
		if (line)
			free(line);
		line = read_stdin();
		if (arguments)
			ft_matrix_clear(arguments);
		arguments = parse_stdin(line);
		i = 0;
		if (tri)
		{
			ft_matrix_clear(tri[i]);
			i++;
		}
		tri = parse_arguments(arguments);
		run_commands(tri);
	}
}
