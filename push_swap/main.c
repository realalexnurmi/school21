#include <stdio.h>
#include <stdlib.h>

typedef enum	e_name_command
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr,
	end,
	all = end
}				t_name_command;

typedef enum	e_type_command
{
	swap_t,
	push_t,
	rotate_t,
	reverse_rotate_t
}				t_type_command;

typedef enum	e_target_command
{
	stack_a,
	stack_b,
	both_stack
}				t_target_command;

typedef struct	s_command
{
	char				act[3];
	t_type_command		command_type;
	t_target_command	command_target;
}				t_command;

typedef struct	s_stacks
{
	int	*top_stack_a;
	int *top_stack_b;
}				t_stacks;



// static char list_command[all];

int main()
{
	int		exit_param = 0;
	char	*str;
	while (!exit_param)
	{
		scanf();
	}
	exit(EXIT_SUCCESS);
}