/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 11:12:19 by adstan            #+#    #+#             */
/*   Updated: 2018/02/18 19:00:20 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>


char	**g_env;

void	display_prompt();
char	*read_stdin();
char	**parse_stdin(char *str);
int		run_commands(char ***arg);
char	***parse_arguments(char **arg);
char	*ft_char_rm(char *str, char c);
void	echo_builtin(char **arg);
void	init_env(char **envp);
void	env_builtin(void);

# endif
