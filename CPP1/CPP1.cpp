#include <iostream>
#include "Algorithme.hpp"
#include "IO_Handler.hpp"

void run();

int main()
{
    while (true) 
    {
        run();
    }
    std::cout << _CrtDumpMemoryLeaks() << std::endl;
}

void run() 
{
    IO_Handler io{};

    io.Write_Message("Which language would u like to program to be run in?");
    io.Write_Message("Type 1 for Dutch and 2 for English");

    int language_id = io.Read_Language_Id();
    Algorithme ag(language_id);

    io.Write_Welcome_Message(language_id);

    std::string input = io.Read_Input();    
    io.Write_Started_Message(language_id, input);

    io.Write_Message(ag.Run_Algorithme(input));
    
    io.Write_Counted_Alfabet(ag.Get_Alfabet_Counted());
}