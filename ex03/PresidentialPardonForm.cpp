#include <iostream>
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("Presidential Pardon Form", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other), _target(other._target)
{
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
    validateExecution(executor);
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox\n";
}
