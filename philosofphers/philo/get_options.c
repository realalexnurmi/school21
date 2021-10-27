#include "philo.h"

static int	ft_isspace(int c)
{
	int	ret;

	ret = FALSE;
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r')
		ret = TRUE;
	return (ret);
}

static int	ft_isdigit(int c)
{
	int	ret;

	ret = FALSE;
	if ((c >= '0') && (c <= '9'))
		ret = TRUE;
	return (ret);
}

static int	ft_atoi(const char *str)
{
	long long int	ret;
	char			sign;

	ret = 0;
	while (*str && ft_isspace((int)*str))
		str++;
	sign = 1 - 2 * (*str == '-');
	str += (*str == '-' || *str == '+');
	while ((*str && ft_isdigit((int)*str)))
	{
		ret = ret * 10 + ((*str - '0') * sign);
		if (ret && (ret * sign < 0))
		{
			ret = -1 * (sign > 0);
			break ;
		}
		str++;
	}
	return ((int)ret);
}

static int	options_is_incorrect(int count, t_options *options)
{
	int	ret;

	ret = FALSE;
	if (options->number_of_philosophers <= 0
		|| options->time_to_die <= 0
		|| options->time_to_eat <= 0
		|| options->time_to_sleep <= 0
		|| (count == 5 && options->number_of_times_each_philo_must_eat <= 0))
		ret = TRUE;
	return (ret);
}

int	get_options(int count_options, char **value_options, t_data *data)
{
	int	ret;

	ret = EXIT_SUCCESS;
	if (count_options < 4 || count_options > 5)
		ret = EXIT_FAILURE;
	else
	{
		data->options.number_of_philosophers = ft_atoi(value_options[1]);
		data->options.time_to_die = ft_atoi(value_options[2]);
		data->options.time_to_eat = ft_atoi(value_options[3]);
		data->options.time_to_sleep = ft_atoi(value_options[4]);
		if (count_options == 5)
			data->options.number_of_times_each_philo_must_eat = \
			ft_atoi(value_options[5]);
		if (options_is_incorrect(count_options, &(data->options)))
			ret = EXIT_FAILURE;
	}
	return (ret);
}
