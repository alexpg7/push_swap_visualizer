#include "../lib/Libft/libft.h"
# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <math.h>

//screen disposition
#define X 800
#define M1 20

//keycodes
#define RIGHT 65363
#define LEFT 65361

typedef struct ps_list
{
	void			*content;
	int				rank;
	unsigned int	color;
	struct ps_list	*next;
}	t_ps_list;

typedef struct s_vars
{
	t_ps_list	*list_a;
	t_ps_list	*list_b;
	char		*inst;
	char		*inst0;
	int			len;
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_vars;

// PS_LIST
t_ps_list	*ps_lstnew(void *content);
void		ps_lstadd_front(t_ps_list **lst, t_ps_list *new);
int			ps_lstsize(t_ps_list *lst);
t_ps_list	*ps_lstlast(t_ps_list *lst);
void		ps_lstadd_back(t_ps_list **lst, t_ps_list *new);
void	ps_lstdelone(t_ps_list *lst);
void	ps_lstclear(t_ps_list **lst);
void		ps_lstiter(t_ps_list *lst, void (*f)(void *));
t_ps_list	*ps_lstmap(t_ps_list *lst, void *(*f)(void *));

// UTILS
int	ft_exit(t_vars *vars, int ret);
void	ft_rank_list(t_ps_list **a);
void	ft_printlist(t_ps_list *list, int mode);

// HOOKS
int	key_hook(int keycode, t_vars *vars);
//int	ft_release(int keycode, t_vars *vars);

// IMAGE
void	pixel_put(t_vars *vars, int x, int y, int color);
void	ft_paintimage(t_vars *vars);

// EXECUTE
void	ft_readnext(t_vars *vars);
void	ft_readprev(t_vars *vars);

// INSTRUCTIONS
int	c_swap(t_ps_list **a);
int	c_push(t_ps_list **a, t_ps_list **b);
int	c_rotate(t_ps_list **a);
int	c_rrotate(t_ps_list **a);
