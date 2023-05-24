##### Colors ####
GREEN	= \033[0;32m
RED	= \033[0;31m
BLUE	= \033[0;34m
END	= \033[0m

##### Names #####
NAME	= philo
CC	= gcc
CFLAGS	= -Wall -Werror -Wextra -O3

SRCSDIR	= src
OBJSDIR	= obj
INCSDIR	= inc

_SRCS	= main.c \
	parsing_handler.c \
	init_handler.c \
	routine_handler.c \
	utils.c \
	print_and_mutex.c \
	action.c \
	need_place.c

SRCS	= $(addprefix $(SRCSDIR)/, $(_SRCS))
OBJS	= $(SRCS:$(SRCSDIR)%.c=$(OBJSDIR)%.o)
HEADER	= $(addprefix $(INCSDIR)/, $(NAME).h)
##### Makefile work ####

$(OBJSDIR)/%.o: $(SRCSDIR)/%.c $(HEADER)
	@mkdir -p $(OBJSDIR)
	@$(CC) -c $(CFLAGS) -I$(INCSDIR) $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	@echo "Baking $(NAME)..."
	@$(CC) -I$(INCSDIR) -o $@ $^ $(CFLAGS)
	@echo "$(GREEN)OK!$(END)"
	@echo "$(BLUE)$(NAME) READY !$(END)"

clean:
	@echo "Removing objects..."
	@rm -rf $(OBJSDIR)
	@echo "$(GREEN)Done!$(END)"

fclean: clean
	@echo "Cleaning everything..."
	@rm -f $(NAME)
	@echo "$(GREEN)Done!$(END)"
	@echo "$(BLUE)Everything is clean!$(END)"

re:    fclean all

.PHONY: all clean fclean re
