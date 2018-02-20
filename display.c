/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 10:57:45 by adstan            #+#    #+#             */
/*   Updated: 2018/02/20 19:19:01 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_parse_home(char *str)
{
	char	*new;

	if ((ft_strnequ(str, g_home, ft_strlen(g_home))))
	{
		if (!(new = ft_strjoin("~", ft_strsub(str, ft_strlen(g_home),
					(ft_strlen(str) - ft_strlen(g_home))))))
			error_exit("malloc: Allocation error!", 2);
	}
	return (new);
}

void	display_prompt()
{
	char	*cwd;
	char	buf[4097];

	cwd = getcwd(buf,4096);
	if (ft_strlen(cwd) >= ft_strlen(g_home))
		cwd = ft_parse_home(cwd);
	ft_putstr("\033[1m\x1b[36m");
	ft_putstr(cwd);
	free(cwd);
	ft_putstr("\x1b[0m");
	ft_putchar(' ');
	ft_putstr("$> ");
}

