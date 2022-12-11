#  |  |  ___ \    \  |         |
#  |  |     ) |  |\/ |   _  |  |  /   _
# ___ __|  __/   |   |  (   |    <    __/
#    _|  _____| _|  _| \__,_| _|\_\ \___|
#                              by jcluzet
################################################################################
#                                     CONFIG                                   #
################################################################################

NAME        := push_swap
CC        := gcc
FLAGS    := -Wall -Wextra -Werror -g
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=      arrays.c \
                          list_utils_2.c \
                          list_utils.c \
                          solvers_2.c \
                          counters.c \
                          init.c \
                          moves.c \
                          push_swap.c \
                          lis_utils.c \
                          various_utils.c \
                          solvers.c \
                          free_and_errors.c \

OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

${NAME}:	${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			${CC} ${FLAGS} -o ${NAME} ${OBJS}
			@echo "$(GREEN)$(NAME) created[0m ✔️"

all:		${NAME}

bonus:		all
			cd bonus && $(MAKE)

clean:
			@ ${RM} *.o */*.o */*/*.o
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

bonusclean: clean
			cd bonus && $(MAKE) clean

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

bonusfclean:	fclean
				cd bonus && $(MAKE) fclean

re:			fclean all

bonusre:	re
			cd bonus && $(MAKE) re

.PHONY:		all clean fclean re bonus bonusclean bonusfclean bonusre


