NAME         := ircserv
CC           := c++
SRCS_DIR     := srcs
OBJS_DIR     := .objs
INCS_DIR     := incs
MAIN         := srcs/main.cpp

CFLAGS :=                           \
    -std=c++98                      \
    -Wall                           \
    -Wextra                         \
    -Werror                         \
    -pedantic 

# export ASAN_OPTIONS="log_path=sanitizer.log"
# export ASAN_OPTIONS="detect_leaks=1"

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
    messages/reply.cpp                     \
    base/Command.cpp                    \
    commands/pass.cpp           \
    commands/nick.cpp           \
    commands/user.cpp           \
    commands/ping_pong.cpp      \
    commands/join.cpp           \
    commands/kick.cpp           \
    commands/privmsg.cpp        \
    commands/mode.cpp           \
    commands/invite.cpp         \
    commands/topic.cpp          \
    commands/part.cpp           \
    modes/mode_i.cpp          \
    modes/mode_k.cpp          \
    modes/mode_l.cpp           \
    modes/mode_o.cpp        \
    modes/mode_t.cpp         \
