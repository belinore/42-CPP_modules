#include "Harl.hpp"

    void Harl::debug( void )
    {
        std::cout << "DEBUG MESSAGE\n";
    }

    void Harl::info( void )
    {
        std::cout << "INFO MESSAGE\n";
    }

    void Harl::warning( void )
    {
        std::cout << "WARNING MESSAGE\n";
    }

    void Harl::error( void )
    {
        std::cout << "ERROR MESSAGE\n";
    }

    void Harl::complain( std::string level )
    {
        std::string levels[4] = {"debug", "info", "warning", "error"};
        void (Harl::*respond[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
        int i = 0;
        while (i < 4)
        {
            if (level == levels[i])
                (this->*respond[i])();
            i++;
        }
    }

/* "DEBUG" level: Debug messages contain contextual information. They are mostly
used for problem diagnosis.
Example: "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup
burger. I really do!"
• "INFO" level: These messages contain extensive information. They are helpful for
tracing program execution in a production environment.
Example: "I cannot believe adding extra bacon costs more money. You didn’t put
enough bacon in my burger! If you did, I wouldn’t be asking for more!"
• "WARNING" level: Warning messages indicate a potential issue in the system.
However, it can be handled or ignored.
Example: "I think I deserve to have some extra bacon for free. I’ve been coming for
years, whereas you started working here just last month."
• "ERROR" level: These messages indicate that an unrecoverable error has occurred.
This is usually a critical issue that requires manual intervention.
Example: "This is unacceptable! I want to speak to the manager now." */