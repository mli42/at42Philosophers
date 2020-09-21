/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:34:27 by mli               #+#    #+#             */
/*   Updated: 2020/09/21 15:14:15 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memalloc(size_t size);

size_t			ft_strlen(const char *const str);
int				ft_atoi(const char *str);

int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);

char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *haystack,
				const char *needle, size_t len);

size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);

void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);

void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(const char *s1);

char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s1, char const *set);

char			*ft_strjoin(char const *s1, char const *s2);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(const char *const str, const int fd);
void			ft_putendl_fd(const char *const str, const int fd);
void			ft_putnbr_fd(int n, int fd);

void			ft_putchar(char c);
void			ft_putstr(char *s);
void			ft_putnbr(int n);

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **alst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **alst, t_list *new);

void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
				void (*del)(void *));

void			ft_free(void **ptr);
int				ft_atoi_ptr(const char *str, int *i);
int				ft_nbrlen_base(long unsigned int nb,
		unsigned long int base_len);
int				ft_nbrlen(long unsigned int nb);
char			*ft_itoa_lbase(const char *base, long int nbr);

double			ft_abs_lf(double nbr);
long int		ft_abs_ld(long int nb);

int				ft_atoi_isdigit(const char *str, int *nbr);

#endif
