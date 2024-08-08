# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/24 20:29:52 by barjimen          #+#    #+#              #
#    Updated: 2024/08/08 20:38:38 by barjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#---------------------------------- First Part ----------------------------------
 #--- Executables
 
	NAME	:= so_long
	NAME_B	:= so_long_bonus

#--- Folders

	SRC_DIR		:=		src/
	BONUS_DIR	:=		src_bonus/
	OBJ_DIR		:=		obj/
	OBJ_DIR_B	:=		obj_bonus/
	LIB_DIR		:=		lib/
	INC_DIR		:=		inc/
	LFT_DIR		:=		Libft/

#--- MLX
	MLX_DIR = mlx/

#--- Compile

	cc			:=		gcc
	CFLAGS		:=		-g -Wall -Wextra -Werror -fsanitize=address
	HEADER		:=		-I$(INC_DIR) -I$(LFT_DIR) -I$(MLX_DIR)
	MLXCC		:=		-I mlx -L $(MLX_DIR) -lmlx -lXext -lX11

#--- .a LIBFT

	LIBFT		:=		$(LFT_DIR)libft.a
	MLX			:=		$(MLX_DIR)libmlx.a

#--- .C
	
	SRC_FILES	:=		main  			 	\
						arg_handler 	 	\
						map_checker 	 	\
						map_checker_char	\
						render_map			\
						image				\
						hooks				\
						ft_str_end_with		\
						check_things		\
						offset_calculator	\
						

	BONUS_FILES	:=			main_bonus  			 	\
							arg_handler_bonus	 	 	\
							map_checker_bonus	 	 	\
							map_checker_char_bonus		\
							render_map_bonus			\
							image_bonus					\
							hooks_bonus					\
							ft_str_end_with_bonus		\
							check_things_bonus			\
							offset_calculator_bonus		\
							animation_bonus				\
							

#--- File variables

	SRC			=		$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
	OBJ			=		$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
	DEPS		=		$(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES)))
	INCS		=		$(addprefix $(INCLUDE), $(addsuffix .h, $(INC_FILES)))
	BONUS		=		$(addprefix $(BONUS_DIR), $(addsuffix .c, $(BONUS_FILES)))
	OBJ_B		=		$(addprefix $(OBJ_DIR_B), $(addsuffix .o, $(BONUS_FILES)))
	DEPS_B		=		$(addprefix $(OBJ_DIR_B), $(addsuffix .d, $(BONUS_FILES)))	
#--- Commands

RM				=		rm -f

#--- Cache

OBJF			=		.cache_exists_c
OBJF_B			=		.cache_exists_c_b

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
			@$(MAKE) $(NAME_B)

-include	${DEPS_B}
$(NAME_B):	$(OBJ_B) makelibs
			@$(CC) $(CFLAGS) $(OBJ_B) $(MLXCC) $(LIBFT) -o $(NAME_B)

$(OBJ_DIR_B)%.o:	$(BONUS_DIR)%.c $(INCS) | $(OBJF_B)
			@$(CC) $(CFLAGS) -MMD -c $< -o $@

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c $(INCS) | $(OBJF)
			@$(CC) $(CFLAGS) -MMD -c $< -o $@
		
$(OBJF_B):
			@mkdir -p $(OBJ_DIR_B)


$(OBJF):
			@mkdir -p $(OBJ_DIR)

$(MLX):
			@make -C $(MLX_DIR)
			
clean:
			@make clean -sC $(LFT_DIR)
			@make clean -sC $(MLX_DIR)
			@$(RM) -rf $(OBJ_DIR)
			@$(RM) -rf $(OBJ_DIR_B)

fclean:		clean
			@$(RM) -f $(NAME)
			@$(RM) -f $(NAME_B)
			@$(RM) -f $(MLX)
			@make fclean -sC $(LFT_DIR)

re:			fclean
			@$(MAKE)

norminette:
			@norminette $(SRC) $(INCLUDE) | grep -v Norme -B1 || true
			@norminette $(INC_DIR) | grep -v Norme -B1 || true

PHONY: all makelibs bonus clean fclean re norminette

