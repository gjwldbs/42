#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list *tmp;

    tmp = *lst;
    if(*lst == 0 || del == 0)
        return;
    while(tmp != NULL)
    {
        del(tmp->content);
        free(tmp);
        tmp = tmp->next;
    }
    *lst = 0;
}
