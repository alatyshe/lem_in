# ----- Colors -----
BLACK ="\033[1;30m"
RED ="\033[1;31m"
GREEN ="\033[1;32m"
YELLOW = "\x1b[33m"
BLUE = "\x1b[34m"
MAGENTA = "\x1b[35m"
CYAN ="\033[1;35m"
PURPLE ="\033[1;36m"
WHITE ="\033[1;37m"
EOC ="\033[0;0m"
RESET = "\x1b[0m"
# ==================

LIB = libft.a

NAME = lem-in
HEAD = header/lem_in.h

FLAGS = -Wall -Wextra -Werror

#------ path -------
HEART_PATH		= ./files/heart
OTHER_PATH		= ./files/other
READ_PATH		= ./files/read
FILL_PATH		= ./files/fill
OPERATIONS_PATH	= ./files/operations
OBJECTS_PATH	= ./objects

#------ files ------
HEART_FILES	= main struct_fill algorithm_2 ways algorithm validate

OTHER_FILES	= struct_create free print other

READ_FILES	= reading

FILL_FILES	= fill_rooms fill_links fill_ants fill_commands fill_start_end

OPERATIONS_FILES = 	links ants rooms

#------ other ------
HEART = $(addprefix $(HEART_PATH)/, $(addsuffix .c, $(HEART_FILES)))
HEART_OBJ = $(addprefix $(OBJECTS_PATH)/, $(addsuffix .o, $(HEART_FILES)))

OTHER = $(addprefix $(OTHER_FILES)/, $(addsuffix .c, $(OTHER_FILES)))
OTHER_OBJ = $(addprefix $(OBJECTS_PATH)/, $(addsuffix .o, $(OTHER_FILES)))

READ = $(addprefix $(READ_FILES)/, $(addsuffix .c, $(READ_FILES)))
READ_OBJ = $(addprefix $(OBJECTS_PATH)/, $(addsuffix .o, $(READ_FILES)))

OPERATIONS = $(addprefix $(OPERATIONS_FILES)/, $(addsuffix .c, $(OPERATIONS_FILES)))
OPERATIONS_OBJ = $(addprefix $(OBJECTS_PATH)/, $(addsuffix .o, $(OPERATIONS_FILES)))

FILL = $(addprefix $(FILL_FILES)/, $(addsuffix .c, $(FILL_FILES)))
FILL_OBJ = $(addprefix $(OBJECTS_PATH)/, $(addsuffix .o, $(FILL_FILES)))


#------ make ------
all: $(NAME)

$(NAME): $(HEART_OBJ) $(OTHER_OBJ) $(READ_OBJ) $(FILL_OBJ) $(OPERATIONS_OBJ)
	@echo "\n"
	@make -C libft/
	@make -C ft_printf/
	@echo $(CYAN) "\tCompiling $@"$(RESET)
	@gcc $(FLAGS) -o $@ $^ libft/libft.a ft_printf/ft_printf.a
	@echo $(GREEN) "\tlem-in\t\t- has been made\n"$(RESET)

$(OBJECTS_PATH)/%.o: $(HEART_PATH)/%.c
	@echo $(PURPLE) "\tCompiling $<"$(RESET)
	@mkdir $(OBJECTS_PATH) 2> /dev/null || true
	@gcc $(FLAGS) -o $@ -c $<

$(OBJECTS_PATH)/%.o: $(OTHER_PATH)/%.c
	@echo $(PURPLE) "\tCompiling $<"$(RESET)
	@mkdir $(OBJECTS_PATH) 2> /dev/null || true
	@gcc $(FLAGS) -o $@ -c $<

$(OBJECTS_PATH)/%.o: $(READ_PATH)/%.c
	@echo $(PURPLE) "\tCompiling $<"$(RESET)
	@mkdir $(OBJECTS_PATH) 2> /dev/null || true
	@gcc $(FLAGS) -o $@ -c $<

$(OBJECTS_PATH)/%.o: $(FILL_PATH)/%.c
	@echo $(PURPLE) "\tCompiling $<"$(RESET)
	@mkdir $(OBJECTS_PATH) 2> /dev/null || true
	@gcc $(FLAGS) -o $@ -c $<

$(OBJECTS_PATH)/%.o: $(OPERATIONS_PATH)/%.c
	@echo $(PURPLE) "\tCompiling $<"$(RESET)
	@mkdir $(OBJECTS_PATH) 2> /dev/null || true
	@gcc $(FLAGS) -o $@ -c $<

#------ make clean ------
cleanlib:
	@make clean -C ./libft
	@make clean -C ./ft_printf

clean: cleanlib
	@echo $(YELLOW)"\t\t\t\tLem-in"$(RESET)
	@rm -f $(HEART_OBJ)
	@rm -f $(OTHER_OBJ)
	@rm -f $(READ_OBJ)
	@rm -f $(OPERATIONS_OBJ)
	@rm -f $(FILL_OBJ)
	@echo $(RED) "\t.o files have been cleaned.\n"$(RESET)

#------ make fclean ------
fcleanlib:
	@make fclean -C ./libft
	@make fclean -C ./ft_printf

fclean: fcleanlib
	@echo $(YELLOW)"\t\t\t\tLem-in"$(RESET)
	@rm -f $(HEART_OBJ)
	@rm -f $(OTHER_OBJ)
	@rm -f $(READ_OBJ)
	@rm -f $(OPERATIONS_OBJ)
	@rm -f $(FILL_OBJ)
	@echo $(RED)"\t.o files have been cleaned."$(RESET)
	@rm -rf $(OBJECTS_PATH)
	@echo $(RED) "\t./objects path have been cleaned."$(RESET)
	@rm -f $(NAME)
	@echo $(RED) "\tLem-in have been cleaned.\n"$(RESET)

#------ make re ------
re: fclean all