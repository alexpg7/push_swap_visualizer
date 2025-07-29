#include "ps_visualizer.h"

void	pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + y * vars->line_length + x * vars->bits_per_pixel / 8;
	*(unsigned int *)dst = color;
}

unsigned int	ft_searchcolor(t_ps_list *list, int index, int *size)
{
	int	i;

	i = 0;
	*size = 0;
	while (list && i < index)
	{
		list = list->next;
		i++;
	}
	if (i == index && list)
	{
		*size = list->rank;
		return(list->color);
	}
	return (0x000000);
}

unsigned int	ft_paintlist(t_ps_list *list, int len, int i)
{
	if (list)
	{
		if (i * len / X <= list->rank - 1)
			return (list->color);
	}
	return (0x000000);
}

void	ft_paintimage(t_vars *vars)
{
	int				i;
	int				j;
	int				k;
	int				len;
	t_ps_list		*list;
	unsigned int	color;

	i = 0;
	color = 0x000000;
	len = vars->len;
	while (i <= X)
	{
		j = 0;
		k = 1;
		list = vars->list_a;
		while (j < X)
		{
			if (j > k * X / len)
			{
				if (list)
					list = list->next;
				k++;
			}
			color = ft_paintlist(list, vars->len, i);
			pixel_put(vars, i, j, color);
			j++;
		}
		i++;
	}
	while (i <= X + M1 && i > X)
	{
		j = 0;
		while (j < X)
		{
			color = 0xFFFFFF;
			pixel_put(vars, i, j, color);
			j++;
		}
		i++;
	}
	while (i < 2 * X + M1 && i > X + M1)
	{
		j = 0;
		list = vars->list_b;
		k = 1;
		while (j < X)
		{
			if (j > k * X / len)
			{
				if (list)
					list = list->next;
				k++;
			}
			color = ft_paintlist(list, vars->len, i - X - M1);
			pixel_put(vars, i, j, color);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}