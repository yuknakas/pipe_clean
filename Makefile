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
BON_FLAG=	.bonus_flag

SRCS	=	01_srcs/01_main.c 01_srcs/02_pipex.c \
			01_srcs/03_first_process.c 01_srcs/04_last_process.c
UTIL	=	01_srcs/05_execute.c 01_srcs/10_errors.c 01_srcs/11_pex_split.c \
			01_srcs/12_handle_quote.c

BON		=	10_BON/01_main_bonus.c 10_BON/02_check_args.c 10_BON/03_pipex_bonus.c  \
			10_BON/04_control.c 10_BON/05_first_process_bon.c \
			10_BON/06_midddle_process_bon.c 10_BON/07_last_process_bon.c \
			10_BON/10_here_control.c 10_BON/11_heredoc.c 10_BON/20_errors_bon.c

MAN_SRCS=	$(SRCS) $(UTIL)
BON_SRCS=	$(BON) $(UTIL)
OBJS	=	$(MAN_SRCS:.c=.o)
BON_OBJS=	$(BON_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) libft -C ./00_libft
	@$(CCW) $(OBJS) -L./00_libft -lft -o $(NAME)
	@echo "> make pipex executed in current directory"

%.o: %.c
	@$(CCW) -c $< -o $@

bonus: $(BON_FLAG)

$(BON_FLAG): $(BON_OBJS)
	@$(MAKE) gnl -C ./00_libft
	@$(CCW) $(BON_OBJS) -L./00_libft -lgnl -lft -o $(NAME)
	@touch $(BON_FLAG)
	@echo "> make bonus executed in current directory"

clean:
	@$(MAKE) clean -C ./00_libft
	@$(RMFLAG) $(OBJS) $(BON_OBJS)
	@echo "> make clean executed in current directory"

fclean: clean
	@$(MAKE) fclean -C ./00_libft
	@$(RMFLAG) $(NAME) $(BON_FLAG)
	@echo "> make fclean executed in current directory"

re: fclean all

.PHONY: all bonus clean fclean re