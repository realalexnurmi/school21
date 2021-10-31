#include "philo.h"
#include <stdio.h>

t_ms	get_current_ms(void)
{
	struct timeval time_of_day;

	gettimeofday(&time_of_day, NULL);
	return (time_of_day.tv_sec * 1000 + time_of_day.tv_usec / 1000);	
}

int main(void)
{
	t_ms s = get_current_ms();
	t_ms now = 0;

	while (now < 10)
	{
		if (get_current_ms() - s != now)
			printf("%llu\n", now = get_current_ms() - s);
	}
}