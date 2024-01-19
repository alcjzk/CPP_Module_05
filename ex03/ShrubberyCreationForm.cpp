#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :
    AForm("Shrubbery Creation Form", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
    AForm(other), _target(other._target)
{
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    validateExecution(executor);
    std::fstream file_stream(_target + "_shrubbery", std::fstream::out);

    file_stream <<
        "                        ,@@@@@@@,\n"
        "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
        "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
        "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
        "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
        "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
        "   `&%\\ ` /%&'    |.|        \\ '|8'\n"
        "       |o|        | |         | |\n"
        "       |.|        | |         | |\n"
        "jgs \\\\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n";

    file_stream.close();
}
