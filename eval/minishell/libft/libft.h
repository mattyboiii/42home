/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 08:41:11 by charlie           #+#    #+#             */
/*   Updated: 2024/11/07 10:08:49 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*libc functions*/
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
// # include <bsd/string.h>

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_iswhitespace(int c);
size_t		ft_strlen(const char *s);
void		*ft_memset(void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strcmp(const char *s1, const char *s2);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
int			ft_atoi(const char *nptr);
void		*ft_calloc(size_t nmemb, size_t size);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
size_t		ft_strlcat(char *dest, const char *src, size_t size);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strdup(const char *s);

char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
char		*ft_strtrim(char const *s1, char const *set);

/*bonus*/
// list node with a pointer to the next node
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list		*ft_lstnew(void *content);
t_list		*ft_lstlast(t_list *lst);
int			ft_lstsize(t_list *lst);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// list node with two pointers, previous and next
typedef struct s_double_list
{
	void					*content;
	struct s_double_list	*next;
	struct s_double_list	*prev;
}	t_dlst;

t_dlst		*d_list_new(void *content);
t_dlst		*d_list_first(t_dlst *list);
t_dlst		*d_list_second(t_dlst *list);
t_dlst		*d_list_find(t_dlst *list, void *content,
				int (*cmp)(void *, void *));
void		d_list_add_back(t_dlst **list, t_dlst *new_node);
void		d_list_add_front(t_dlst **list, t_dlst *new_node);
void		d_list_remove_if(t_dlst **list, void *content,
				int (*cmp)(void *, void *), void (*del)(void *));
void		d_list_delone(t_dlst *node, void (*del)(void *));
void		d_list_clear(t_dlst **list, void (*del)(void *));
void		d_list_iter(t_dlst *list, void (*f)(void *));
t_dlst		*d_list_last(t_dlst *list);
t_dlst		*d_list_get_nth(t_dlst *list, int n);
t_dlst		*d_list_copy(t_dlst *list, void *(*copy)(void *),
				void (*del)(void *));
void		d_list_reverse(t_dlst **list);

// added some new functions
double		ft_atodbl(char *s);
char		*ft_free_str_and_null(char *s);
void		ft_free_str2d(char **s);
void		ft_free_str3d(char ***s);
char		*ft_strjoin_and_free(char *s1, char *s2);
char		*ft_strjoin_with(char const *s1, char const *s2, char c);
char		*ft_strjoin_with_and_free(char *s1, char *s2, char c);
char		**ft_str_arr_dup(char **arr);
int			ft_str_arr_len(char **arr);
void		ft_free(void *ptr);
int			ft_isnumber(char *s);

#endif /* libft.h */
