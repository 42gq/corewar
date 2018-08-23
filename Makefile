# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gquerre <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/23 13:11:21 by gquerre           #+#    #+#              #
#    Updated: 2018/08/23 14:02:30 by gquerre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: corewar\
	asm

corewar:
	make -C VM/

asm:
	make -C asm_dir/

clean:
	make clean -C VM/
	make clean -C asm_dir/

fclean:
	make fclean -C VM/
	make fclean -C asm_dir/


re: fclean all
