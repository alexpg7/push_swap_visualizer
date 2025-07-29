#include "ps_visualizer.h"

void	ft_fill_list(t_ps_list *list, char **argv, t_vars *vars)
{
	t_ps_list	*first;
	t_ps_list	*new;
	int			i;

	first = list;
	i = 0;
	while (argv[i])
	{
		new = ps_lstnew(argv[i]);
		if (!new)
			ps_lstclear(&first);
		ps_lstadd_back(&first, new);
		i++;
	}
	vars->len = i + 1;
}

int	ft_readinput(char **inst)
{
	char	*read;
	char	*aux;

	read = get_next_line(0);
	if (!read)
		*inst = ft_strjoin(NULL, "B");
	else
		*inst = ft_strjoin("B", read);
	if (!(*inst))
	{
		if (read)
			free(read);
		get_next_line(-1);
		return (-1);
	}
	if (read)
		free(read);
	read = get_next_line(0);
	while (read)
	{
		aux = *inst;
		*inst = ft_strjoin(aux, read);
		free(aux);
		if (!(*inst))
		{
			get_next_line(-1);
			return (-1);
		}
		if (read)
			free(read);
		read = get_next_line(0);
	}
	get_next_line(-1);
	return (0);
}

int	ft_mainmlx2(t_vars *vars)
{
	ft_paintimage(vars);
	mlx_hook(vars->win, 2, 1L<<0, key_hook, vars);
	//mlx_hook(vars->win, 3, 1L<<1, ft_release, vars);
	mlx_hook(vars->win, 17, 0L, ft_exit, vars);
	mlx_loop(vars->mlx);
	return (0);
}

int	ft_mainmlx(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!(vars->mlx))
	{
		perror("mlx init");
		ft_exit(vars, 1);
	}
	vars->win = mlx_new_window(vars->mlx, 2 * X + M1, X, "push_swap Visualizer");
	vars->img = mlx_new_image(vars->mlx, 2 * X + M1, X);
	if (!(vars->win) || !(vars->img))
	{
		perror("mlx error");
		ft_exit(vars, 1);
	}
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_length, &vars->endian);
	if (!(vars->addr) || !(vars->bits_per_pixel) || !(vars->line_length))
	{
		perror("mlx address get");
		ft_exit(vars, 1);
	}
	return (ft_mainmlx2(vars));
}

int	main(int narg, char **argv)
{
	t_ps_list	*list_a;
	t_ps_list	*list_b;
	t_vars		vars;
	char		*inst;

	inst = NULL;
	list_b = NULL;
	vars.list_b = list_b;
	if (narg >= 1)
	{
		if (ft_readinput(&inst) == -1)
			return (1);
		list_a = ps_lstnew(argv[1]);
		if (!list_a)
			return (1);
		ft_fill_list(list_a, argv + 2, &vars);
		ft_rank_list(&list_a);
		vars.list_a = list_a;
		vars.inst = inst + 1;
		vars.inst0 = inst;
		//ft_printlist(list_a, 0);
		return(ft_mainmlx(&vars));
	}
	else
		ft_putstr_fd("Please, input at least 1 number.\n", 2);
	return (1);
}