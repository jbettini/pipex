/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:48:22 by jbettini          #+#    #+#             */
/*   Updated: 2021/12/16 16:54:52 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>

typedef unsigned long long	t_ull;
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

# define FD_MAX 255
# define BUFFER_SIZE 1

int				ft_bytes_len(int nb);
t_ull			ft_itb(int nb);
void			ft_swap_str(char **a, char **b);
void			ft_swap_content(t_list **a, t_list **b);
size_t			ft_double_strlen(char **arg);
void			ft_free_split(char **tab);
int				ft_bytes_len(int nb);
void			ft_lstdel_content(void *content);
int				ft_atoi_base(const char *str, char *base);
void			ft_void_swap(void *a, void *b);
long long		ft_atoll(const char *str);
char			*get_next_line(int fd);
int				ft_isin(char *str, int c);
char			*ft_strjoin_gnl(char *save, char *buf);
char			*ft_strncat(char *dest, const char *src, size_t n);
int				ft_check_base(char *base);
int				ft_is_prime(int nb);
char			*ft_itoa_base(unsigned long long nb, char *base);
void			ft_putchar(char c);
void			ft_putendl(char const *s);
void			ft_putnbr_base(int nbr, char *base);
void			ft_putnbr(int n);
int				ft_putsize(unsigned long long nb, char *base);
void			ft_putstr(char const *s);
int				*ft_range(int min, int max);
int				ft_recursive_power(int nb, int power);
int				ft_sqrt(int nb);
char			*ft_strcat(char *dest, const char *src);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *dest, const char *src);
void			ft_strclr(char *s);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strnew(size_t size);
void			*ft_memset(void *pt, int value, size_t len);
void			ft_bzero(void *s, size_t len);
void			*ft_memcpy(void *dest, const void *src, size_t len);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *src);
size_t			ft_strlcat(char *dest, const char *src, size_t n);
char			*ft_strchr(const char *str, int tofind);
char			*ft_strrchr(const char *str, int tofind);
char			*ft_strnstr(const char *str, const char *tofind, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s, char const *charset);
char			**ft_split(char const *s, char charset);
char			*ft_itoa(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strlcpy(char *dest, const char *src, size_t size);
void			*ft_calloc(size_t count, size_t size);
void			ft_strdel(char **as);
void			ft_swap(int *a, int *b);
t_list			*ft_lstnew(void *content);
int				ft_lstsize(t_list *lst);
void			ft_lstadd_front(t_list **alst, t_list *start);
void			ft_lstadd_back(t_list **alst, t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void*));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*));

#endif
