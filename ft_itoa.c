#include "libft.h"

char	*ft_itoa(int n)
{
	int		i;
	int 	aux;
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
	while (i >= 0)
	{
		chr[i] = aux % 10 + 48;
		aux = aux / 10;
		i--;
	}
	return (chr);
}
