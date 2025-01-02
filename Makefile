NAME         := ircserv
CC           := c++
SRCS_DIR     := srcs
OBJS_DIR     := .objs
INCS_DIR     := includes
MAIN         := srcs/main.cpp

CFLAGS :=                           \
    -std=c++98                      \
    -Wall                           \
    -Wextra                         \
    -Werror                         \
    -pedantic 

CFLAGS_DBG :=                       \
    -g3                             \
    -O0                             \
    -fsanitize=address              \
    -fsanitize=undefined            \
    -fno-omit-frame-pointer         \
    -fstack-protector-strong        \
    -fno-optimize-sibling-calls 

SRCS :=                                 \
    base/Server.cpp                     \
    base/User.cpp                       \
    base/utils.cpp                      \
    base/Channel.cpp                    \
    messages/reply.cpp                   \
    base/Command.cpp                    \
    commands/pass.cpp                   \
    commands/nick.cpp                   \
    commands/user.cpp                   \
    commands/ping_pong.cpp              \
    commands/join.cpp                   \
    commands/kick.cpp                   \
    commands/privmsg.cpp                \
    commands/mode.cpp                   \
    commands/invite.cpp                 \
    commands/topic.cpp                  \
    commands/part.cpp                   \
    channel/mode_i.cpp                  \
    channel/mode_k.cpp                  \
    channel/mode_l.cpp                  \
    channel/mode_o.cpp                  \
    channel/mode_t.cpp                  

SRCS_OBJS := $(patsubst %.cpp,$(OBJS_DIR)/%.o,$(SRCS))

$(OBJS_DIR)/%.o:$(SRCS_DIR)/%.cpp
	@mkdir -vp $(dir $@)
	@echo "Compiling $<..."
	@$(CC) \
		$(CFLAGS) \
		-MMD \
		-MP \
		-o $@ \
		-c $< \
		-I $(INCS_DIR)

all: $(NAME)

-include  $(SRCS_OBJS:.o=.d)

$(NAME): $(SRCS_OBJS)
	@echo "Linking $(NAME)..."
	@$(CC) \
		$^ \
		$(MAIN) \
		$(CFLAGS) \
		-o $(NAME) \
		-I $(INCS_DIR)
	@echo "Build complete: $(NAME)"

g: CFLAGS += $(CFLAGS_DBG)
g: all

clean:
	@echo "Cleaning object files..."
	@rm -rf $(OBJS_DIR)

fclean: clean
	@echo "Removing $(NAME)..."
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean g fclean re
