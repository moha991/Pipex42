/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:18:14 by mfornah           #+#    #+#             */
/*   Updated: 2022/09/22 11:49:54 by mfornah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isdigit(int str)
{
	if (str >= 48 && str <= 57)
		return (1);
	return (0);
}
/*
int	main(void)
{
	int	str;

	str = 'a';

	ft_isdigit(str);

	printf("%d",ft_isdigit(str));

}
*/