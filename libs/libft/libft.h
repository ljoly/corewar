/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 19:24:54 by bdal-can          #+#    #+#             */
/*   Updated: 2017/06/16 15:11:36 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "get_next_line.h"

# define ABS(x) (x < 0) ? -x : x
# define ULL unsigned long long

typedef struct s_list	t_list;

struct	s_list
{
	void	*content;
	size_t	content_size;
	t_list	*next;
};

typedef t_list		**t_clist;

typedef char		t_boolean;

# define TRUE		1
# define FALSE		0

int		ft_strcmp(const char *s1, const char *s2);
void	ft_putchar(char c);
void	ft_putstr(char const *s);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
size_t	ft_strlen(const char *s);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
void	ft_putnbr(int n);
void	ft_putnbr_fd(int n, int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *dst, const char *src, size_t len);
char	*ft_strcat(char *restrict s1, const char *restrict s2);
char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n);
size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strstr(const char *big, const char *little);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strnew(size_t size);
void	ft_strdel(char **as);
void	ft_strclr(char *s);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnjoin(char const *s1, char const *s2);
char	*ft_strjoinfree(char const *s1, char const *s2);
char	*ft_strtrim(char const *s);
void	ft_putendl(char const *s);
void	ft_putendl_fd(char const *s, int fd);
void	*ft_memalloc(size_t size);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *restrict s1, const void *restrict s2, size_t n);
void	*ft_memccpy(void *restrict a, const void *restrict b, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	ft_memdel(void **ap);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_atoi(const char *str);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	**ft_strsplit(char const *s, char c);
char	*ft_itoa(long long n);
t_list	*ft_lstnew(void const *content, size_t content_size);
void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void	ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void	ft_lstadd(t_list **alst, t_list *new);
void	ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int		ft_isspace(int c);
void	ft_lstaddend(t_list **list, t_list *new);
void	ft_printtab_char(char **tab);
void	ft_printtab_int(int **tab, size_t x, size_t y);
int		**ft_createtab_int(size_t x, size_t y);
void	ft_printtab(char **tab, int x, int y);
void	ft_printtab_fd(char **tab, int x, int y, int fd);
int		ft_sqrt(int nb);
char	**ft_createtab_char(int x, int y);
char	*ft_strndup(const char *s, size_t n);
void	ft_capitalise(char *str);
char	*ft_itoa_base(unsigned long long nb, int base);
int		ft_putnwstr(wchar_t *str, int byte);
int		ft_putwstr(wchar_t *str);
int		ft_putwchar(wchar_t c);
int		ft_wcslen(wchar_t *wstr);
int		ft_wcsbytelen(wchar_t *wstr);
wchar_t	*ft_wcsdup(wchar_t *str);
wchar_t	*ft_wcsndup(wchar_t *str, int bytes);
int		ft_ishex(char *str);
char	*ft_strjoinfree1st(char const *s1, char const *s2);
int		ft_atoi_base(char *str, int base);
ULL		ft_pos_power(int value, int power);
void	ft_nbrswap(int *a, int *b);
int		ft_countbyte(wchar_t c);
char	*ft_strmerge(char *a, char *b);
int		ft_count_words(char const *str, char c);
int		ft_isalldigits(char *str);
void	ft_free_tab(char **tab, int num);
void	ft_free3strings(char *s1, char *s2, char *s3);
void	ft_freeinsidelst(void *content, size_t content_size);
int		ft_lstcountelem(t_list *list);
int		ft_isinarray(int *array, int n, int size);
void	ft_lstfree(t_list *lst);
int		ft_bytestoint(unsigned char *bytes, int size);
int		ft_cmparr(int *tab, int a, int b, int c);
int		ft_array_have_doubles(int *arr, int size);

void	ft_clist_addfirst(t_clist list, void *data, size_t size);
void	ft_clist_addlast(t_clist list, void *data, size_t size);
t_clist	ft_clist_create();
void	*ft_clist_first(t_clist list);
void	*ft_clist_last(t_clist list);
void	ft_clist_rmfirst(t_clist list);
void	ft_clist_destroy(t_clist list);

int		ft_check_argc(int argc, int nb, char *error);
int		ft_open_file(char *path, int option, int *fd);
int		ft_savearg(int in, int *store);
int		ft_error(int ret_val, char *str);

#endif
