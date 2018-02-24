/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:34:46 by adstan            #+#    #+#             */
/*   Updated: 2018/01/07 15:10:57 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int	ft_power(int n, size_t pow)
{
	if (pow)
		return (n * ft_power(n, pow - 1));
	else
		return (1);
}