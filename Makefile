# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 21:20:53 by ewolfghe          #+#    #+#              #
#    Updated: 2023/05/13 11:52:28 by ewolfghe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libft.a
CC			= cc
FLAGS		= -Wall -Wextra -Werror
SRC_PATH 	= sources/
OBJ_PATH 	= objs/
BNS_PATH	= sources_bonus/
OBJ_BNS_PATH= objs/sources_bonus/

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
		ft_tolower.c ft_toupper.c ft_strdup.c ft_memset.c ft_bzero.c ft_memcpy.c \
		ft_memmove.c ft_memchr.c ft_memcmp.c ft_atoi.c ft_strchr.c ft_strrchr.c \
		ft_calloc.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c \
		ft_itoa.c ft_strncmp.c ft_strnstr.c ft_strlcpy.c ft_strlcat.c ft_striteri.c \
		ft_substr.c ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_split.c
SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
INCS	= -I ./include/

BONUS_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
				ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

BONUS_SRCS	= $(addprefix $(BNS_PATH), $(BONUS_SRC))
BONUS_OBJ 	= $(BONUS_SRCS:.c=.o)
BONUS_OBJS	= $(addprefix $(OBJ_PATH), $(BONUS_OBJ))

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(FLAGS) -c $< -o $@ $(INCS)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: all $(OBJ_BNS_PATH) $(BONUS_OBJS)
	ar rcs $(NAME) $(BONUS_OBJS)

$(OBJ_BNS_PATH)%.o: $(BNS_PATH)%.c
	$(CC) $(FLAGS) -c $< -o $@ $(INCS)
	
$(OBJ_BNS_PATH):
	mkdir $(OBJ_BNS_PATH)

clean:
	rm -rf $(OBJ_BNS_PATH) $(OBJ_PATH)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re 
