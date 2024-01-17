#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target = "Unknown Target") :
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
        "                        ,@@@@@@@,"
        "       ,,,.   ,@@@@@@/@@,  .oo8888o."
        "    ,&%%&%&&%,@@@@@/@@@@@@,8888\88/8o"
        "   ,%&\%&&%&&%,@@@\@@@/@@@88\88888/88'"
        "   %&&%&%&/%&&%@@\@@/ /@@@88888\88888'"
        "   %&&%/ %&%%&&@@\ V /@@' `88\8 `/88'"
        "   `&%\ ` /%&'    |.|        \ '|8'"
        "       |o|        | |         | |"
        "       |.|        | |         | |"
        "jgs \\/ ._\//_/__/  ,\_//__\\/.  \_//__/_";

    file_stream.close();
}
