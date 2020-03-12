#include "libft.h"

int ft_lstsize(t_list *lst)
{
 int len;

 len = 0;
 if(lst == NULL)
    return(0);
 while(lst != NULL)
 {
     lst = lst->next;
     len++;
 }
 return(len);
}