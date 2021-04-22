NAME = libftprintf.a

SRCS =  srcs/ft_analyze.c \
		srcs/ft_itoas.c \
		srcs/ft_printf.c \
		srcs/ft_printf_is.c \
		srcs/ft_printf_ps.c \
		srcs/ft_printf_ss.c \
		srcs/ft_printf_ss1.c \
		srcs/ft_printf_us.c \
		srcs/ft_printf_xm.c \
		srcs/ft_printf_xp.c \
		srcs/ft_utils.c \

OBJECTS =  ft_analyze.o \
		ft_itoas.o \
		ft_printf.o \
		ft_printf_is.o \
		ft_printf_ps.o \
		ft_printf_ss.o \
		ft_printf_ss1.o \
		ft_printf_us.o \
		ft_printf_xm.o \
		ft_printf_xp.o \
		ft_utils.o \

INCLUDES = includes/ft_printf.h

$(OBJECTS): $(SRCS) $(INCLUDES)
	@gcc -Wextra -Werror -Wall -c $(SRCS)
	@ar rcs $(NAME) $(OBJECTS) 

$(NAME): $(OBJECTS)

all: $(NAME)

clean:
	rm -rf $(OBJECTS)
	
fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re