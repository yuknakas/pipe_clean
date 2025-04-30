# **************************************************************************** #
#																			  #
#														 :::	  ::::::::	#
#	Makefile										   :+:	  :+:	:+:	#
#													 +:+ +:+		 +:+	  #
#	By: yuknakas <yuknakas@student.42.fr>		  +#+  +:+	   +#+		 #
#												 +#+#+#+#+#+   +#+			#
#	Created: 2024/11/17 14:57:32 by yuknakas		  #+#	#+#			  #
#	Updated: 2025/02/14 10:19:55 by yuknakas		 ###   ########.fr		#
#																			  #
# **************************************************************************** #

CCW			=	cc -Wall -Wextra -Werror
NAME_LIBFT	=	libft.a
NAME_GNL	=	libgnl.a
NAME_GNL_BON=	libgnl_bon.a

CTYPE		=	ctype/ft_isalnum.c ctype/ft_isalpha.c ctype/ft_isascii.c ctype/ft_isdigit.c \
				ctype/ft_isprint.c ctype/ft_tolower.c ctype/ft_toupper.c
FD			=	fd/ft_putchar_fd.c fd/ft_putendl_fd.c fd/ft_putnbr_fd.c fd/ft_putstr_fd.c
LST			=	lst/ft_lstadd_back_bonus.c lst/ft_lstadd_front_bonus.c lst/ft_lstclear_bonus.c \
				lst/ft_lstdelone_bonus.c lst/ft_lstiter_bonus.c lst/ft_lstlast_bonus.c \
				lst/ft_lstmap_bonus.c lst/ft_lstnew_bonus.c lst/ft_lstsize_bonus.c
MEMORY		=	memory/ft_bzero.c memory/ft_memchr.c memory/ft_memcmp.c memory/ft_memcpy.c \
				memory/ft_memmove.c memory/ft_memset.c
STDLIB		=	stdlib/ft_atoi.c stdlib/ft_calloc.c stdlib/ft_itoa.c
STRING		=	string/ft_split.c string/ft_strchr.c string/ft_strdup.c string/ft_striteri.c \
				string/ft_strjoin.c string/ft_strlcat.c string/ft_strlcpy.c string/ft_strlen.c \
				string/ft_strmapi.c string/ft_strncmp.c string/ft_strnstr.c string/ft_strrchr.c \
				string/ft_strtrim.c string/ft_substr.c

GNL_SRCS	=	gnl/get_next_line.c
GNL_BON_SRCS=	gnl/get_next_line_bonus.c gnl/free_double_pointer.c

SRCS_MAN	=	$(CTYPE) $(FD) $(MEMORY) $(STDLIB) $(STRING)
SRCS_BON	=	$(LST)
OBJS_MAN	=	$(SRCS_MAN:%.c=%.o)
OBJS_BON	=	$(SRCS_BON:%.c=%.o)
OBJS_GNL	=	$(GNL_SRCS:%.c=%.o)
OBJS_GNL_BON=	$(GNL_BON_SRCS:%.c=%.o)
OBJS		=	$(OBJS_MAN) $(OBJS_BON) $(OBJS_GNL) $(OBJS_GNL_BON)
BONUS_FLAG	=	.bonus_flag

all: libft gnl gnl_bon libft_bonus

libft: $(OBJS_MAN)
	@ar rcs $(NAME_LIBFT) $(OBJS_MAN)
	@echo "> make libft executed in 00_libft"

gnl: libft $(OBJS_GNL)
	@ar rcs $(NAME_GNL)	$(OBJS_GNL) $(NAME_LIBFT)
	@echo "> make gnl executed in 00_libft"

gnl_bon: libft $(OBJS_GNL_BON)
	@ar rcs $(NAME_GNL_BON)	$(OBJS_GNL_BON) $(NAME_LIBFT)
	@echo "> make gnl_bon executed in 00_libft"

%.o: %.c
	@$(CCW) -c $< -o $@

libft_bonus: $(BONUS_FLAG)

$(BONUS_FLAG): $(OBJS_MAN) $(OBJS_BON)
	@ar rcs $(NAME_LIBFT) $(OBJS_BON)
	@touch $(BONUS_FLAG)
	@echo "> make libft_bonus executed in 00_libft"

clean:
	@rm -f $(OBJS) $(BONUS_FLAG)
	@echo "> make clean executed in 00_libft"

fclean: clean
	@rm -f $(NAME_LIBFT) $(NAME_GNL) $(NAME_GNL_BON)
	@echo "> make fclean executed in 00_libft"

re: fclean all

.PHONY: all bonus gnl gnl_bon clean fclean re