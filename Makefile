#wanted
CLIENT = client
SERVER = server

#compile
CC = cc
CFLAGS = -Wall -Werror -Wextra

#dir
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = lib/libft
FT_PRINTF_DIR = lib/ftprintf
INC_DIR = include
INCLUDE = -I ./include 

#file
SRC_CLIENT = $(SRC_DIR)/client/client.c
SRC_SERVER = $(SRC_DIR)/server/server.c
OBJ_CLIENT = $(SRC_CLIENT:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ_SERVER = $(SRC_SERVER:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

#libs
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
LIBS = -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf

#Header
HEADERS = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR)

#rules
all:LIBFT FT_PRINTF $(CLIENT) $(SERVER) 

$(CLIENT): $(LIBFT) $(FT_PRINTF) $(OBJ_CLIENT)
		$(CC) $(CFLAGS) $(OBJ_CLIENT) $(HEADERS) $(LIBS) -o $(CLIENT)
		

$(SERVER): $(LIBFT) $(FT_PRINTF) $(OBJ_SERVER)
		$(CC) $(CFLAGS) $(OBJ_SERVER) $(HEADERS) $(LIBS) -o $(SERVER)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/minitalk.h 
		@mkdir -p $(@D)
		$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@
LIBFT :
	$(MAKE) -C $(LIBFT_DIR)
FT_PRINTF :
	$(MAKE) -C $(FT_PRINTF_DIR)

clean:
		$(MAKE) -C $(LIBFT_DIR) clean
		$(MAKE) -C $(FT_PRINTF_DIR) clean
		rm -rf $(OBJ_DIR)

fclean: clean
		$(MAKE) -C $(LIBFT_DIR) fclean
		$(MAKE) -C $(FT_PRINTF_DIR) fclean
		rm -f $(CLIENT)
		rm -f $(SERVER)

re: fclean all

.PHONY: all clean fclean re 
