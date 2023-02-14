##### Colors ####
GREEN	= \033[0;32m
RED	= \033[0;31m
BLUE	= \033[0;34m
END	= \033[0m

##### Names #####
NAME	= philo
LIBNAME	= libft.a
CC	= gcc
CFLAGS	= -Wall -Werror -Wextra

SRCSDIR	= src
OBJSDIR	= obj
INCSDIR	= inc
LIBDIR	= Libft

_SRCS	= main.c \
	parsing_handler.c \
	init_handler.c \
	routine_handler.c \
	utils.c \
	printing.c \

SRCS	= $(addprefix $(SRCSDIR)/, $(_SRCS))
OBJS	= $(SRCS:$(SRCSDIR)%.c=$(OBJSDIR)%.o)
HEADER	= $(addprefix $(INCSDIR)/, $(NAME).h)
##### Makefile work ####

$(OBJSDIR)/%.o: $(SRCSDIR)/%.c $(HEADER)
	@mkdir -p $(OBJSDIR)
	@$(CC) -c $(CFLAGS) -I$(INCSDIR) -I$(LIBDIR) $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	@echo "Baking $(LIBDIR)..."
	@make -s -C $(LIBDIR)
	@echo "$(GREEN)OK!$(END)"
	@echo "Baking $(NAME)..."
	@$(CC) -I$(INCSDIR) -I$(LIBDIR) -o $@ $^ $(LIBDIR)/$(LIBNAME) $(CFLAGS)
	@echo "$(GREEN)OK!$(END)"
	@echo "$(BLUE)$(NAME) READY !$(END)"

clean:
	@echo "Removing objects..."
	@make clean -s -C $(LIBDIR)
	@rm -rf $(OBJSDIR)
	@echo "$(GREEN)Done!$(END)"

fclean: clean
	@echo "Cleaning everything..."
	@make fclean -s -C $(LIBDIR)
	@rm -f $(NAME)
	@echo "$(GREEN)Done!$(END)"
	@echo "$(BLUE)Everything is clean!$(END)"

re:    fclean all

.PHONY: all clean fclean re
