/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:36:39 by mfornah           #+#    #+#             */
/*   Updated: 2023/03/14 10:53:07 by mfornah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 90) || (c >= 48 && c <= 57))
		return (1);
	return (0);
}

/*int	main(void)
{
	int	str;

	str = 'a';

	ft_isalnum(str);

	printf("%d",ft_isalnum(str));

}
*/