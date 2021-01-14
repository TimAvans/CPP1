#include "Algorithme.hpp"


Algorithme::Algorithme(int language_id)
{
    this->language_id = language_id;
    for (size_t i = 0; i < 200; i++)
    {
        written_numbers[i] = db->Select_Number(i, language_id);
    }
}

std::string Algorithme::Run_Algorithme(const std::string& start_sentence)
{
    bool end_is_found = false;

    Set_Alfabet_Random();
    std::string the_seed = Build_String(start_sentence);    
    int iteration = 0, complete_iterations = 0;

    while (!end_is_found) 
    {
        Set_Alfabet_Nul();

        for (auto& c : the_seed)
        {
            auto character = tolower(c);
            if (isalpha(character))
            {
                alfabet[character]++;
            }
        }

        if (prev_alfabet == alfabet)
        {
            end_is_found = true;
            return the_seed;
        }

        prev_alfabet = alfabet;

        if (iteration == 10)
        {
            Set_Alfabet_Random(true);

            iteration = 0;
        }

        the_seed = Build_String(start_sentence);

        if (complete_iterations % 100000 == 0)
        {
            std::cout << complete_iterations << std::endl;
        }

        if (complete_iterations == 10000000)
        {
            return (language_id == 1) ? "Geen autopangram gevonden, de laatste poging was: " + the_seed : "No autopangram has been found, the result of the last try was: " + the_seed;
        }

        iteration++;
        complete_iterations++;
    }
    return the_seed;
}

void Algorithme::Set_Alfabet_Random(bool reset)
{
    std::random_device rd;
    std::default_random_engine engine(rd());
    std::uniform_int_distribution<> dist(1, 50);

    for (char c : alfabet_string)
    {
        if (isalpha(tolower(c)) && alfabet.find(tolower(c)) == alfabet.end() && !reset )
        {
            alfabet.insert(std::pair<char, int>(tolower(c), dist(engine)));
        }
        if (isalpha(tolower(c)) && reset)
        {
            alfabet[tolower(c)] = dist(engine);
        }
    }
}

void Algorithme::Set_Alfabet_Nul()
{
    for (auto iter = alfabet.begin(); iter != alfabet.end(); ++iter)
    {
        iter->second = 0;
    }
}

std::map<char, int> Algorithme::Get_Alfabet_Counted()
{
    return alfabet;
}


std::string Algorithme::Build_String(const std::string& start_sentence)
{
    std::string start = start_sentence + " ";

    for (auto iter = alfabet.begin(); iter != alfabet.end(); ++iter) {

        std::string temp;

        if (iter->second == 1)
        {
            temp = written_numbers[iter->second] + " " + iter->first;
        }
        else 
        {
            temp = written_numbers[iter->second] + " " + iter->first + "'s";
        }      
        
        if (std::next(iter) != alfabet.end()) {
            if (std::next(iter)->first != 'z')
            {
                temp += ", ";
            }
            else
            {
                (language_id == 1) ? temp += " en " : temp += " and ";
            }
        }
        start += temp;
    }
    return start; 
}