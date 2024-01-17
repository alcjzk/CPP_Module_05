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
    // TODO:
}
