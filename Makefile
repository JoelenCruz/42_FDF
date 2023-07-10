# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 15:47:41 by awoimbee          #+#    #+#              #
#    Updated: 2019/04/26 17:23:13 by awoimbee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf

CC = cc

ECHO = @printf

HEADERS	= includes

CFLAGS	=	-Wall -Wextra -Werror  -Ofast -march=native -fno-builtin -ftree-vectorize -fstrict-aliasing

#SRC_PATH =	src
OBJ_PATH =	obj

SRC =	fdf.c	./srcs/initialize.c	./srcs/free.c	./srcs/read.c	\
				./srcs/legend.c	./srcs/key_hooks.c	./srcs/color.c			\
				./srcs/draw.c	./srcs/projection.c	./srcs/rotate.c 		\
				./srcs/mouse_hooks.c	./srcs/image.c	./srcs/reproject.c

OBJ = $(SRC:.c=.o)

#SRC = SRC_NAME
#OBJ = OBJ_NAME

LDLIBS = -lft -lmlx -lm -lpthread

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	LIBX_FD = ./minilibx_macos
	LDLIBS += -framework OpenGL -framework AppKit
else
	LIBX_FD = ./minilibx-linux
	LDLIBS += -lXext -lX11
	#Don't forget you need libxext-dev & libx11-dev
endif

LDFLAGS = -Llibft -L$(LIBX_FD)

CPPFLAGS = -I./ -I$(LIBX_FD) -I./libft

LIBS = libft/libft.a $(LIBX_FD)/libmlx.a

all : $(NAME)

%.o:		%.c
			@$(CC) $(CFLAGS) -I $(HEADERS) -c $< -o $@

libft/libft.a :
	$(ECHO) "$(RED)Making libft...$(EOC)\n"
	make -C libft/ all

$(LIBX_FD)/libmlx.a :
	$(ECHO) "$(RED)Making libx...$(EOC)\n"
	make all -C $(LIBX_FD)


$(NAME) : $(LIBS) $(OBJ)
	$(ECHO) "$(RED)Linking $(NAME)...$(EOC)\n"
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS) $(LDLIBS)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	$(ECHO) "$(GRN)Making $@ with \"$(CFLAGS) $(CPPFLAGS)\"...$(EOC)\n"
	@mkdir -p $(OBJ_PATH) 2> /dev/null
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean :
	$(ECHO) "$(RED)Cleaning libx...$(EOC)\n"
	make clean -C $(LIBX_FD)
	$(ECHO) "$(RED)Cleaning libft...$(EOC)\n"
	make fclean -C libft
	$(ECHO) "$(RED)Cleaning objects...$(EOC)\n"
	rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean : clean
	$(ECHO) "$(RED)Cleaning $(NAME)...$(EOC)\n"
	rm -f $(NAME)

re : fclean all

sfclean :
	$(ECHO) "$(RED)Cleaning $(NAME)...$(EOC)\n"
	rm -f $(NAME)
	$(ECHO) "$(RED)Cleaning objects...$(EOC)\n"
	rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

sre: sfclean $(NAME)

.PHONY: all clean re fclean sfclean sre

RED = \033[1;31m
GRN = \033[1;32m
EOC = \033[0m
