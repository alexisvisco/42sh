# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/02/08 18:43:06 by ggranjon     #+#   ##    ##    #+#        #
#   Updated: 2018/02/09 13:38:04 by ggranjon    ###    #+. /#+    ###.fr     # #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

C_FILES += \
\
io/ft_putchar.c \
io/ft_putfloat.c \
io/ft_putnum.c \
io/ft_putstr.c \
io/ft_putunum.c \
io/get_next_line.c \
\
is/ft_isalnum.c \
is/ft_isalpha.c \
is/ft_isascii.c \
is/ft_isdigit.c \
is/ft_isprint.c \
\
lib/ft_itoa_base.c \
lib/ft_atoi.c \
lib/ft_numstr.c \
lib/find_in_tab.c \
lib/size_tab.c \
\
lst/lst_add.c \
lst/lst_get.c \
lst/lst_foreach.c \
lst/lst_delete.c \
lst/lst_foreach_i.c \
lst/lst_map.c \
lst/lst_collect_if.c \
lst/lst_new.c \
lst/lst_print.c \
lst/lst_printer_preset.c \
lst/lst_push.c \
lst/lst_remove_if.c \
lst/lst_clear.c \
lst/lst_shift.c \
lst/lst_pop.c \
lst/lst_find.c \
lst/lst_reverse.c \
lst/lst_swap.c \
lst/lst_sort.c \
lst/lst_remove_at.c \
lst/lst_size.c \
\
heap/heap_new.c \
heap/heap_add.c \
heap/heap_del.c \
heap/heap_free.c \
heap/heap_get_whole.c \
heap/heap_get.c \
heap/heap_growth.c \
heap/heap_print_preset.c \
heap/heap_print.c \
\
hashtable/ht_has.c \
hashtable/ht_new.c \
hashtable/ht_set.c \
hashtable/ht_hash.c \
hashtable/ht_remove.c \
hashtable/ht_free.c \
hashtable/ht_get.c \
hashtable/ht_print.c \
hashtable/ht_print_preset.c \
\
trie/trie_new.c \
trie/trie_free.c \
trie/trie_insert.c \
trie/trie_is_last_node.c \
trie/trie_search.c \
trie/trie_start_with.c \
trie/trie_char_to_index.c \
\
math/math_abs.c \
math/math_len.c \
math/math_pgcd.c \
math/math_pow.c \
math/math_round.c \
math/math_sqrt.c \
\
mem/ft_bzero.c \
mem/free_smart.c \
mem/ft_memalloc.c \
mem/ft_memccpy.c \
mem/ft_memchr.c \
mem/ft_memcmp.c \
mem/ft_memcpy.c \
mem/ft_memdel.c \
mem/ft_memmove.c \
mem/ft_memset.c \
\
str/ft_strcat.c \
str/ft_strdel_at.c \
str/ft_str_append.c \
str/ft_strchr.c \
str/ft_strclr.c \
str/ft_strcmp.c \
str/ft_strmatch.c \
str/ft_strjoin_multiple.c \
str/ft_strisdigit.c \
str/ft_strcpy.c \
str/ft_strdel.c \
str/ft_strdup.c \
str/ft_strequ.c \
str/ft_striter.c \
str/ft_striteri.c \
str/ft_strjoin.c \
str/ft_strjoinch.c \
str/ft_strlcat.c \
str/ft_strstarts_with.c \
str/ft_strends_with.c \
str/ft_strlen.c \
str/ft_strlen_classic.c \
str/ft_strmap.c \
str/ft_strmapi.c \
str/ft_strncat.c \
str/ft_strncmp.c \
str/ft_strncpy.c \
str/ft_strnequ.c \
str/ft_strnew.c \
str/ft_strnstr.c \
str/ft_strrchr.c \
str/ft_strsplit.c \
str/ft_strsplit_f.c \
str/ft_split.c \
str/ft_strstr.c \
str/ft_strsub.c \
str/ft_strtrim.c \
str/ft_tolower.c \
str/ft_toupper.c \
str/ft_strbasename.c \
str/ft_strrep.c \
\
miniprintf/ft_printf.c \
miniprintf/percent_di.c \
miniprintf/percent_s.c


PROJECT = libft
NAME = $(PROJECT).a
CC = gcc
CFLAGS += -g -Wall -Werror -Wextra

SRC_PATH = ./src/
INC_PATH = ./includes/
OBJ_PATH = ./obj/
OBJ_PATHS = io is lib trie lst heap hashtable math mem str map miniprintf

OBJ_SUB_PATHS = $(addprefix $(OBJ_PATH),$(OBJ_PATHS))
OBJ_NAME = $(C_FILES:.c=.o)
SRC = $(addprefix $(SRC_PATH),$(C_FILES))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_SUB_PATHS)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(NAME): $(OBJ)
	@ar -rc $(NAME) $^
	@ranlib $(NAME)

clean:
	/bin/rm -rf $(OBJ_PATH)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all

git_add:
	make fclean
	git add src/*
	git add Makefile
	git add includes/*
	git add auteur

.PHONY: clean fclean re
