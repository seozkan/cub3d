# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seozkan <seozkan@42kocaeli.com.tr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/11 14:49:07 by seozkan           #+#    #+#              #
#    Updated: 2023/12/07 16:34:34 by seozkan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = @gcc
RM = @rm -f
AR = ar rcs
FLAGS = -Wall -Wextra -Werror

YELLOW 	= \033[33;49;1m
CYAN 	= \033[33;36;1m
END 	= \033[0;0m
CLEAR 	= \033[2K

SRC = \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_printf.c \
	get_next_line.c
	
BNS_SRC = \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c
	
OBJ = $(SRC:.c=.o)

BNS_OBJ = $(BNS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $@ $?
	@printf "$(CLEAR)$(CYAN)${NAME} ✔️\n"
	@printf "$(CLEAR)$(YELLOW)Mandatory files compiled successfully ✔️$(END)\n"
	@printf "$(CLEAR)$(CYAN)by seozkan ✔️$(END)\n"
	

bonus: $(OBJ) $(BNS_OBJ)
	@$(AR) $(NAME) $?
	@printf "$(CLEAR)$(CYAN)${NAME} ✔️\n"
	@printf "$(CLEAR)$(YELLOW)Bonus files compiled successfully ✔️$(END)\n"
	@printf "$(CLEAR)$(CYAN)by seozkan ✔️$(END)\n"
	
%.o: %.c
	$(CC) -c $(FLAGS) $?
	@printf "$(CLEAR)Compiling: $(CYAN)$<$(END)\r"
	
clean:
	$(RM) $(OBJ) $(BNS_OBJ)
	
fclean: clean
	$(RM) $(NAME)
	
re: fclean all

.PHONY: all bonus clean fclean re