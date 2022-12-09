#include "checker.h"

int	ft_is_number(char c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

int	ft_checkinput_nbrs(int argc, char **argv)
{
	int	i;
	int	b;

	i = 0;
	b = 1;
	while (b < argc)
	{
		if (argv[b][0] == '\0')
			return (1);
		if ((argv[b][i] == '-' || argv[b][i] == '+')
		&& ft_is_number(argv[b][i + 1]) == 1)
			i++;
		while (argv[b][i])
		{
			if (ft_is_number(argv[b][i]) == 0)
				return (1);
			i++;
		}
		i = 0;
		b++;
	}
	return (0);
}
