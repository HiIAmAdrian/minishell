/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 10:57:45 by adstan            #+#    #+#             */
/*   Updated: 2018/02/25 18:32:03 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_parse_home(char *str)
{
	char	*new;

	new = NULL;
	ft_strnequ(str, g_home, ft_strlen(g_home));
	if (!(new = ft_strjoin("~", ft_strsub(str, ft_strlen(g_home),
						(ft_strlen(str) - ft_strlen(g_home))))))
		error_exit(M_ERROR, 2);
	return (new);
}

void	display_prompt(void)
{
	char	*cwd;
	char	buf[4097];
	int		parsed;

	parsed = 0;
	cwd = getcwd(buf, 4096);
	if (ft_strlen(cwd) >= ft_strlen(g_home))
	{
		cwd = ft_parse_home(cwd);
		parsed = 1;
	}
	ft_putstr("\033[1m\x1b[36m");
	ft_putstr(cwd);
	if (parsed)
		free(cwd);
	ft_putstr("\x1b[0m");
	ft_putchar(' ');
	ft_putstr("$> ");
}
