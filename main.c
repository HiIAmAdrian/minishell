/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 10:58:50 by adstan            #+#    #+#             */
/*   Updated: 2018/02/21 20:12:54 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_stack *push(char *s,t_stack *pre)
{
	t_stack *new;

	new = (t_stack*)ft_memalloc(sizeof(t_stack));
	if (!(new->str = ft_strdup(s)))
		ft_putendl_fd("minishell: push to history failed!", 2);
	new->prev = pre;
	new->next = NULL;
	return (new);
}

void	signal_handler(int signo)
{
	//asta dc nu omoara procesul pe cand celalalt sig handler il omoara
	if (signo == SIGINT)
	{
		ft_putstr("\n");
		display_prompt();
	}
}

int		main(int argc, char **argv, char **envp)
{
	char	*line;
	char	**arguments;
	char	***tri;
	int		i;
	t_stack	*start;
	t_stack *new;

	g_history = (t_stack*)ft_memalloc(sizeof(t_stack));
	start = g_history;
	init_env(envp);
	i = search_env("HOME");
	g_home = ft_strsub(ft_strdup(g_env[i]), 5, ft_strlen(g_env[i]));
	while (1)
	{
		signal(SIGINT, signal_handler);
		display_prompt();
		line = read_stdin();
		arguments = parse_stdin(line);
		tri = parse_arguments(arguments);
		run_commands(tri);

		//		new = start;
		//		while (new)
		//		{
		//			ft_putendl(new->str);
		//			new = new->next;
		//		}
	}
}
