#include <iostream>
#include <string>

std::string get_user_input(std::string prompt_message)
{
    std::string user_input;
    std::cout << prompt_message;
    getline(std::cin, user_input);
    return user_input;
}

int main()
{
    std::string guess;
    std::string const real_name = "Cristian";
    std::string try_again_message;
    std::string try_again_input;
    int attempts = 0;
    bool keep_playing = true;

    do
    {
        attempts++;
        guess = get_user_input("Enter the name you think I'm thinking: ");
        if (guess == real_name)
        {
            keep_playing = false;
            std::string answer_attempts = attempts == 1 ? " attempt." : " attempts.";
            std::cout << "Congratulations!! You guessed the name in " << attempts << answer_attempts << std::endl;
        }
        else
        {
            try_again_message = "Sorry, but " + guess + " is not the secret name. Would you like to try again? [y/n]: ";
            try_again_input = get_user_input(try_again_message);

            while (try_again_input != "y" && try_again_input != "Y" && try_again_input != "n" && try_again_input != "N")
            {
                try_again_input = get_user_input("Invalid answer. Would you like to try again? [y/n]: ");
            }
            if (try_again_input == "y" || try_again_input == "Y")
            {
                continue;
            }
            else if (try_again_input == "n" || try_again_input == "N")
            {
                std::cout << "Bye!" << std::endl;
                keep_playing = false;
            }
        }
    } while (keep_playing);
}