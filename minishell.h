/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 11:12:19 by adstan            #+#    #+#             */
/*   Updated: 2018/02/24 16:44:26 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/includes/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <signal.h>
# include <term.h>
# include <curses.h>
# define K_TAB 9
# define K_ENTER 10
# define M_ERROR "malloc: allocation error!"
# define U_ERROR "unsetenv: Too few arguments!"
# define UM_ERROR "unsetenv: Too many arguments!"
# define S_ERROR "setenv: Too many arguments!"

char	**g_env;
char	*g_home;

void	display_prompt();
char	*read_stdin();
char	**parse_stdin(char *str);
int		run_commands(char ***arg);
char	***parse_arguments(char **arg);
char	*ft_char_rm(char *str, char c);
void	echo_builtin(char **arg);
void	init_env(char **envp);
void	env_builtin(void);
void	setenv_builtin(char **arg);
void	unsetenv_builtin(char **arg);
void	error_exit(char *str, int fd);
int		search_env(char *str);
void	exit_sh(void);
void	cd_builtin(char **arg);
void	put_env(char *str1, char *str2, int i);
char	*ft_parse_home(char *str);
void	bin_exec(char **arg);
void	cd_builtin2(char *cwd, char **arg);
void	execute_exe(char **arg, int ok);
int		exec_cmd(char *path, char **arg);

#endif
