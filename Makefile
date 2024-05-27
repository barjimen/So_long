# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/24 20:29:52 by barjimen          #+#    #+#              #
#    Updated: 2024/05/27 20:57:02 by barjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#---------------------------------- First Part ----------------------------------
 #--- Executables
 
	NAME	:= so_long

#--- Folders

	SRC_DIR		:=		src/
	OBJ_DIR		:=		obj/
	LIB_DIR		:=		lib/
	INC_DIR		:=		inc/
	LFT_DIR		:=		Libft/

#--- MLX
	MLX_DIR = mlx/

#--- Compile

	cc			:=		gcc
	CFLAGS		:=		-g -Wall -Wextra -Werror 
	HEADER		:=		-I$(INC_DIR) -I$(LFT_DIR) -I$(MLX_DIR) 
	MLXCC		:=		-I mlx -L $(MLX_DIR) -lmlx -lXext -lX11

#--- .a LIBFT

	LIBFT		:=		$(LFT_DIR)libft.a
	MLX			:=		$(MLX_DIR)libmlx.a

#--- .C
	
	SRC_FILES	:=		main  		\
						arg_handler \

#--- File variables

	SRC			=		$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
	OBJ			=		$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
	DEPS		=		$(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES)))
	INCS		=		$(addprefix $(INCLUDE), $(addsuffix .h, $(INC_FILES)))
	
#--- Commands

RM				=		rm -f

#--- Cache

OBJF			=		.cache_exists_c

#---------------------------------- Second Part ----------------------------------
all:	makelibs $(MLX)
			@$(MAKE) $(NAME) 

makelibs:
			@$(MAKE) -C $(LFT_DIR)
			@$(MAKE) -C $(MLX_DIR)

-include	${DEPS}
$(NAME):	$(OBJ)
			@$(CC) $(CFLAGS) $(OBJ) $(MLXCC) $(LIBFT) -o $(NAME) 

bonus:
			@$(MAKE)	all

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c $(INCS) | $(OBJF)
			@$(CC) $(CFLAGS) -MMD -c $< -o $@


$(OBJF):
			@mkdir -p $(OBJ_DIR)

$(MLX):
			@make -C $(MLX_DIR)
			
clean:
			@make clean -sC $(LFT_DIR)
			@make clean -sC $(MLX_DIR)
			@$(RM) -rf $(OBJ_DIR)

fclean:		clean
			@$(RM) -f $(NAME)
			@$(RM) -f $(MLX)
			@make fclean -sC $(LFT_DIR)

re:			fclean
			@$(MAKE)

norminette:
			@norminette $(SRC) $(INCLUDE) | grep -v Norme -B1 || true
			@norminette $(INC_DIR) | grep -v Norme -B1 || true

PHONY: all makelibs bone clean fclean re norminette

