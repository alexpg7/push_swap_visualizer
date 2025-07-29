#include "ps_visualizer.h"

uint32_t rainbow_color(float t)
{
	if (t < 0.0f) t = 0.0f;
	if (t > 1.0f) t = 1.0f;

	float h = t * 300.0f;
	float s = 1.0f;
	float v = 1.0f;
	float c = v * s;
	float x = c * (1 - fabs(fmod(h / 60.0f, 2) - 1));
	float m = v - c;
	float r_prime, g_prime, b_prime;
	if (h < 60) {
		r_prime = c; g_prime = x; b_prime = 0;
	} else if (h < 120) {
		r_prime = x; g_prime = c; b_prime = 0;
	} else if (h < 180) {
		r_prime = 0; g_prime = c; b_prime = x;
	} else if (h < 240) {
		r_prime = 0; g_prime = x; b_prime = c;
	} else if (h < 300) {
		r_prime = x; g_prime = 0; b_prime = c;
	} else {
		r_prime = c; g_prime = 0; b_prime = x;
	}
	uint8_t r = (uint8_t)((r_prime + m) * 255);
	uint8_t g = (uint8_t)((g_prime + m) * 255);
	uint8_t b = (uint8_t)((b_prime + m) * 255);
	return (r << 16) | (g << 8) | b;
}

static int	ft_smallest(t_ps_list *a)
{
	int	small;

	small = ft_atoi(a->content);
	while (a != NULL)
	{
		if (ft_atoi(a->content) < small)
			small = ft_atoi(a->content);
		a = a->next;
	}
	return (small);
}

static int	ft_bigger(t_ps_list *a, int small)
{
	int	bigger;
	int	num;

	bigger = 2147483647;
	while (a != NULL)
	{
		num = ft_atoi(a->content);
		if (num < bigger && num > small)
			bigger = num;
		a = a->next;
	}
	return (bigger);
}

void	ft_rank_list(t_ps_list **a)
{
	t_ps_list	*aux1;
	t_ps_list	*aux2;
	int			size;
	int			i;
	int			small;

	aux1 = *a;
	size = ps_lstsize(aux1);
	i = 0;
	while (++i <= size)
	{
		aux2 = aux1;
		if (i == 1)
			small = ft_smallest(aux2);
		else
			small = ft_bigger(aux2, small);
		while (ft_atoi(aux2->content) != small)
			aux2 = aux2->next;
		aux2->rank = i;
		aux2->color = rainbow_color((float)(i) / (float)(size));
	}
}

int	ft_exit(t_vars *vars, int ret)
{
	if (vars->mlx)
	{
		if (vars->img)
			mlx_destroy_image(vars->mlx, vars->img);
		if (vars->win)
			mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	free(vars->inst0);
	ps_lstclear(&vars->list_a);
	ps_lstclear(&vars->list_b);
	exit(ret);
	return (ret);
}

void	ft_printlist(t_ps_list *list, int mode)
{
	while (list)
	{
		if (mode == 0)
			ft_printf("%s\n", list->content);
		else if (mode == 1)
			ft_printf("%X\n", list->color);
		list = list->next;
	}
}
