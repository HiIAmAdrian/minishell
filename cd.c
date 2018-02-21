/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 12:51:57 by adstan            #+#    #+#             */
/*   Updated: 2018/02/21 20:12:52 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_dir(char **arg, char *cwd)
{
	int		i;
	char	buf[1025];

	if (!(chdir(arg[1])))
	{
		i = search_env("OLDPWD");
		put_env("OLDPWD", cwd, i);
		i = search_env("PWD");
		cwd = getcwd(buf, 1024);
		put_env("PWD", cwd, i);
	}
	else
	{
		if (access(arg[1], F_OK))
			ft_putstr("cd: no such file or directory: ");
		else if (access(arg[1], X_OK))
			ft_putstr("cd: permission denied: ");
		else 
			ft_putstr("cd: not a directory: ");
		ft_putendl(arg[1]);
	}
}


void	cd_builtin(char **arg)
{
	int		i;
	char	*cwd;
	char	buf[1025];

	cwd = getcwd(buf, 1024);
	if (arg[1] == NULL || ft_strequ(arg[1], "~") ||
			ft_strequ("--", arg[1]))
	{
		i = search_env("OLDPWD");
		put_env("OLDPWD", cwd, i);
		i = search_env("PWD");
		put_env("PWD", g_home, i);
		chdir(g_home);
	}
	else if (arg[1][0] == '-' && !arg[1][1])
	{
		i = search_env("OLDPWD");
		if (i == -1)
			ft_putendl_fd("cd: YOU DELETED OLDPWD YOU DUMBASS :))", 2);
		else
		{
			ft_putendl(ft_parse_home(ft_strchr(g_env[i], '/')));
			chdir(ft_strchr(g_env[i], '/'));
			put_env("OLDPWD", cwd, i);
			cwd = getcwd(buf, 1024);
			i = search_env("PWD");
			put_env("PWD", cwd, i);
		}
	}
	else
		change_dir(arg, cwd);
}

void	process_signal(int signo)
{
	//dc asta omoara procesul pe cand celalalt sig handler nu il omoara
	if (signo == SIGINT)
		ft_putstr("\n");
}

int		exec_cmd(char *path, char **arg)
{
	pid_t pid;
	pid	= fork();
	signal(SIGINT, process_signal);
	if (pid < 0)
	{
		free(path);
		ft_putendl_fd("Fork failed!", 2);
		return (-1);
	}
	else if (!pid)
		execve(path, arg, g_env);
	wait(&pid);
	if (path)
		free(path);
	return (0);
}

int		isThereEx(char *str, char **arg)
{
	DIR				*dir;
	struct	stat	st;
	struct	dirent	*ret;
	int				ok;

	ok = 0;
	if ((dir = opendir(str)))
	{
		while ((ret = readdir(dir)))
		{
			if (ft_strequ(arg[0], ret->d_name))
			{
				ok = 1;
				if ((lstat(ft_strjoin(ft_strjoin(str, "/"), ret->d_name), &st)) == -1)
					ft_putendl_fd("lstat: error", 2);
				if (st.st_mode & S_IFREG)
				{
					if (st.st_mode & S_IXOTH)
						return(exec_cmd(ft_strjoin(ft_strjoin(str, "/"), ret->d_name), arg));
					else
					{
						ft_putendl_fd("Permission denied!", 2);
						return (0);
					}
				}
			}
		}
	}
	return (1);
}

void	bin_exec(char **arg)
{
	char	**paths;
	int		i;
	int		ok;

	ok = 0;
	paths = ft_strsplit(g_env[search_env("PATH")] + 5, ':');
	i = 0;
	while(paths[i])
	{
		if ((isThereEx(paths[i], arg)) == 0)
			ok = 1;
		i++;
	}
	if (!ok)
	{
		ft_putstr_fd(arg[0], 2);
		ft_putendl_fd(": command not found!", 2);
	}
}
