#include "ps_visualizer.h"

void	ft_nextop(char **inst)
{
	while (**inst && **inst != '\n')
		*inst = *inst + 1;
	if (**inst == '\n')
		*inst = *inst + 1;
}

void	ft_prevop(char **inst)
{
	*inst = *inst - 1;
	if (**inst == 'B')
		return ;
	*inst = *inst - 1;
	while (**inst && **inst != '\n' && **inst != 'B')
		*inst = *inst - 1;
	if (**inst == '\n' || **inst == 'B')
		*inst = *inst + 1;
}

void	ft_operation2(char *inst, t_ps_list **a, t_ps_list **b)
{
	if (ft_strncmp(inst, "ss\n", 3) == 0)
	{
		c_swap(a);
		c_swap(b);
	}
	else if (ft_strncmp(inst, "rr\n", 3) == 0)
	{
		c_rotate(a);
		c_rotate(b);
	}
	else if (ft_strncmp(inst, "rrr\n", 4) == 0)
	{
		c_rrotate(a);
		c_rrotate(b);
	}
}

void	ft_operationprev(char *inst, t_ps_list **a, t_ps_list **b)
{
	if (ft_strncmp(inst, "sa\n", 3) == 0)
		c_swap(a);
	else if (ft_strncmp(inst, "sb\n", 3) == 0)
		c_swap(b);
	else if (ft_strncmp(inst, "pa\n", 3) == 0)
		c_push(b, a);
	else if (ft_strncmp(inst, "pb\n", 3) == 0)
		c_push(a, b);
	else if (ft_strncmp(inst, "ra\n", 3) == 0)
		c_rrotate(a);
	else if (ft_strncmp(inst, "rb\n", 3) == 0)
		c_rrotate(b);
	else if (ft_strncmp(inst, "rra\n", 4) == 0)
		c_rotate(a);
	else if (ft_strncmp(inst, "rrb\n", 4) == 0)
		c_rotate(b);
	else
		ft_operation2(inst, a, b);
}

void	ft_operation(char *inst, t_ps_list **a, t_ps_list **b)
{
	if (ft_strncmp(inst, "sa\n", 3) == 0)
		c_swap(a);
	else if (ft_strncmp(inst, "sb\n", 3) == 0)
		c_swap(b);
	else if (ft_strncmp(inst, "pa\n", 3) == 0)
		c_push(a, b);
	else if (ft_strncmp(inst, "pb\n", 3) == 0)
		c_push(b, a);
	else if (ft_strncmp(inst, "ra\n", 3) == 0)
		c_rotate(a);
	else if (ft_strncmp(inst, "rb\n", 3) == 0)
		c_rotate(b);
	else if (ft_strncmp(inst, "rra\n", 4) == 0)
		c_rrotate(a);
	else if (ft_strncmp(inst, "rrb\n", 4) == 0)
		c_rrotate(b);
	else
		ft_operation2(inst, a, b);
}

void	ft_readnext(t_vars *vars)
{
	if (*vars->inst == 'B')
		vars->inst = vars->inst + 1;
	ft_operation(vars->inst, &vars->list_a, &vars->list_b);
	ft_nextop(&vars->inst);
}

void	ft_readprev(t_vars *vars)
{
	if (*vars->inst == 'B')
		return ;
	ft_prevop(&vars->inst);
	ft_operationprev(vars->inst, &vars->list_a, &vars->list_b);
}