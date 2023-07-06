# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnegro <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 18:05:52 by mnegro            #+#    #+#              #
#    Updated: 2023/04/18 18:05:53 by mnegro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### PHONY TARGET ###
.PHONY: all clean fclean libft re valgrind

### SILENT TARGET ###
.SILENT:

### VARIABLES (DEFINITION) ###
NAME = push_swap
NAME_ARC = libft.a

CC = clang
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

#### TARGETS ####
MSRCS = ft_algoApplies.c ft_algoCombos.c ft_algoFinds.c ft_algoLimits.c ft_algoMovesAB.c \
		ft_algoMovesBA.c ft_algoOpsAB.c ft_algoOpsBA.c  ft_algoTurk.c ft_minorSorts.c \
		ft_miscUtils.c ft_preChecks.c ft_singleArgv.c ft_stackMoves.c ft_stackMoves2X.c \
		ft_stackOps1.c ft_stackOps2.c main.c

MOBJS = ${MSRCS:.c=.o}

DIROBJS = objs/
OBJS = ${addprefix ${DIROBJS},${MOBJS}}

DIRARC = archive/
ARC = ${addprefix ${DIRARC},${NAME_ARC}}

INCLUDE = include

### (EXPLICIT) RULES ###
${DIROBJS}%.o: %.c
	@echo "${YELLOW}Compiling:${WHITE} $< ${DEF_COLOR}"
	${CC} ${CFLAGS} -I ${INCLUDE} -c $< -o $@

${NAME}: libft ${OBJS}
	cp libft/libft.a ${ARC}
	${CC} ${CFLAGS} -L ${DIRARC} -I ${INCLUDE} -o ${NAME} ${OBJS} ${ARC}
	@echo "Rule 'all' for mandatory ${NAME} executed successfully!"

all:	${NAME}

clean:
	${MAKE} -C libft clean
	${RM} ${OBJS}
	@echo "Rule 'clean' for ${NAME} executed successfully!"

fclean: clean
	${MAKE} -C libft fclean
	${RM} ${NAME} ${ARC}
	@echo "Rule 'fclean' for ${NAME} executed successfully!"

libft:
	${MAKE} -C libft

re:	fclean all
	@echo "Rule 're' for ${NAME} executed successfully!"

### COLORS ###

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
