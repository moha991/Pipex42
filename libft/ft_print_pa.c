/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:17:52 by mfornah           #+#    #+#             */
/*   Updated: 2023/03/14 10:53:52 by mfornah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It takes a string, and prints it to the screen,
 *  while also checking for any format specifiers, and
 * printing the corresponding argument
 * 
 * @param i the index of the string
 * @param count the number of characters printed
 * @param inp the string that is being printed
 * @param argms the va_list that contains the arguments to be printed
 * 
 * @return The number of characters printed.
 */
int	ft_print_pa(int i, int count, const char *inp, va_list argms)
{
	if (!inp)
		return (0);
	while (inp[i] != '\0')
	{
		if (inp[i] == '%')
		{
			count = ft_checkparam(inp, i, count, argms);
			i++;
		}
		else
			count += write(1, &inp[i], 1);
		i++;
	}
	return (count);
}
