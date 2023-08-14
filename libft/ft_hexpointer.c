/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:09:39 by mfornah           #+#    #+#             */
/*   Updated: 2023/03/14 10:53:03 by mfornah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It prints a pointer in hexadecimal format
 * 
 * @param pnt the pointer to print
 * 
 * @return The number of characters printed.
 */
int	ft_hexpointer(unsigned long pnt)
{
	int	count;

	count = 0;
	count += write(1, "0x", 2);
	if (pnt != 0)
		count += ft_printf_hexlong(pnt, HEXADECIMAL_MIN);
	else
		count += write (1, "0", 1);
	return (count);
}
