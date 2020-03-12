#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list *new_lst;
    t_list *new_element;

    if(lst == 0 || f == 0 || del == 0)
        return(0);
    if(!(new_lst = malloc(sizeof(t_list))))
        return(NULL);
    while(lst != 0)
    {
        new_element = ft_lstnew(f(lst->content));
        if(new_element == 0) //if malloc fails
        {
            ft_lstclear(&new_lst, del);
            break;
        }
        ft_lstadd_back(&new_lst, new_element);
        lst = lst->next;
    }
        return(new_lst);
}