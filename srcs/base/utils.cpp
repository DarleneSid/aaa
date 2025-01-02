#include "utils.hpp"
#include "color.hpp"

std::vector<std::string>	split(std::string cmd, char delimiter) {
    
    std::vector<std::string>    tokens;
    std::istringstream          token_stream(cmd);
    std::string                 token;
    
    while (std::getline(token_stream, token, delimiter)) {
        tokens.push_back(token);
    }
    return (tokens);
}

bool    find_fds_in_vec(std::vector<int32_t> *vec, const int32_t fd) {

    for (std::vector<int32_t>::iterator it = vec->begin(); it != vec->end(); it++) {

        if (*it == fd)
            return (true);
    }
    return (false);
}

int32_t    nickname_is_in_channel(std::map<int, User *> &users, Channel *channel, std::string &nickname) {
    
    for (std::vector<int32_t>::iterator it = channel->fetch_fds()->begin(); it != channel->fetch_fds()->end(); it++) {
        if (users[*it]->get_nickname() == nickname) {
            return (*it);
        }
    }
    return (0);
}

int32_t    search_fd_by_nickname(std::map<int, User *> &users, std::string &nickname) {
    
    for (std::map<int, User *>::iterator it = users.begin(); it != users.end(); it++) {
        if ((*it).second->get_nickname() == nickname) {
            return ((*it).second->get_fd());
        }
    }
    return (0);
}

Channel     *channel_is_existing(std::vector<Channel *> &c_list, std::string &c_name) {
    
    for (std::vector<Channel *>::iterator it = c_list.begin(); it != c_list.end(); it++) {
        if ((*it)->get_name() == c_name) {
            return (*it);
        }
    }
    return (NULL);
}