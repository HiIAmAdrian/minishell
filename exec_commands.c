/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 12:24:18 by adstan            #+#    #+#             */
/*   Updated: 2018/02/18 19:00:40 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		run_commands(char ***arg)
{
	int i;

	i = 0;
	while (arg[i])
	{
		/*if ((ft_strnequ(arg[i][0], "cd", 2)))
			cd_builtin(arg[i]);*/
		 if ((ft_strnequ(arg[i][0], "echo", 4)))
			echo_builtin(arg[i]);
		else if ((ft_strnequ(arg[i][0], "env", 3)))
			env_builtin();
	/*	else if ((ft_strnequ(arg[i][0], "setenv", 6)))
			setenv_builtin(arg[i]);
		else if ((ft_strnequ(arg[i][0], "unsetenv", 8)))
			unsetenv_builtin(arg[i]);
		else if ((ft_strnequ(arg[i][0], "exit", 4)))
			exit_builtin(arg[i]);*/
		 else
		 {
			 ft_putstr("minishell: command not found: ");
			 ft_putendl(arg[i][0]);
		 }
		i++;
	}
	return(0);
}
