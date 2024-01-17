#pragma once

#include <string>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    public:
        virtual ~PresidentialPardonForm() override = default;
        PresidentialPardonForm(const std::string& target);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm(PresidentialPardonForm&&) = delete;

        PresidentialPardonForm& operator=(const PresidentialPardonForm&) = delete;
        PresidentialPardonForm& operator=(PresidentialPardonForm&&) = delete;

        virtual void execute(const Bureaucrat& executor) const override;

    private:
        std::string _target;
};
