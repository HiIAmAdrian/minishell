/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 10:58:50 by adstan            #+#    #+#             */
/*   Updated: 2018/02/20 18:14:30 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int argc, char **argv, char **envp)
{
	char	*line;
	char	**arguments;
	char	***tri;
	int		i;

	init_env(envp);
	i = search_env("HOME");
	g_home = ft_strsub(ft_strdup(g_env[i]), 5, ft_strlen(g_env[i]));
	while (1)
	{
		display_prompt();
		line = read_stdin();
		arguments = parse_stdin(line);
		tri = parse_arguments(arguments);
		run_commands(tri);
	}
	free(line);
	ft_strdel(arguments);
	ft_strdel(g_env);
	i = 0;
	while (tri[i])
	{
		ft_strdel(tri[i]);
		i++;
	}
	free(g_home);
}
