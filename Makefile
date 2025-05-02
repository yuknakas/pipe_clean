# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/02 09:26:34 by marvin            #+#    #+#              #
#    Updated: 2025/03/02 09:26:34 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CCW		=	cc -Wall -Wextra -Werror
RMFLAG	=	rm -rf
NAME	=	pipex

SRCS	=	01_srcs/01_main.c 01_srcs/02_pipex.c 01_srcs/03_control.c \
			01_srcs/04_process.c 01_srcs/05_heredoc.c 01_srcs/06_execute.c \
			01_srcs/10_errors.c 01_srcs/11_pex_split.c 01_srcs/12_utils.c

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) gnl -C ./00_libft
	@$(CCW) $(OBJS) -L./00_libft -lgnl -lft -o $(NAME)
	@echo "> make pipex executed in current directory"

%.o: %.c
	@$(CCW) -c $< -o $@

clean:
	@$(MAKE) clean -C ./00_libft
	@$(RMFLAG) $(OBJS)
	@echo "> make clean executed in current directory"

fclean: clean
	@$(MAKE) fclean -C ./00_libft
	@$(RMFLAG) $(NAME)
	@echo "> make fclean executed in current directory"

re: fclean all

.PHONY: all clean fclean re