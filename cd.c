/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 12:51:57 by adstan            #+#    #+#             */
/*   Updated: 2018/02/24 18:28:07 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_dir(char *str, char *cwd)
{
	int		i;
	char	buf[1025];

	ft_putendl(str);
	if (!(chdir(str)))
	{
		i = search_env("OLDPWD");
		put_env("OLDPWD", cwd, i);
		i = search_env("PWD");
		cwd = getcwd(buf, 1024);
		put_env("PWD", cwd, i);
	}
	else
	{
		if (access(str, F_OK))
			ft_putstr("cd: no such file or directory: ");
		else if (access(str, X_OK))
			ft_putstr("cd: permission denied: ");
		else
			ft_putstr("cd: not a directory: ");
		ft_putendl(str);
	}
}

int		arg_length(char **arg)
{
	int i;

	i = 0;
	while (arg[i])
		i++;
	return (i);
}

void	cd_builtin(char **arg)
{
	int		i;
	char	*cwd;
	char	buf[1025];

	cwd = getcwd(buf, 1024);
	if (arg_length(arg) > 2)
	{
		ft_putendl_fd("cd: too many arguments!", 2);
		return ;
	}
	else if (arg[1] && ft_strchr(arg[1], '~'))
	{
		if (!(arg[1] = ft_strjoin(g_home,
						ft_strsub(arg[1], 1, ft_strlen(arg[1])))))
			ft_putendl_fd(M_ERROR, 2);
	}
	else if (arg_length(arg) == 1 || ft_strequ("--", arg[1]))
			
	{
	ft_putnbr(arg_length(arg));
		i = search_env("OLDPWD");
		put_env("OLDPWD", cwd, i);
		i = search_env("PWD");
		put_env("PWD", g_home, i);
		chdir(g_home);
	}
	else
		cd_builtin2(cwd, arg);
}

void	cd_builtin2(char *cwd, char **arg)
{
	char	buf[1025];
	int		i;

	if (arg[1][0] == '-' && !arg[1][1])
	{
		i = search_env("OLDPWD");
		if (i == -1)
			ft_putendl_fd("cd: YOU DELETED OLDPWD YOU DUMBASS :))", 2);
		else
		{
			if (ft_strstr(g_env[i], g_home))
				ft_putendl(ft_parse_home(ft_strchr(g_env[i], '/')));
			else
				ft_putendl(ft_strchr(g_env[i], '/'));
			chdir(ft_strchr(g_env[i], '/'));
			put_env("OLDPWD", cwd, i);
			cwd = getcwd(buf, 1024);
			i = search_env("PWD");
			put_env("PWD", cwd, i);
		}
	}
	else
		change_dir(arg[1], cwd);
}

void	execute_exe(char **arg, int ok)
{
	char		*cwd;
	char		buf[1025];
	struct stat	st;

	if (!ok && (!(lstat(arg[0], &st))))
	{
		if ((S_ISDIR(st.st_mode)))
		{
			cwd = getcwd(buf, 1024);
			ok = 1;
			change_dir(arg[0], cwd);
			return ;
		}
		if (st.st_mode & S_IXUSR)
		{
			ok = 1;
			exec_cmd(arg[0], arg);
			return ;
		}
	}
	if (!ok)
	{
		ft_putstr_fd(arg[0], 2);
		ft_putendl_fd(": command not found!", 2);
	}
}
