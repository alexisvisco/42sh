# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/01/19 13:46:02 by aviscogl     #+#   ##    ##    #+#        #
#    Updated: 2018/01/23 11:51:13 by ggranjon    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = shell
CC = gcc
CC_FLAGS = -g -Wall -Wextra

LFT_PATH = ./libft
SRC_PATH = ./src/
INC_PATH = -I ./includes -I $(LFT_PATH)/includes
OBJ_PATH = ./obj/

SRC_NAME = \
shell.c \
lex/split.c \
lex/recognize.c \
\
messages/messages.c

OBJ_FOLDERS = editor env eval exec lex messages parser util 
OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
OBJ_FOLDERS_BIS = $(addprefix $(OBJ_PATH),$(OBJ_FOLDERS))

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LFT_PATH)
	$(CC) -o $(NAME) $(OBJ) -L$(LFT_PATH) -lft


$(OBJ_PATH)%.o: $(SRC_PATH)%.c 
	@mkdir -p $(OBJ_PATH) $(OBJ_FOLDERS_BIS)
	$(CC) $(CC_FLAGS) $(INC_PATH) -o $@ -c $^

clean:
	make -C $(LFT_PATH) clean
	rm -rf $(OBJ_PATH)

fclean: clean
	@make -C $(LFT_PATH) fclean
	@rm -f $(NAME)

download_libft:
	@git clone https://github.com/AlexisVisco/libft/
	@cd libft && rm -rf .git

update_libft:
	@rm -rf ./libft
	@git clone https://github.com/AlexisVisco/libft/
	@cd libft && rm -rf .git

git_add:
	@git add includes/*.h
	@git add src/*
	@git add libft/src/*
	@git add libft/includes/*.h
	@git add libft/Makefile
	@git add Makefile
	@git add auteur

norme:
	norminette $(SRC)
	norminette ./includes $(LFT_PATH)/includes

launch: $(NAME)
	@./$(NAME)

re: fclean all

.PHONY: all, $(NAME), clean, fclean, re, download_libft, update_libft, git_add, norme