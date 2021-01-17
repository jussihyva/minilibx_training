# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkauppi <jkauppi@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/20 10:35:04 by ubuntu            #+#    #+#              #
#    Updated: 2020/08/22 11:20:07 by jkauppi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LOG					=	/var/tmp/fdf_lib_make.log
LIBFT_H				=	libft.h
FT_PRINTF_H			=	ft_printf.h
LIBFT_A				=	libft.a
FT_PRINTF_A			=	libftprintf.a
MINILIBX_A			=	libmlx_Linux.a

LIBFT_FOLDER		=	libft
FT_PRINTF_FOLDER	=	ft_printf
MINILIBX_FOLDER		=	minilibx-linux
LIB_FOLDERS			=	$(LIBFT_FOLDER) $(FT_PRINTF_FOLDER) $(MINILIBX_FOLDER)
A_FILES				=	$(LIBFT_FOLDER)/$(LIBFT_A)
A_FILES				+=	$(FT_PRINTF_FOLDER)/$(FT_PRINTF_A)
A_FILES				+=	$(MINILIBX_FOLDER)/$(MINILIBX_A)

all: libft ft_printf headers $(LIB_FOLDERS) archives

headers: $(LIBFT_H) $(FT_PRINTF_H)

$(LIBFT_H): $(LIBFT_FOLDER)/$(LIBFT_H)
	cp $(LIBFT_FOLDER)/$(LIBFT_H) ./

$(FT_PRINTF_H): $(FT_PRINTF_FOLDER)/src/$(FT_PRINTF_H)
	cp $(FT_PRINTF_FOLDER)/src/$(FT_PRINTF_H) ./

$(LIB_FOLDERS):
	make -C $@

archives: $(A_FILES)
	cp $^ ./

.PHONY: all $(LIB_FOLDERS) headers archives
