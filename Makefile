# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/10 13:57:23 by gcaixeta          #+#    #+#              #
#    Updated: 2018/07/10 15:23:59 by gcaixeta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
OBJECT = $(SRC:.c=.o)
CFLAGS = -Wall -Werror -Wextra -I libft.h
SRC = ft_atoi.c\
		ft_bldstr.c\
		ft_bzero.c\
		ft_cntwrds.c\
		ft_fndwrds.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_itoa.c\
		ft_lstadd.c\
		ft_lstdel.c\
		ft_lstdelone.c\
		ft_lstiter.c\
		ft_lstmap.c\
		ft_lstnew.c\
		ft_lstrev.c\
		ft_memalloc.c\
		ft_memccpy.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memdel.c\
		ft_memmove.c\
		ft_memset.c\
		ft_putchar.c\
		ft_putchar_fd.c\
		ft_putendl.c\
		ft_putendl_fd.c\
		ft_putnbr.c\
		ft_putnbr_fd.c\
		ft_putstr.c\
		ft_putstr_fd.c\
		ft_strcat.c\
		ft_strchr.c\
		ft_strclr.c\
		ft_strcmp.c\
		ft_strcpy.c\
		ft_strdel.c\
		ft_strdup.c\
		ft_strequ.c\
		ft_striter.c\
		ft_striteri.c\
		ft_strjoin.c\
		ft_strlcat.c\
		ft_strlen.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strncat.c\
		ft_strncmp.c\
		ft_strncpy.c\
		ft_strnequ.c\
		ft_strnew.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_strsplit.c\
		ft_strstr.c\
		ft_strsub.c\
		ft_strtrim.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_wrdsizes.c\
		ft_strrev.c\
		ft_acqinput.c\
		ft_incr_n_trans.c\
		ft_free_all.c\
		ft_get_mtx_lst.c\
		ft_mtx_count.c\
		ft_mtx_add.c\
		ft_mtx_new.c\
		ft_mtx_rev.c\
		ft_mtx_iter.c\
		ft_mtx_print.c\
		ft_print_tab.c\
		get_next_line.c\
		ft_lstdel2.c\
		ft_lstnew2.c

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECT)
	@ar rc $(NAME) $(OBJECT)
	@ranlib $(NAME)

$(OBJECT): $(SRC)
	@gcc $(CFLAGS) -c $(SRC)

clean:
	@rm -f $(OBJECT)
	@rm -f libft.h.gch

fclean: clean
	@rm -f $(NAME)

re: fclean all
