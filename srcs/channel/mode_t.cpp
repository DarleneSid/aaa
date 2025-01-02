#include "Channel.hpp"
#include "utils.hpp"

void    Server::_mode_topic_manage(Channel *channel, bool add_or_rm, int32_t fd) {
    
    std::vector<std::string>    reply_arg;

    if (add_or_rm == REMOVE_MODE) {
        channel->set_mflags(channel->get_mflags() & ~CHANNEL_MODE_TOPIC_MANAGE);

        reply_arg.push_back("-t");    
        _send_nmode_to_channel(channel, fd, reply_arg);

    } else {
        channel->set_mflags(channel->get_mflags() | CHANNEL_MODE_TOPIC_MANAGE);

        reply_arg.push_back("+t");    
        _send_nmode_to_channel(channel, fd, reply_arg);
    }

    channel->set_is_invite_only(add_or_rm);
}
