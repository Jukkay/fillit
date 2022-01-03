/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htahvana <htahvana@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 10:14:49 by htahvana          #+#    #+#             */
/*   Updated: 2022/01/03 12:15:48 by htahvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# define TRUE 1
# define FALSE 0
# define BUFF_SIZE 16
typedef int	t_bool;

typedef struct s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}	t_list;

typedef struct	s_point
{
	int x;
	int y;
}	t_point;


void	ft_bzero(void *s, size_t n);
void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void	*dst, const void *src, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strnew(size_t size);
void	ft_strdel(char **as);
void	ft_strclr(char *s);
size_t	ft_strlen(const char *str);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	**ft_strsplit(char const *s, char c);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *dst, const char *src, size_t len);
char	*ft_strcat(char *s1, const char *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strncat(char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strdup(const char *s1);
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strstr(const char *haystack, const char *needle);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s);
void	ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr(char const *s);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putnbr(int n);
void	ft_putnbr_fd(int n, int fd);
void	ft_putendl(char const *s);
void	ft_putendl_fd(char const *s, int fd);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_isprint(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isalnum(int c);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
void	ft_lstadd(t_list **alst, t_list *new);
void	ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void	ft_lstiter(t_list *lst,	void (*f)(t_list *elem));
t_list	*ft_lstnew(void const *content, size_t content_size);
t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int		ft_abs(int nbr);
int		ft_intdigits(int i);
t_bool	ft_islower(int c);
t_bool	ft_isupper(int c);
t_bool	ft_iswhitespace(char c);
size_t	ft_strnlen(char *str, size_t maxlen);
t_list	*ft_lstdelto(t_list **alst, t_list **lst, void (*del)(void *, size_t));
void	ft_lstput(t_list **alst, t_list *new);
void	ft_freeclr(void *ptr, size_t n);
t_list	*ft_lstsplit(const char *str, char c);
t_list	*ft_lstpopi(t_list **lst, size_t index, void (*del)(void *, size_t));
size_t	ft_strclen(char *src, char delim);
ssize_t	ft_math_sign(ssize_t i);
size_t	ft_lstsize(t_list *lst);
size_t	ft_memtrim(const void *src, void **dst, size_t contentsize);
size_t	ft_lstlen(t_list *lst);
char	*ft_lstjoin(t_list *lst, char limit);
char	*ft_strjoinfree(char *s1, char *s2, int type);
int		ft_get_next_line(const int fd, char **line);
int		ft_strchri(const char *s, char c);
char	*ft_strsubfree(char *s, unsigned int start, size_t len);
t_point	*ft_newpoint(int x, int y);
t_point	*ft_setpoint(t_point *point, int x, int y);

#endif
