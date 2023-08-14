/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_putchar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 18:56:06 by mfornah           #+#    #+#             */
/*   Updated: 2023/03/14 10:52:42 by mfornah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It writes a character to the standard output.
 * 
 * @param c the character to print
 * 
 * @return The number of bytes written to the standard output.
 */
int	ft_print_putchar(char c)
{
	return (write(1, &c, 1));
}
