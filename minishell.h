/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 11:12:19 by adstan            #+#    #+#             */
/*   Updated: 2018/02/21 19:45:02 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <signal.h>

typedef	struct 		s_stack
{
	char			*str;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

char	**g_env;
char	*g_home;
t_stack	*g_history;
t_stack *g_pointer;

t_stack *push(char *s, t_stack *pre);
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
# endif
