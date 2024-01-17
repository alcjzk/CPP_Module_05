#pragma once

#include <string>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    public:
        virtual ~RobotomyRequestForm() override = default;
        RobotomyRequestForm(const std::string& target = "Unknown Target");
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm(RobotomyRequestForm&&) = delete;

        RobotomyRequestForm& operator=(const RobotomyRequestForm&) = delete;
        RobotomyRequestForm& operator=(RobotomyRequestForm&&) = delete;

        virtual void execute(const Bureaucrat& executor) const override;

    private:
        std::string _target;
};
