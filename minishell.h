/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 11:12:19 by adstan            #+#    #+#             */
/*   Updated: 2018/02/25 19:02:16 by adstan           ###   ########.fr       */
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
char	*ft_char_rm(char *str, char c);

/*
** set_env.c
*/

void	env_builtin(void);
int		search_env(char *str);
void	init_free_env(char *str);
void	put_env(char *str1, char *str2, int i);
void	setenv_builtin(char **arg);

/*
** bin_commands.c
*/

void	process_signal(int signo);
int		exec_cmd(char *path, char **arg);
int		is_there_ex1(struct dirent *ret, char **arg, char *str);
int		is_there_ex(char *str, char **arg);
void	bin_exec(char **arg);

/*
** cd.c
*/

void	change_dir(char *str, char *cwd);
int		arg_length(char **arg);
void	cd_builtin(char **arg);
void	cd_builtin2(char *cwd, char **arg);
void	execute_exe(char **arg, int ok);

/*
** display.c
*/

char	*ft_parse_home(char *str);
void	display_prompt(void);

/*
** echo.c
*/

void	echo_builtin(char **arg);

/*
** exec_commands.c
*/

int		run_commands(char ***arg);

/*
** exit_unsetenv.c
*/

void	exit_sh(void);
void	error_exit(char *str, int fd);
void	unsetenv_builtin(char **arg);

/*
** main.c
*/

int		white_space(char *str);
void	init(char **envp);
void	signal_handler(int signo);
void	init_env(char **envp);

/*
** reading.c
*/

int		put_stdin(unsigned int key);
char	*read_stdin(void);
char	*str_replace(char *str, char c, char r);
char	**parse_stdin(char *str);
char	***parse_arguments(char **arg);

#endif
