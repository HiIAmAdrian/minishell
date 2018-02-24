/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isperfect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:50:53 by adstan            #+#    #+#             */
/*   Updated: 2018/01/07 15:14:33 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int	ft_isperfect(size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (i * i == n)
			return (1);
		i++;
	}
	return (0);
}