/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 12:24:18 by adstan            #+#    #+#             */
/*   Updated: 2018/02/25 19:15:45 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		run_commands(char ***arg)
{
	int i;

	i = -1;
	while (arg[++i])
	{
		if ((ft_strequ(arg[i][0], "cd")))
			cd_builtin(arg[i]);
		else if ((ft_strequ(arg[i][0], "echo")))
			echo_builtin(arg[i]);
		else if ((ft_strequ(arg[i][0], "env")))
			env_builtin();
		else if ((ft_strequ(arg[i][0], "setenv")))
			setenv_builtin(arg[i]);
		else if ((ft_strequ(arg[i][0], "unsetenv")))
			unsetenv_builtin(arg[i]);
		else if ((ft_strequ(arg[i][0], "exit")))
			exit_sh();
		else
			bin_exec(arg[i]);
	}
	return (0);
}
