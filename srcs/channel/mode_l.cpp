#include "Channel.hpp"
#include "utils.hpp"
#include <cstdlib>
#include <limits.h>

static int32_t  limits_is_valid(std::string limits) {

    uint64_t    nlimits = std::atoi(limits.c_str());
    
    if (nlimits > INT_MAX)
        return (0);
    return (nlimits);
}

void    Server::_mode_user_limit(Channel *channel, std::vector<std::string> &cmd, bool add_or_rm, int32_t fd) {

    std::string                 limits;    
    uint8_t                     nlimits;
    std::vector<std::string>    reply_arg;

    if (add_or_rm == REMOVE_MODE) {
        logger(INFO, "Mode -l set, user limit mode deleted on this channel");

        channel->set_mflags(channel->get_mflags() & ~CHANNEL_MODE_USER_LIMIT);
        channel->set_limits(CHANNEL_DEFAULT_LIMIT);

        reply_arg.push_back("-l");    
        _send_nmode_to_channel(channel, fd, reply_arg);
    
    } else if (add_or_rm == ADD_MODE) {
        
        if (cmd.size() >= 4) {
            
            limits = cmd[3].substr(0, cmd[3].find(','));

            if ((nlimits = limits_is_valid(limits)) != false) {
                logger(INFO, "Mode +l set, new user limit on this channel");
                
                channel->set_mflags(channel->get_mflags() | CHANNEL_MODE_USER_LIMIT);
                channel->set_limits(nlimits);

                reply_arg.push_back("+l");    
                _send_nmode_to_channel(channel, fd, reply_arg);

            } else {
                logger(WARNING, "Invalid user limit");

                reply_arg.push_back(cmd[1]);
                reply_arg.push_back("+l");
                reply_arg.push_back(limits);
                reply_arg.push_back(":Invalid user limit");
                _send_reply(fd, 696, reply_arg);
            }
        } else {
            logger(WARNING, "Missing user limit");

            reply_arg.push_back(cmd[1]);
            reply_arg.push_back("+l");
            reply_arg.push_back("Missing user limit");
            reply_arg.push_back(":Missing user limit");
            _send_reply(fd, 696, reply_arg);
        }
        cmd[3].erase(0, cmd[3].find(',') + 1);
    }
}
