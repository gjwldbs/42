/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 19:26:09 by jhur              #+#    #+#             */
/*   Updated: 2020/03/05 19:32:09 by jhur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#ifndef BUFFER_SIZE = 32
//#define
static int has_s_res(char **s_res, char **line, char *tmp)
{
   int i;
   
	//printf("hi");
    if(!(ft_strchr(*s_res, '\n')))
    {
        if(!(*line = ft_strjoin(*line, *s_res)))
        {
            free(*s_res);
            return (-1);
        }
        free(*s_res);
        *s_res = NULL; //ㅎㅎ없애야 다음 문장 읽을 수 있으니까
    }    
    else
    {
        i = 0;
        while((*s_res)[i] != '\n' && (*s_res)[i] != '\0')
        {
            tmp[i] = (*s_res)[i];
            i++;
        }
        tmp[i] = '\0';
        if(!(*line = ft_strjoin(*line, tmp)))
        {
            free(*s_res);
            return(-1); //개행전까지 line 에 들어감
        }
        ft_memmove(*s_res, *s_res + i + 1, ft_strlen(*s_res) - i);
        return(1); //line is read
    }
    return(0);
} 
static int has_newline(char *buf, char *tmp, char **s_res, char **line)
{
    int i;

    if(ft_strchr(buf, '\n'))
    {
        i = 0;
        while(buf[i] != '\n')
        {
            tmp[i] = buf[i];
            i++;
        }
        tmp[i] = '\0';
        if(!(*line = ft_strjoin(*line, tmp)))
        {    
            free(*s_res);
            return(-1);//개행전까지 line 에 들어감
        }
        free(*s_res);
        *s_res = NULL; 
        if(!(*s_res = ft_strdup(&buf[i + 1])))
        {
            free(*s_res);
            return(-1);
        }
        return(1);
    }
    return(0);
}

int get_next_line(int fd, char **line)
{
    //fd == 0 키보드 입력을 버퍼에 저장하고 버퍼에 저장한 크기를 리턴
    //fd != 0 파일의 데이터 크기만큼 저장후 읽은 바이트 수를 리턴
    size_t res;
    char buf[BUFFER_SIZE + 1];
    char tmp[BUFFER_SIZE + 1];
    int i;
    static char *s_res;

    if(fd < 0 || line == NULL || BUFFER_SIZE < 1)
        return (-1);
    *line = ft_strdup(""); //strjoin 실행 위해 둘중하나가 null이면 실행안되니까
    if(s_res)
    {
        if(has_s_res(&s_res, line, tmp) == 1)
            return(1);
    }
    while((res = read(fd, buf, BUFFER_SIZE)) > 0)//읽어서 바이트수만큼 res에 저장
    {
        buf[res] = '\0'; 
        if(has_newline(buf, tmp, &s_res, line) == 1)
            return(1);
        if(!(*line = ft_strjoin(*line, buf)))
        {
            free(s_res);
            return(-1);
        }
    }
    return(res);  
}
int main(void)
{
    char    *line = 0;
    size_t  ret;
    int     fd;
    fd = open("test.txt", O_RDONLY);
    while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);
    while(1);
	return (0);
}
