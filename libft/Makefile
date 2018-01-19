# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/17 14:07:28 by aviscogl     #+#   ##    ##    #+#        #
#    Updated: 2018/01/05 14:14:44 by aviscogl    ###    #+. /#+    ###.fr      #
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
map/map_new.c \
map/map_print.c \
map/map_get.c \
map/map_getv.c \
map/map_del.c \
map/map_set.c \
map/map_unset.c \
\
math/math_abs.c \
math/math_len.c \
math/math_pgcd.c \
math/math_pow.c \
math/math_round.c \
math/math_sqrt.c \
\
mem/ft_bzero.c \
mem/free_debug.c \
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
str/ft_strreplace.c \
str/ft_strreplace_first.c \
str/ft_strsplit.c \
str/ft_strsplit_f.c \
str/ft_split.c \
str/ft_strstr.c \
str/ft_strsub.c \
str/ft_strtrim.c \
str/ft_tolower.c \
str/ft_toupper.c \
str/ft_strbasename.c \
\
printf/converter/c_intmax.c \
printf/converter/c_uintmax.c \
printf/converter/c_unicode.c \
printf/struct/formatter.c \
printf/evaluator/eval_string/compute/str_compute.c \
printf/evaluator/eval_string/compute/str_padding.c \
printf/evaluator/eval_string/compute/str_delprec_0.c \
printf/evaluator/eval_string/compute/str_precision.c \
printf/evaluator/eval_string/compute/wstr_precision.c \
printf/evaluator/eval_string/get_string.c \
printf/evaluator/eval_string/get_wstring.c \
printf/evaluator/eval_char/get_char.c \
printf/evaluator/eval_char/get_wchar.c \
printf/evaluator/eval_base/get_base.c \
printf/evaluator/eval_base/compute/base_compute.c \
printf/evaluator/eval_base/compute/base_zero.c \
printf/evaluator/eval_base/compute/base_delprec_0.c \
printf/evaluator/eval_base/compute/base_hash.c \
printf/evaluator/eval_number/get_val.c \
printf/evaluator/eval_number/get_uval.c \
printf/evaluator/eval_number/get_number.c \
printf/evaluator/eval_number/compute/number_precision.c \
printf/evaluator/eval_number/compute/number_zero.c \
printf/evaluator/eval_number/compute/number_space.c \
printf/evaluator/eval_number/compute/number_plus.c \
printf/evaluator/eval_number/compute/number_compute.c \
printf/evaluator/eval_pointer/compute/pointer_compute.c \
printf/evaluator/eval_pointer/get_pointer.c \
printf/evaluator/core.c \
printf/evaluator/evaluator.c \
printf/evaluator/dynamic_value.c \
printf/parser/extract_flags.c \
printf/parser/extract_full.c \
printf/parser/extract_length.c \
printf/parser/extract_precision.c \
printf/parser/extract_width.c \
printf/parser/extractor.c \
printf/util/ft_str_repeat.c \
printf/util/ft_strrep_first_aft.c \
printf/util/unicode.c \
printf/printf.c \

PROJECT = libft
NAME = $(PROJECT).a
CC = gcc
CFLAGS += -g -Wall -Werror -Wextra

SRC_PATH = ./src/
INC_PATH = ./includes/
OBJ_PATH = ./obj/
OBJ_PATHS = io is lib lst math mem printf str map printf/parser printf/struct printf/util printf/converter printf/evaluator \
printf/evaluator/eval_base printf/evaluator/eval_char printf/evaluator/eval_number \
printf/evaluator/eval_pointer printf/evaluator/eval_string printf/evaluator/eval_string/compute \
printf/evaluator/eval_base/compute printf/evaluator/eval_number/compute \
printf/evaluator/eval_pointer/compute

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

test: all
	gcc -g -L. -lft -I $(INC_PATH) main/main.c -o test_libft.out

##	Use the compiled libft : 
##		gcc -L. -lft -I $(INC_PATH) [C_FILES] -o [NAME_OUTPUT]

.PHONY: clean fclean re