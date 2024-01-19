#include <iostream>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("Robotomy Request Form", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), _target(other._target)
{
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    static bool will_exec = false;
    validateExecution(executor);

    if (will_exec)
    {
        std::cout << _target << " has been robotomized successfully\n";
        will_exec = false;
    }
    else
    {
        std::cout << "robotomy failed\n";
        will_exec = true;
    }
}

