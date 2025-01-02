#include "Server.hpp"
#include "utils.hpp"

static bool __is_running__ = true;

static inline void	singleton_ctrl_c(int sig) {
    (void)sig;
    __is_running__ = false;
}

int main(int ac, char **av) {

    const char *port = av[1];
    const char *pass = av[2];
    
    if (ac == 3) {
        
        try {
            signal(SIGINT, singleton_ctrl_c);
            Server serv(port, pass);
            serv.server_initialisation();

            logger(INFO, "Listening ...");
            while (__is_running__)
                serv.run();
            
        } catch(std::exception &err) {
            std::cerr
                << err.what()
                << std::endl;

            return (EXIT_FAILURE);
        }

        return (EXIT_SUCCESS);
    }

    std::cerr
        << "`error`: usage: ./ircserv [port] [password]"
        << std::endl;

    return (EXIT_FAILURE);
}
