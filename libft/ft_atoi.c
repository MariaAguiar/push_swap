/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnascime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 17:34:29 by mnascime          #+#    #+#             */
/*   Updated: 2022/04/03 17:34:33 by mnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "libft.h"

int	ft_atoi(const char *str)
{
	int			sign;
	long long	value;

	sign = 1;
	value = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
		sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		value = value * 10 + (*str++ - '0');
	if ((value * sign) > 2147483647 || (value * sign) < -2147483648)
	{
		if (sign == -1)
			return (0);
		return (-1);
	}
	return (value * sign);
}
