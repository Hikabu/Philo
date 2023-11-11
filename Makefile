NAME			=	philo
BON				=	philo_bonus
SRCS 			=	main.c time.c parc_act.c init.c utils.c
HEADERS 		=	philo.h
OBJ 			=	$(SRCS:.c=.o)
CFLAGS 			=	-Wall -Wextra -Werror -g3 #-fsanitize=address
RM				=	rm -rf
BSRC			=	
BOBJ 			=	$(BSRC:.c=.o)

YELLOW  = \033[33m
PURPLE  = \033[32m
END     = \033[0m

%.o: %.c $(HEADERS) Makefile
	@cc -c $(CFLAGS) $(IFLAGS) $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	cc $(CFLAGS) $(OBJ) -o $@
	@echo "$(YELLOW) Executable file $(NAME) was compiled $(END)"

bonus: $(BON)
$(BON): $(BOBJ) 
	cc $(CFLAGS) $(BOBJ) -o $@
	@echo "$(YELLOW) Executable file $(BON) was compiled $(END)"

 clean:
	$(RM) $(OBJ) $(BOBJ) $(BON)
	@echo "$(PURPLE) Executable file $(NAME) was deleted$(END)"

fclean:	clean
	$(RM) $(NAME) $(BON)
	@echo "$(PURPLE) Executable file $(NAME) was deleted$(END)"
re:	fclean all

.PHONY: all clean fclean re libft bonus

