/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 10:58:50 by adstan            #+#    #+#             */
/*   Updated: 2018/02/18 19:03:12 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int argc, char **argv, char **envp)
{
	char *line;
	char **arguments;
	char ***tri;

	while (1)
	{
		display_prompt();
		init_env(envp);
		line = read_stdin();
		arguments = parse_stdin(line);
		tri = parse_arguments(arguments);
		run_commands(tri);
	}
}
