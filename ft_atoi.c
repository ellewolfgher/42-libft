#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	neg;
	int	res;
	int	i;

	neg = 1;
	i = 0;
	while (nptr[i] <= 32 || nptr[i] == 127)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			neg = -1;
		i++;
	}

	res = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10;
		res = res + (nptr[i] - 48);
		i++;
	}
	return (res * neg);		
}
