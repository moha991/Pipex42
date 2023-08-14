/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:06:44 by mfornah           #+#    #+#             */
/*   Updated: 2023/03/14 10:55:34 by mfornah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen2(const char *str)
{
	unsigned long int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}