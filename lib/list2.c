#include "../src/ps_visualizer.h"

void	ps_lstdelone(t_ps_list *lst)
{
	if (!lst)
		return ;
	free(lst);
}

void	ps_lstclear(t_ps_list **lst)
{
	t_ps_list	*aux;

	if (!lst)
		return ;
	while (*lst)
	{
		aux = (*lst)->next;
		ps_lstdelone(*lst);
		*lst = aux;
	}
}

void	ps_lstiter(t_ps_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

t_ps_list	*ps_lstmap(t_ps_list *lst, void *(*f)(void *))
{
	t_ps_list	*new;
	t_ps_list	*firstdir;

	if (!lst || !f)
		return (0);
	new = ps_lstnew(f(lst->content));
	if (!new)
		return (0);
	firstdir = new;
	lst = lst->next;
	while (lst)
	{
		new->next = ps_lstnew(f(lst->content));
		if (!new)
		{
			ps_lstclear(&firstdir);
			return (0);
		}
		new = new->next;
		lst = lst->next;
	}
	new->next = NULL;
	return (firstdir);
}
