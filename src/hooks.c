#include "ps_visualizer.h"

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == RIGHT)
	{
		ft_readnext(vars);
		ft_paintimage(vars);
	}
	else if (keycode == LEFT)
	{
		ft_readprev(vars);
		ft_paintimage(vars);
	}
	return (0);
}
