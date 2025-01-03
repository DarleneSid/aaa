#pragma once

#include "User.hpp"

#include <string>
#include <stdint.h>
#include <vector>

class User;

std::string CREATE_RPL_WELCOME(const User *user, const std::string &networkname, const std::string &servername);
std::string CREATE_RPL_YOURHOST(const User *user, const std::string &servername, const std::string &version);
std::string CREATE_RPL_CREATED(const User *user, const std::string &start_time, const std::string &servername);
std::string CREATE_RPL_MYINFO(const User *user, const std::string &servername, const std::string &version);
std::string CREATE_RPL_UMODEIS(const User *user, const std::vector<std::string> &reply_arg);
std::string CREATE_RPL_CHANNELMODEIS(const std::vector<std::string> &reply_arg);
std::string CREATE_RPL_TOPIC(const User *user, const std::vector<std::string> &reply_arg);
std::string CREATE_RPL_INVITING(const User *user, const std::vector<std::string> &reply_arg);

std::string CREATE_ERR_NOSUCHNICK(const User *user, const std::vector<std::string> &reply_arg);
std::string CREATE_ERR_USERNOTINCHANNEL(const User *user, const std::vector<std::string> &reply_arg);
std::string CREATE_ERR_NOTONCHANNEL(const User *user, const std::vector<std::string> &reply_arg);
std::string CREATE_ERR_USERONCHANNEL(const User *user, const std::vector<std::string> &reply_arg);
std::string CREATE_RPL_ENDOFNAMES(const User *user, const std::vector<std::string> &reply_arg);
std::string CREATE_ERR_NOTREGISTERED(const User *user);
std::string CREATE_ERR_NEEDMOREPARAMS(const User *user, const std::vector<std::string> &reply_arg);
std::string CREATE_ERR_ALREADYREGISTERED(const User *user);
std::string CREATE_ERR_PASSWDMISMATCH(const User *user);
std::string CREATE_ERR_NOTEXTTOSEND(const User *user);
std::string CREATE_ERR_NOSUCHCHANNEL(const User *user, const std::vector<std::string> &reply_arg);
std::string CREATE_ERR_CANNOTSENDTOCHAN(const User *user, const std::vector<std::string> &reply_arg);
std::string CREATE_ERR_NORECIPIENT(const User *user, const std::vector<std::string> &reply_arg);
std::string CREATE_ERR_NONICKNAMEGIVEN(const User *user);
std::string CREATE_ERR_ERRONEUSNICKNAME(const User *user, const std::vector<std::string> &reply_arg);
std::string CREATE_ERR_NICKNAMEINUSE(const User *user, const std::vector<std::string> &reply_arg);
std::string CREATE_ERR_CHANNELISFULL(const User *user, const std::vector<std::string> &reply_arg);
std::string CREATE_ERR_INVITEONLYCHAN(const User *user, const std::vector<std::string> &reply_arg);
std::string CREATE_ERR_BADCHANNELKEY(const User *user, const std::vector<std::string> &reply_arg);
std::string CREATE_ERR_BADCHANMASK(const std::vector<std::string> &reply_arg);
std::string CREATE_ERR_CHANOPRIVSNEEDED(const User *user, const std::vector<std::string> &reply_arg);
std::string CREATE_ERR_UMODEUNKNOWNFLAG(const User *user);
std::string CREATE_ERR_USERSDONTMATCH(const User *user);
std::string CREATE_ERR_INVALIDMODEPARAM(const User *user, const std::vector<std::string> &reply_arg);

std::string CREATE_PER_NICKNAMECHANGE(const std::vector<std::string> &reply_arg);
std::string CREATE_PER_SENDMESSAGETOCHANNEL(const std::vector<std::string> &reply_arg);
