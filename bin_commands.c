/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 14:36:05 by adstan            #+#    #+#             */
/*   Updated: 2018/02/24 16:44:42 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	process_signal(int signo)
{
	if (signo == SIGINT)
		ft_putstr("\n");
}

int		exec_cmd(char *path, char **arg)
{
	pid_t pid;

	pid = fork();
	signal(SIGINT, process_signal);
	if (pid < 0)
	{
		if (path)
			free(path);
		ft_putendl_fd("minishell: fork failed!", 2);
		return (-1);
	}
	else if (!pid)
		if ((execve(path, arg, g_env)) == -1)
		{
			ft_putendl_fd("minishell: execve failed!", 2);
			return (-1);
		}
	wait(&pid);
	if (path)
		free(path);
	return (0);
}

int		is_there_ex1(struct dirent *ret, char **arg, char *str)
{
	struct stat		st;

	if (ft_strequ(arg[0], ret->d_name))
	{
		if ((lstat(ft_strjoin(
							ft_strjoin(str, "/"), ret->d_name), &st)) == -1)
			ft_putendl_fd("minishell: lstat error", 2);
		if (st.st_mode & S_IFREG)
		{
			if (st.st_mode & S_IXOTH)
				return (exec_cmd(ft_strjoin(
								ft_strjoin(str, "/"), ret->d_name), arg));
			else
			{
				ft_putendl_fd("Permission denied!", 2);
				return (-1);
			}
		}
	}
	return (-100);
}

int		is_there_ex(char *str, char **arg)
{
	DIR				*dir;
	struct dirent	*ret;
	int				ok;

	if ((dir = opendir(str)))
		while ((ret = readdir(dir)))
			if ((ok = is_there_ex1(ret, arg, str)) != -100)
				return (ok);
	closedir(dir);
	return (1);
}

void	bin_exec(char **arg)
{
	char		**paths;
	int			i;
	int			ok;

	ok = 0;
	paths = ft_strsplit(g_env[search_env("PATH")] + 5, ':');
	i = 0;
	while (paths[i] && !ok)
	{
		if ((is_there_ex(paths[i], arg)) == 0)
			ok = 1;
		i++;
	}
	execute_exe(arg, ok);
}
