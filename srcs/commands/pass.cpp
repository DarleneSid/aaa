#include "Server.hpp"
#include "User.hpp"

void	Server::_command_pass(std::vector<std::string> cmd, int32_t fd) {

    std::vector<std::string>    reply_arg;

    if (cmd.size() != 2) {
        reply_arg.push_back(cmd[0]);
        _send_reply(fd, 461, reply_arg);
        return ;
    }

    if (_users[fd]->get_nickname() != DEFAULT_INFO_VALUE) {
        _send_reply(fd, 462, reply_arg);
        return ;
    }

    if (_password != cmd[1]) {
        _send_reply(fd, 464, reply_arg);
        return ;
    }

    _users[fd]->set_pass_is_valid(true);
}
