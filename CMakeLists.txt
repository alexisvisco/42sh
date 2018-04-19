project(21sh)

set(CMAKE_CXX_STANDARD 11)


file(GLOB_RECURSE 21sh_SRCS ${21sh_SRCS} src/*.c)
file(GLOB_RECURSE 21sh_SRCS ${21sh_SRCS} libft/*.c)
file(GLOB_RECURSE 21sh_SRCS ${21sh_SRCS} *.h)

include_directories(includes)
include_directories(libft/includes)

add_executable(21sh ${21sh_SRCS} src/exec/exec_built_in.c src/backquotes/backquotes_parsing.c includes/backquotes.h src/backquotes/exec_backquotes.c src/backquotes/core_exec_backquotes.c src/backquotes/ft_mine_strjoin.c)