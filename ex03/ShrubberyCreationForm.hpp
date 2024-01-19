#pragma once

#include <string>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    public:
        virtual ~ShrubberyCreationForm() override = default;
        ShrubberyCreationForm(const std::string& target = "Unknown Target");
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm(ShrubberyCreationForm&&) = delete;

        ShrubberyCreationForm& operator=(const ShrubberyCreationForm&) = delete;
        ShrubberyCreationForm& operator=(ShrubberyCreationForm&&) = delete;

        virtual void execute(const Bureaucrat& executor) const override;

    private:
        std::string _target;
};
