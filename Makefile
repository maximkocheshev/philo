
_GREEN	=	\x1b[32m

NAME	=	philo

NAME_B	=	philo_bonus/philo_bonus

SRCS	=	philo.c ft_parsing.c ft_atoi.c ft_init.c ft_routine.c utils.c

SRCS_B	=	philo_bonus/philo_bonus.c philo_bonus/ft_parsing_bonus.c philo_bonus/ft_atoi_bonus.c \
			philo_bonus/ft_init_bonus.c philo_bonus/ft_strcpy_bonus.c \
			philo_bonus/ft_routine_bonus.c philo_bonus/utils_bonus.c

HEADER	=	philo.h
OBJS	=	${SRCS:.c=.o}
HEADER_B	=	philo_bonus/philo_bonus.h
OBJS_B	=	${SRCS_B:.c=.o}

CC		=	gcc

FLAGS	=	-Wall -Werror -Wextra -pthread

RM		=	rm -f

.PHONY	:	all clean fclean re bonus

all		:	${NAME}

${NAME}	:	${OBJS} ${HEADER}
			${CC} ${FLAGS} ${OBJS} -o ${NAME}
			@echo "$(_GREEN) Executable '$(NAME)' created! $(_END)✅"

bonus	:
			make OBJS="${OBJS_B}" HEADER="${HEADER_B}" NAME="${NAME_B}" all

clean	:	
			${RM} ${OBJS} ${OBJS_B}

fclean	:	clean
			${RM} ${NAME} ${NAME_B}
			@echo "$(_GREEN) Executable file has been deleted! $(_END)🗑️"

re		: 	fclean all