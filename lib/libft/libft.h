/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:22:43 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/24 15:00:27 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# define GNL_BUFFER_SIZE 50

// binary_tree
typedef struct s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	size_t			key;
	void			*value;
}	t_btree;

t_btree		*ft_btreenew(size_t key, void *value);
t_btree		*ft_btreesearch(t_btree *root, size_t key);
void		ft_btreeinsert(t_btree **rootptr, t_btree *new);
void		ft_btreeinsert_balanced(t_btree **rootptr, t_btree *new);
void		ft_btreeclear(t_btree **rootptr, void (*fr)(void *));
void		ft_btreerotate_left(t_btree **rootptr);
void		ft_btreerotate_right(t_btree **rootptr);
void		ft_btreebalance(t_btree **rootptr);
size_t		ft_btreesize(t_btree *root);
size_t		ft_btreeheight(t_btree *root);
int			ft_btreeis_balanced(t_btree *root);
int			ft_btreebalance_factor(t_btree *root);

// char
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isspace(int c);
int			ft_isprint(int c);
int			ft_tolower(int c);
int			ft_toupper(int c);

// converters
int			ft_atoi(const char *s);
long		ft_atol(const char *s);
double		ft_atod(const char *s);
char		*ft_itoa_base(int n, char *base);
char		*ft_itoa(int n);
char		*ft_uitoa_base(unsigned int n, char *base);
char		*ft_uitoa(unsigned int n);
char		*ft_ultoa_base(unsigned long n, char *base);
char		*ft_ultoa(unsigned long n);

// doubly_linked_list
typedef struct s_dllist
{
	struct s_dllist	*prev;
	struct s_dllist	*next;
	void			*data;
}	t_dllist;

void		ft_dllstadd_back(t_dllist **headptr, t_dllist *new);
void		ft_dllstadd_front(t_dllist **headptr, t_dllist *new);
void		ft_dllstclear(t_dllist **headptr, void (*free)(void *));
int			ft_dllstcmp(t_dllist *l1, t_dllist *l2, int (*cmp)(void *, void *));
t_dllist	*ft_dllstfind(
				t_dllist *head,
				void *ref,
				int (*cmp)(void *, void *));
t_dllist	*ft_dllstfind_closest(
				t_dllist *head,
				void *ref,
				int (*cmp)(void *, void *));
t_dllist	*ft_dllstfirst(t_dllist *elem);
t_dllist	*ft_dllstindex_after(t_dllist *head, size_t index);
t_dllist	*ft_dllstindex_before(t_dllist *head, size_t index);
void		ft_dllstinsert_after(t_dllist *elem, t_dllist *new);
void		ft_dllstinsert_before(t_dllist *elem, t_dllist *new);
int			ft_dllstis_sorted(t_dllist *head, int (*cmp)(void *, void *));
void		ft_dllstiter(t_dllist *head, void (*f)(void *));
t_dllist	*ft_dllstlast(t_dllist *head);
int			ft_dllstmatch(
				t_dllist *find,
				t_dllist *in,
				int (*cmp)(void *, void *));
t_dllist	*ft_dllstnew(void *data);
void		ft_dllstremove_elem(t_dllist **elemptr, void (*fr)(void *));
void		ft_dllstremove_after(
				t_dllist **headptr,
				size_t index,
				void (*free)(void *));
void		ft_dllstremove_before(
				t_dllist **headptr,
				size_t index,
				void (*free)(void *));
size_t		ft_dllstsize(t_dllist *head);

// get_next_line
char		*get_next_line(int fd);

// linked_list
typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}	t_list;

void		ft_lstadd_back(t_list **headptr, t_list *new);
void		ft_lstadd_front(t_list **headptr, t_list *new);
void		ft_lstclear(t_list **headptr, void (*f_free)(void *));
t_list		*ft_lstfind(t_list *head, void *ref, int (*cmp)(void *, void *));
t_list		*ft_lstfind_closest(
				t_list *head,
				void *ref,
				int (*cmp)(void *, void *));
t_list		*ft_lstindex(t_list *head, size_t index);
int			ft_lstis_sorted(t_list *head, int (*cmp)(void *, void *));
void		ft_lstiter(t_list *head, void (*f)(void *));
t_list		*ft_lstlast(t_list *head);
t_list		*ft_lstmap(t_list *head, void *(*f)(void *));
size_t		ft_lstmax(t_list *head, int (*cmp)(void *, void *));
size_t		ft_lstmin(t_list *head, int (*cmp)(void *, void *));
t_list		*ft_lstnew(void *data);
t_list		*ft_lstpop(t_list **headptr, size_t index);
void		ft_lstremove(
				t_list **headptr,
				size_t index,
				void (*f_free)(void *));
size_t		ft_lstsize(t_list *head);
t_list		*ft_lstsplit_before(t_list **headptr, int (*pred)(void *));
t_list		*ft_lstsplit(t_list **headptr, int (*pred)(void *),
				void (*f_free)(void *)); // Deletes split points

// memory
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *p1, const void *p2, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t n);
void		*ft_memset(void *b, int c, size_t len);
void		ft_memswap(void *a, void *b, size_t n);
void		*ft_simple_realloc(void *p, size_t old, size_t new);

// string
char		**ft_split(char const *s, char c);
char		*ft_strchr(const char *s, int c);
char		*ft_strchrs(const char *s, const char *cs);
int			ft_strcmp(const char *s1, const char *s2);
size_t		ft_strcount(const char *s, char c);
char		*ft_strdup(const char *s);
int			ft_stris_numeric(const char *s);
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlen(const char *s);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strndup(const char *s, size_t n);
char		*ft_strnstr(const char *h, const char *n, size_t len);
char		*ft_strrchr(const char *s, int c);
void		ft_strtoupper(char *s);
char		*ft_strtrim(char const *s, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);

// vector
typedef struct s_vector
{
	void	*data;
	size_t	length;
	size_t	_capacity;
	size_t	_elem_size;
}	t_vector;

int			ft_vecdelete(t_vector *vec, size_t index, void (*clear)(void *));
void		ft_vecfor_each(t_vector *vec, void (*action)(void *, size_t));
void		ft_vecfree(t_vector **pvec, void (*clear)(void *));
void		*ft_vecindex(t_vector *vec, size_t index);
int			ft_vecinsert_elems(
				t_vector *vec,
				void *elems,
				size_t num_elems,
				size_t index);
int			ft_vecinsert(t_vector *vec, void *elem, size_t index);
t_vector	*ft_vecmap(t_vector *vec, void *(*map)(void *, size_t));
t_vector	*ft_vecnew_from_array(
				void *elements,
				size_t length,
				size_t elem_size);
t_vector	*ft_vecnew_from_func(
				size_t length,
				void *(*gen)(size_t),
				size_t elem_size);
t_vector	*ft_vecnew_with_capacity(size_t capacity, size_t elem_size);
t_vector	*ft_vecnew(size_t elem_size);
void		*ft_vecpop_elems(t_vector *vec, size_t num_elems);
void		*ft_vecpop(t_vector *vec);
int			ft_vecpush_consume(t_vector *vec, void *elem);
int			ft_vec_push_elems(t_vector *vec, void *elems, size_t num_elems);
int			ft_vecpush(t_vector *vec, void *elem);
void		*ft_vecremove_elems(t_vector *vec, size_t index, size_t num_elems);
void		*ft_vecremove(t_vector *vec, size_t index);
void		ft_vecreserve_exact(t_vector *vec, size_t num_elems);
void		ft_vecreserve(t_vector *vec, size_t num_elems);

#endif
