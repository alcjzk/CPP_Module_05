#pragma once

#include <string>
#include "AForm.hpp"

class Intern
{
    public:
        ~Intern() = default;
        Intern() noexcept = default;
        Intern(const Intern&) noexcept = default;
        Intern(Intern&&) noexcept = default;

        Intern& operator=(const Intern&) noexcept = default;
        Intern& operator=(Intern&&) noexcept = default;

        AForm*  makeForm(const std::string& form_name, const std::string& target) const;

    private:
        typedef AForm* (*createForm)(const std::string& target);
        typedef struct Entry
        {
            const char* name;
            createForm  createForm;
        } Entry;

        static AForm* createShrubberyCreationForm(const std::string& target);
        static AForm* createRobotomyRequestForm(const std::string& target);
        static AForm* createPresidentialPardonForm(const std::string& target);

        static constexpr Entry map[] = {
            {"Shrubbery Creation Form", &Intern::createShrubberyCreationForm},
            {"Robotomy Request Form", &Intern::createRobotomyRequestForm},
            {"Presidential Pardon Form", &Intern::createPresidentialPardonForm},
        };
};
