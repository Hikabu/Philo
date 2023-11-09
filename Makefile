NAME			=	philo
BON				=	philo_bonus
SRCS 			=	main.c time.c parc_act.c init.c
HEADERS 		=	philo.h
OBJ 			=	$(SRCS:.c=.o)
CFLAGS 			=	-Wall -Wextra -Werror -Imlx -g #-fsanitize=thread
IFLAGS			=	-Ilibft
LFLAGS			=	-Llibft -lft
RM				=	rm -rf
BSRC			=	
BOBJ 			=	$(BSRC:.c=.o)

YELLOW  = \033[33m
PURPLE  = \033[32m
END     = \033[0m

%.o: %.c $(HEADERS) Makefile
	@cc -c $(CFLAGS) $(IFLAGS) $< -o $@

all: $(NAME)

$(NAME): $(OBJ) libft/libft.a
	cc $(CFLAGS) $(IFLAGS) $(OBJ) $(LFLAGS) -o $@
	@echo "$(YELLOW) Executable file $(NAME) was compiled $(END)"

FORCE:

libft/libft.a: FORCE
	cd libft && make


bonus: $(BON)
$(BON): $(BOBJ) libft/libft.a
	cc $(CFLAGS) $(IFLAGS) $(BOBJ) -L./libft -lft -o $@
	@echo "$(YELLOW) Executable file $(BON) was compiled $(END)"

clean:
	$(RM) $(OBJ) $(BOBJ) $(BON)
	make -C libft fclean
	@echo "$(PURPLE) Executable file $(NAME) was deleted$(END)"

fclean:	clean
	$(RM) $(NAME) $(BON)
	@echo "$(PURPLE) Executable file $(NAME) was compiled$(END)"
re:	fclean all

.PHONY: all clean fclean re libft bonus

