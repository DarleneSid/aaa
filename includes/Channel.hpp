#pragma once

#include "Server.hpp"

#include <iostream>
#include <vector>
#include <stdint.h>
#include <netinet/in.h>

#define CHANNEL_MODE_INVITE_ONLY   2
#define CHANNEL_MODE_USER_LIMIT    4
#define CHANNEL_MODE_CHANGE_PASS   8
#define CHANNEL_MODE_OPERATOR_PRIV 16
#define CHANNEL_MODE_TOPIC_MANAGE  32

# define CHANNEL_DEFAULT_LIMIT     12

class Channel {
    private:
        std::string             _name;
        std::string             _topic;
        std::string             _password;
        int32_t                 _limits;
        
        std::vector<int32_t>    _fds;
        std::vector<int32_t>    _operator_fds;
        std::vector<int32_t>    _invite_fds;
        
        uint64_t                _mflags;
        bool                    _is_invite_only;
   
    public:
        Channel(std::string name, int32_t fd);
        Channel(std::string name, int32_t fd, std::string password);

        ~Channel();

        std::string             get_name(void) const;
        std::string             get_password(void) const;
        std::string             get_topic(void) const;
        int32_t                 get_limits(void) const;
        uint64_t                get_mflags(void);
        bool                    get_is_invite_only(void);
        
        void                    set_password(std::string npass);
        void                    set_topic(std::string ntopic);
        void                    set_limits(int32_t nlimits);
        void                    set_mflags(uint64_t flag);
        void                    set_is_invite_only(bool add_or_rm);
        
        std::vector<int32_t>    *fetch_fds(void);
        std::vector<int32_t>    *fetch_operator_fds(void);
        std::vector<int32_t>    *fetch_invite_fds(void);
};
