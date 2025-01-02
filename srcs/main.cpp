#include "Server.hpp"
#include "utils.hpp"

static bool is_running = true;

static void	ctrl_c_sig(int sig) {
    (void)sig;
    is_running = false;
}

int main(int ac, char **av) {
    const char *port = av[1];
    const char *pass = av[2];
    
    if (ac == 3) {
        
        try 
        {
            signal(SIGINT, ctrl_c_sig);
            Server serv(port, pass);
            serv.init();
            logger(INFO, "Server is listening ...");
            while (is_running)
                serv.run();
        } 
        catch (std::exception &err)
        {
            std::cerr << err.what() << std::endl;
            return (EXIT_FAILURE);
        }
        return (EXIT_SUCCESS);
    }
    std::cerr << "`error`: usage: ./ircserv [port] [password]" << std::endl;
    return (EXIT_FAILURE);
}
