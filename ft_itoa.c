/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:15:28 by ewolfghe          #+#    #+#             */
/*   Updated: 2022/09/05 22:27:49 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		i;
	int		aux;
	char	*chr;

	aux = n;
	i = 1;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	chr = malloc(i + 1);
	chr[i] = '\0';
	i--;
	if (n < 0)
	{
		chr[i] = '-';
		ft_itoa(n * -1);
	}
	while (i >= 0)
	{
		chr[i] = aux % 10 + 48;
		aux = aux / 10;
		i--;
	}
}
