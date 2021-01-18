# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkauppi <jkauppi@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/21 11:50:38 by jkauppi           #+#    #+#              #
#    Updated: 2021/01/18 12:35:18 by jkauppi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Input parameters
# P --> Projection which define a picture projection
ifdef P
	PROJECTION	=	$(P)
else
	PROJECTION	=	1
endif

# Application specific parameters
NAME_1			=	ex1
NAME_2			=	ex2
NAME_3			=	ex3
NAME_4			=	ex4
NAMES			=	$(NAME_1) $(NAME_2) $(NAME_3) $(NAME_4)

# Folders
LIB				=	lib
BIN				=	bin
DATA			=	data
OBJ				=	obj
SRC				=	src
INCLUDE			=	include
FOLDERS			=	$(LIB) $(BIN) $(DATA) $(OBJ) $(SRC) $(INCLUDE)
INCLUDES		=	-I $(INCLUDE) -I $(LIB)

# Compiler and linking parameters
CC				=	clang
C_FLAGS			=	-g -Wall -Wextra -Werror $(INCLUDES)
LD_FLAGS		=	-std=gnu99 \
					-Llib \
					-lftprintf -lft -lmlx_Linux -lGLEW -lglfw -lGL \
					-lm -lXext -lX11

# C (Source code) and H (Header) files
SRC_C_FILES		=	hook_functions.c close_win.c release_mlx_win.c \
					render_frame.c create_element.c mlx_image_pixel_put.c \
					initialize_window.c set_elem_positions.c
SRC_H_FILES		=	ex.h

# Path folders for H, C, O and APP files
H_FILES			=	$(addprefix $(INCLUDE)/, $(SRC_H_FILES))
C_FILES			=	$(addprefix $(SRC)/, $(SRC_C_FILES))
C_FILES			+=	$(addprefix $(SRC)/, $(patsubst %, %.c, $(NAMES)))
O_FILES			=	$(addprefix $(OBJ)/, $(patsubst %.c, %.o, $(SRC_C_FILES)))
MAIN_FILES		=	$(addprefix $(SRC)/, $(patsubst %, %.c, $(NAMES)))
APP_FILES		=	$(addprefix $(BIN)/, $(NAMES))

# Colours for printouts
RED				=	\033[0;31m
GREEN			=	\033[0;32m
YELLOW			=	\033[0;33m
END				=	\033[0m

all: $(FOLDERS) $(C_FILES) libraries $(APP_FILES) norm
	@echo "$(GREEN)Done!$(END)"

$(APP_FILES): $(BIN)/%: $(SRC)/%.c $(H_FILES) $(O_FILES) Makefile
	$(CC) -o $@ $< $(O_FILES) $(LD_FLAGS) $(C_FLAGS)

$(O_FILES): $(OBJ)/%.o: $(SRC)/%.c $(H_FILES) Makefile
	$(CC) -c -o $@ $< $(C_FLAGS)

$(FOLDERS):
	mkdir $@

$(C_FILES):
	touch $@

libraries:
	@make -C ${LIB}

run:
	valgrind -s --tool=memcheck --leak-check=full --show-leak-kinds=all $(BIN)/$(NAME_4) -f $(DATA)/maps/42.fdf -P $(PROJECTION)

clean:
#	@make -C ${LIB} clean
	rm -f $(O_FILES)

fclean: clean
#	@make -C ${LIB} fclean
	rm -f $(NAME_1)

re: fclean all

norm:
	norminette.rb $(SRC)/* $(INCLUDE)/*

.PHONY: all clean fclean re norm libraries
