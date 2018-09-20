/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 13:58:36 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/07/10 13:59:25 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFF_SIZE 4096
# define MAX_FD 64000

# define AUX_BUFFER_SIZE 4096
# define MAIN_BUFFER_SIZE 64000

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_mtx_lst
{
	int					width;
	int					height;
	char				**mtx;
	struct s_mtx_lst	*next;
}				t_mtx_lst;

void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memmove(void *dst, const void *src, size_t len);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_isprint(int c);
int				ft_isascii(int c);
int				ft_isalnum(int c);
int				ft_isdigit(int c);
int				ft_isalpha(int c);
int				ft_atoi(char *str);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strchr(const char *s, int c);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strdup(const char *s1);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t			ft_strlen(char *str);
char			*ft_strncat(char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strnstr(const char *haystack, const char *needle,
				size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);

int				ft_cntwrds(char *s, char c);
char			*ft_fndwrds(char *s, char c, int n);
char			**ft_bldstr(char *s, int q_words, char c);
int				*ft_wrdsizes(char *s, int q_words, char c);
t_list			*ft_lstrev(t_list **lst);

char			*ft_strrev(char *str);
char			*ft_acqinput(int fd);
char			*ft_incr_n_trans(char *str, int *size);
char			**ft_free_all(char **s, int i);
t_mtx_lst		*ft_get_mtx_lst(int mtx_index, t_mtx_lst *mlst);
int				ft_mtx_count(t_mtx_lst *mlst);
void			ft_mtx_add(t_mtx_lst **amlst, t_mtx_lst *new);
t_mtx_lst		*ft_mtx_new(char **matrix, int height, int width);
t_mtx_lst		*ft_mtx_rev(t_mtx_lst **mlst);
void			ft_mtx_iter(t_mtx_lst *mlst, void (*f)(t_mtx_lst *elem));
void			ft_mtx_print(t_mtx_lst *mlst);
void			ft_print_tab(char **s);
int				get_next_line(const int fd, char **line);

t_list			*ft_lstnew2(char *content);
void			ft_lstdel2(t_list **alst);

#endif
