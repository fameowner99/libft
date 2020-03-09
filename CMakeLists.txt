cmake_minimum_required(VERSION 3.12.3)

project (ft)

set(SOURCE_FILES
${CMAKE_CURRENT_LIST_DIR}/src/ft_abs.c 
${CMAKE_CURRENT_LIST_DIR}/src/ft_isdigit.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_memmove.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_strchr.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_strncpy.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_alloc_2d.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_isprint.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_memset.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_strclr.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_strnequ.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_alloc_2d_int.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_itoa.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_strcmp.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_strnew.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_atoi.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_lstadd.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_printf.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_strcpy.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_strnstr.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_atoi_ui.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_lstdel.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_putchar.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_strdel.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_strrchr.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_bubble_sort.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_lstdelone.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_putchar_fd.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_strdup.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_strsplit.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_bzero.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_lstiter.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_putendl.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_strequ.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_strstr.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_count_digits.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_lstmap.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_putendl_fd.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_striter.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_strsub.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_count_letters.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_lstnew.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_putnbr.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_striteri.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_strtrim.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_count_words.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_max.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_putnbr_fd.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_strjoin.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_swap.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_decode.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_memalloc.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_putstr.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_strlcat.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_tolower.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_free_2d.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_memccpy.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_putstr_fd.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_strlen.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_toupper.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_free_2d_int.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_memchr.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_putstr_fixed_size.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_strmap.c
${CMAKE_CURRENT_LIST_DIR}/src/get_next_line.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_isalnum.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_memcmp.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_realloc.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_strmapi.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_isalpha.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_memcpy.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_realloc_fixed_size.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_strncat.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_isascii.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_memdel.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_strcat.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_strncmp.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_printf/convert_to_another_base.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_printf/get_specifier1.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_printf/parsing1.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_printf/parsing_tools1.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_printf/ft_itoa_for_ui.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_printf/hash.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_printf/parsing2.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_printf/result_output.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_printf/get_specifier.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_printf/parsing.c
${CMAKE_CURRENT_LIST_DIR}/src/ft_printf/parsing_tools.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_write.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_read.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ft_append.c
)
set(HEADER_FILES
${CMAKE_CURRENT_LIST_DIR}/inc/libft.h)

add_library(ft STATIC ${HEADER_FILES} ${SOURCE_FILES})

target_include_directories(ft PRIVATE ${CMAKE_CURRENT_LIST_DIR}/inc)

if (WIN32)
    target_include_directories(ft PUBLIC ${CMAKE_CURRENT_LIST_DIR}/inc/windows_inc)
endif(WIN32)