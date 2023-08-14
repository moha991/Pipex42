/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_putstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 20:48:08 by mfornah           #+#    #+#             */
/*   Updated: 2023/03/14 10:52:20 by mfornah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It prints a string to the standard output
 * 
 * @param str The string to print.
 * 
 * @return The number of characters printed.
 */
int	ft_print_putstr(const char *str)
{
	int	i;
	int	len;

	if (!str)
		return (write (1, "(null)", 6));
	i = 0;
	len = ft_strlen2(str);
	while (i < len)
	{
		ft_print_putchar(str[i]);
		i++;
	}
	return (i);
}
