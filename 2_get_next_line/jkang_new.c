#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

// # ifdef BUFFER_SIZE 32; 
// #endif

static int      ft_strlen(const char *s)
{
    int count;

    count = 0;
    while (s[count] != '\0')
      ++count;
   return (count);
}

static char     *ft_strjoin(char const *s1, char const *s2)
{
   char   *joined_str;
   int      i;
   int      j;

   if (s1 == 0 || s2 == 0)
      return (0);
   joined_str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
   if (joined_str == 0)
      return (0);
   i = -1;
   while (++i < ft_strlen(s1))
      joined_str[i] = s1[i];
   j = -1;
   while (++j < ft_strlen(s2))
      joined_str[i++] = s2[j];
   joined_str[i] = '\0';
   return (joined_str);
}

static char    *ft_strchr(const char *s, int c)
{
    while (*s != '\0')
    {
        if (*s == (char)c)
            return ((char *)s);
        ++s;
    }
    if (c == '\0')
        return ((char *)s);
    return (0);
}

static char    *ft_strdup(const char *s)
{
    int     len;
    int     i;
    char    *temp;

    len = 0;
    while (s[len] != '\0')
        ++len;
    temp = (char *)malloc(sizeof(char) * (len + 1));
    if (temp == 0)
        return (0);
    i = 0;
    while (i < len)
    {
        temp[i] = s[i];
        ++i;
    }
    temp[i] = '\0';
    return (temp);
}

static void    *ft_memmove(void *dst, const void *src, size_t len)
{
    size_t i;
    size_t n;

    n = len;
    i = 0;
    if (src < dst)
   {
      while (n)
        {
            n--;
            ((unsigned char *)dst)[n] = ((unsigned char *)src)[n];
        }
   }
    else
   {
        while (i < len)
        {
            *((unsigned char *)dst++) = *((unsigned char *)src++);
            ++i;
        }
   }
    return (dst);
}

int             ft_has_new_line(char *buf, char *tmp, char **s_res, char **line)
{
    int i;

    if (ft_strchr(buf, '\n') != 0)
    {
        i = 0;
        printf("buf of ft_has_new_line %s\n", buf);
        while (buf[i] != '\n')
        {
            tmp[i] = buf[i];
            ++i;
        }
        tmp[i] = '\0';
        if(!(*line = ft_strjoin(*line, tmp)))
            return (-1);
        printf("tmp of ft_has_new_line %s\n", tmp);
        //free(*s_res);
        //*s_res = 0;
        if(!(*s_res = ft_strdup(&buf[i + 1])))
            return (-1);
        printf("s_res of ft_has_new_line %s\n", *s_res);
        return (1);
    }
    return (0);
}

int             ft_read_s_res(char *tmp, char **s_res, char **line)
{
    int i;

    if ((ft_strchr(*s_res, '\n')) == 0)
    {
        if (!(*line = ft_strjoin(*line, *s_res)))
            return (-1);
        *s_res = 0;
    }
    else  
    {
        i = 0;
        while ((*s_res)[i] != '\n' && (*s_res)[i] != '\0')
        {
            tmp[i] = (*s_res)[i];
            ++i;
        }
        tmp[i] = '\0';
        if (!(*line = ft_strjoin(*line, tmp)))
            return (-1);
        ft_memmove(*s_res, *s_res + i + 1, ft_strlen(*s_res) - i);
        return (1);   
    }
    return (0);
}

int             get_next_line(int fd, char **line)
{
    int             BUFFER_SIZE = 5;
    char            buf[BUFFER_SIZE + 1];
   static char      *s_res;
    size_t          ret;
   char         tmp[BUFFER_SIZE + 1];
   
    if (fd < 0 || line == 0 || BUFFER_SIZE < 1)
      return (-1);    
   *line = ft_strdup("");
   if (s_res)
   {
        printf("s_res of get_next_line %s\n", s_res);
        if (ft_read_s_res(tmp, &s_res, line) == 1)
            return (1);
   }
   while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
    {
        buf[ret] = '\0';
        printf("ret %ld\n", ret);
        printf("1st loop buf %s", buf);
        if (ft_has_new_line(buf, tmp, &s_res, line) == 1)
            return (1);
      if(!(*line = ft_strjoin(*line, buf)))
         return (-1);
    }
    return (ret);
}

   //how to keep the text read after 개행 in memory, if it exists.
   //how to re-use the text kept in static from a previous gnl call.

int main(void)
{
    char    *line = 0;
    size_t  ret;
    int     fd;
   
    fd = open("test.txt", O_RDONLY);
    while ((ret = get_next_line(fd, &line)) > 0)
   {
      printf("a line is read in main : %s\n", line);
      free(line);
   }
   printf("Reading test.txt is done, but we have to free 'line' with a NULL VALUE in heap area (due to s_res of get_net_line) %s\n", line);
   free(line);
   return (0);
}