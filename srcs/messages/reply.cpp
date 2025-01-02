#include "reply.hpp"

std::string	CREATE_RPL_WELCOME(const User *user, const std::string &networkname, const std::string &servername) {

    return (
        ":" + servername + " 001 " + user->get_nickname() + " :Welcome to the " + networkname + " Network, "
        + user->get_nickname() + "[!" + user->get_username() + "@" + user->get_hostname() + "]\r\n"
    );
}

std::string	CREATE_RPL_YOURHOST(const User *user, const std::string &servername, const std::string &version) {

    return (
        ":" + servername + " 002 " + user->get_nickname() + " :Your host is "
        + servername + ", running version " + version + "\r\n"
    );
}

std::string	CREATE_RPL_CREATED(const User *user, const std::string &start_time, const std::string &servername) {

    return (
        ":" + servername + " 003 " + user->get_nickname()
        + " :This server was created " + start_time + "\r\n"
    );
}

std::string	CREATE_RPL_MYINFO(const User *user, const std::string &servername, const std::string &version) {

    return (
        ":" + servername + " 004 " + user->get_nickname() + " "
        + servername + " " + version + "\n[ -k -i -o -t -l ] [ -k -o -l ]" + "\r\n"
    );
}

std::string CREATE_RPL_UMODEIS(const User *user, const std::vector<std::string> &reply_arg) {
    
    return (user->get_prefix() + " 221 " + reply_arg[0] + "\r\n");
}

std::string CREATE_RPL_CHANNELMODEIS(const std::vector<std::string> &reply_arg) {
    return (reply_arg[1] + " " + reply_arg[2] + " " + reply_arg[0] + "\r\n");
}

std::string CREATE_RPL_TOPIC(const User *user, const std::vector<std::string> &reply_arg) {
    
    return (":" + user->get_hostname() + " 332 " + user->get_nickname() + " " + reply_arg[1] + " :" + reply_arg[2] + "\r\n");
}

std::string CREATE_RPL_INVITING(const User *user, const std::vector<std::string> &reply_arg) {
    
    return (user->get_prefix() + " 341 " + reply_arg[0] + " :" + reply_arg[1] + "\r\n");
}

std::string	CREATE_RPL_ENDOFNAMES(const User *user, const std::vector<std::string> &reply_arg) {

    return (user->get_prefix() + " 366 " + reply_arg[0] + " :End of /NAMES list\r\n");
}

std::string	CREATE_ERR_NOSUCHNICK(const User *user, const std::vector<std::string> &reply_arg) {

    return (user->get_prefix() + " 401 " + reply_arg[0] + " :No such nick/channel\r\n");
}

std::string	CREATE_ERR_NOSUCHCHANNEL(const User *user, const std::vector<std::string> &reply_arg) {

    return (user->get_prefix() + " 403 " + reply_arg[0] + " :No such channel\r\n");
}

std::string	CREATE_ERR_CANNOTSENDTOCHAN(const User *user, const std::vector<std::string> &reply_arg) {

    return (user->get_prefix() + " 404 " + reply_arg[0] + " :Cannot send to channel\r\n");
}

std::string	CREATE_ERR_NORECIPIENT(const User *user, const std::vector<std::string> &reply_arg) {

    return (user->get_prefix() + " 411 :No recipient given (" + reply_arg[0] + ")\r\n");
}

std::string	CREATE_ERR_NOTEXTTOSEND(const User *user) {

    return (user->get_prefix() + " 412 :No text to send\r\n");
}

std::string	CREATE_ERR_NONICKNAMEGIVEN(const User *user) {

    return (user->get_prefix() + " 431 :No nickname given\r\n");
}

std::string	CREATE_ERR_ERRONEUSNICKNAME(const User *user, const std::vector<std::string> &reply_arg) {

    return (user->get_prefix() + " 432 " + reply_arg[0] + " :Erroneus nickname\r\n");
}

std::string	CREATE_ERR_NICKNAMEINUSE(const User *user, const std::vector<std::string> &reply_arg) {

    return (user->get_prefix() + " 433 " + reply_arg[0] + " :Nickname is already in use\r\n");
}

std::string	CREATE_ERR_USERNOTINCHANNEL(const User *user, const std::vector<std::string> &reply_arg) {

    return (user->get_prefix() + " 441 " + reply_arg[0] + " " + reply_arg[1] + " :They aren't on that channel\r\n");
}

std::string	CREATE_ERR_NOTONCHANNEL(const User *user, const std::vector<std::string> &reply_arg) {

    return (user->get_prefix() + " 442 " + reply_arg[0] + " :You're not on that channel\r\n");
}

std::string	CREATE_ERR_USERONCHANNEL(const User *user, const std::vector<std::string> &reply_arg) {

    return (user->get_prefix() + " 443 " + reply_arg[0] + " " + reply_arg[1] + " :is already on channel\r\n");
}

std::string	CREATE_ERR_NOTREGISTERED(const User *user) {

    return (user->get_prefix() + " 451 :You have not registered\r\n");
}

std::string	CREATE_ERR_NEEDMOREPARAMS(const User *user, const std::vector<std::string> &reply_arg) {

    return (user->get_prefix() + " 461 " + reply_arg[0] + " :Not enough parameters\r\n");
}

std::string	CREATE_ERR_ALREADYREGISTERED(const User *user) {

    return (user->get_prefix() + " 462 :You may not reregister\r\n");
}

std::string	CREATE_ERR_PASSWDMISMATCH(const User *user) {

    return (user->get_prefix() + " 464 :Password incorrect\r\n");
}

std::string	CREATE_ERR_CHANNELISFULL(const User *user, const std::vector<std::string> &reply_arg) {

    return (":" + user->get_hostname() + " 471 " + user->get_nickname() + " " + reply_arg[0] + " :Cannot join channel (+l)\r\n");
}

std::string	CREATE_ERR_INVITEONLYCHAN(const User *user, const std::vector<std::string> &reply_arg) {

    return (":" + user->get_hostname() + " 473 " + user->get_nickname() + " " + reply_arg[0] + " :Cannot join channel (+i)\r\n");
}

std::string	CREATE_ERR_BANNEDFROMCHAN(const User *user, const std::vector<std::string> &reply_arg) {

    return (user->get_prefix() + " 474 " + reply_arg[0] + " :Cannot join channel (+b)\r\n");
}

std::string	CREATE_ERR_BADCHANNELKEY(const User *user, const std::vector<std::string> &reply_arg) {

    return (":" + user->get_hostname() + " 475 " + user->get_nickname() + " " + reply_arg[0] + " :Cannot join channel (+k)\r\n");
}

std::string	CREATE_ERR_BADCHANMASK(const std::vector<std::string> &reply_arg) {

    return ("476 " + reply_arg[0] + " :Bad Channel Mask\r\n");
}

std::string	CREATE_ERR_CHANOPRIVSNEEDED(const User *user, const std::vector<std::string> &reply_arg) {

    return (user->get_prefix() + " 482 " + reply_arg[0] + " :You're not channel operator\r\n");
}

std::string	CREATE_ERR_UMODEUNKNOWNFLAG(const User *user) {

    return (user->get_prefix() + " 501 :Unknown MODE flag\r\n");
}

std::string	CREATE_ERR_USERSDONTMATCH(const User *user) {

    return (user->get_prefix() + " 502 :Cant change mode for other users\r\n");
}

std::string	CREATE_ERR_INVALIDMODEPARAM(const User *user, const std::vector<std::string> &reply_arg) {

    return (
        user->get_prefix() + " 696 " + reply_arg[0] + " " + reply_arg[1] + " "
        + reply_arg[2] + " " + reply_arg[3] + "\r\n"
    );
}

std::string	CREATE_PER_NICKNAMECHANGE(const std::vector<std::string> &reply_arg) {

    return (reply_arg[0] + " NICK " + reply_arg[1] + "\r\n");
}

std::string	CREATE_PER_SENDMESSAGETOCHANNEL(const std::vector<std::string> &reply_arg) {

    return (reply_arg[0] + " " + reply_arg[1] + " " + reply_arg[2] + " :" + reply_arg[3] + "\r\n");
}
