# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eluceon <eluceon@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/01 19:41:25 by eluceon           #+#    #+#              #
#    Updated: 2021/04/05 17:59:29 by eluceon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

B&W = \033[0;0m
RED = \033[0;31m
GREEN = \033[0;32m
PURPLE = \033[0;35m

RM = rm -rf
NAME = libasm.a

SRCS = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
SRCDIR = ./srcs/

OBJDIR = ./obj/
OBJS = $(addprefix $(OBJDIR), $(SRCS:.s=.o))

$(NAME): $(OBJDIR) $(OBJS)
	ar rcs $(NAME) $(OBJS)
	@echo "$(PURPLE) $(NAME) has been created $(B&W)"

all: $(NAME)

$(OBJS): $(OBJDIR)%.o: $(SRCDIR)%.s
	# nasm -f macho64 $< -o $@
	nasm -f elf64 -g $< -o $@
	@echo "$(GREEN) Object file $(PURPLE)$@ $(GREEN)has been created $(B&W)"

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	$(RM) $(OBJDIR)
	@echo "$(RED) $(OBJDIR) has been deleted $(B&W)"

fclean: clean
	$(RM) $(NAME)
	@echo "$(RED) $(NAME) has been deleted $(B&W)"

re:	fclean all

.PHONY: all clean fclean re
