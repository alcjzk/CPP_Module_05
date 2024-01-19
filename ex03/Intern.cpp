#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

AForm* Intern::makeForm(const std::string& form_name, const std::string& target) const
{
    AForm*  form;

    for (const Entry& entry : map)
    {
        if (entry.name == form_name)
        {
            form = entry.createForm(target);
            std::cout << "Intern creates " << form << '\n';
            return form;
        }
    }
    std::cout << "Intern could not create the form. No form named '" << form_name << "' exists.\n";
    return nullptr;
}

AForm* Intern::createShrubberyCreationForm(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string& target)
{
    return new PresidentialPardonForm(target);
}
