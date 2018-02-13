project(21sh)

set(CMAKE_CXX_STANDARD 11)


file(GLOB_RECURSE 21sh_SRCS ${21sh_SRCS} src/*.c)
file(GLOB_RECURSE 21sh_SRCS ${21sh_SRCS} libft/*.c)
file(GLOB_RECURSE 21sh_SRCS ${21sh_SRCS} *.h)

include_directories(includes)
include_directories(libft/includes)

add_executable(21sh ${21sh_SRCS} src/util/replace_env_variables.c src/util/ft_repall.c)