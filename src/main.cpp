
#include <iostream>
#include "saunabot.hpp"
#include "utils/logger.hpp"

int main()
{
    try 
    {
        saunabot::Run();
    } 
    catch(const std::exception& e)
    {
        std::cout << "Something went wrong: " << e.what() << "\n";
        return -1;
    }
    catch(...)
    {
        std::cout << "Something went very wrong" << "\n";
    }

    return 0;
}
