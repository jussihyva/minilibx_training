# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhani <juhani@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/20 10:35:04 by ubuntu            #+#    #+#              #
#    Updated: 2021/03/06 14:45:21 by juhani           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

A_FILES				=	libft/libft.a ft_printf/libftprintf.a \
						minilibx-linux/libmlx_Linux.a \
						libft_addons/libft_addons.a
H_FILES				=	libft/libft.h ft_printf/include/ft_printf.h \
						minilibx-linux/mlx.h minilibx-linux/mlx_int.h \
						libft_addons/include/libft_addons.h
LIB_FOLDERS			=	$(dir $(A_FILES))

.PHONY: all
all: libraries h_files archives

.PHONY: h_files
h_files: $(H_FILES)
	@cp -f $^ ./

.PHONY: libraries
libraries:
	for folder in $(LIB_FOLDERS) ; do \
	    make -C $$folder ; \
	done

.PHONY: archives
archives: $(A_FILES)
	@cp -f $^ ./

.PHONY: clean
clean:
	for folder in $(LIB_FOLDERS) ; do \
	    make -C $$folder clean ; \
	done
	rm -f $(notdir $(H_FILES))
	rm -f $(notdir $(A_FILES))

.PHONY: fclean
fclean:
	for folder in $(LIB_FOLDERS) ; do \
		make -C $$folder fclean ; \
	done
	rm -f $(notdir $(H_FILES))
	rm -f $(notdir $(A_FILES))

.PHONY: re
re: all
	for folder in $(LIB_FOLDERS) ; do \
	    make -C $$folder re ; \
	done

.PHONY: norm
norm:
	for folder in $(LIB_FOLDERS) ; do \
	    make -C $$folder norm ; \
	done
