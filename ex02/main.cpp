#include <cstdlib>
#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    Bureaucrat bureaucrat_high("High Grade Bureaucrat", 1);
    Bureaucrat bureaucrat_low("Low Grade Bureaucrat", 150);

    ShrubberyCreationForm shrubbery("Shrubbery_Target");
    bureaucrat_high.executeForm(shrubbery);
    bureaucrat_high.signForm(shrubbery);
    bureaucrat_low.executeForm(shrubbery);
    bureaucrat_high.executeForm(shrubbery);

    std::cout << '\n';

    RobotomyRequestForm robotomy("Robotomy_Target");
    bureaucrat_high.executeForm(robotomy);
    bureaucrat_high.signForm(robotomy);
    bureaucrat_low.executeForm(robotomy);
    bureaucrat_high.executeForm(robotomy);
    bureaucrat_high.executeForm(robotomy);

    std::cout << '\n';

    PresidentialPardonForm presidential("Presidential_Target");
    bureaucrat_high.executeForm(presidential);
    bureaucrat_high.signForm(presidential);
    bureaucrat_low.executeForm(presidential);
    bureaucrat_high.executeForm(presidential);

    return EXIT_SUCCESS;
}
