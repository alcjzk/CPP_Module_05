#pragma once

#include <string>
#include <exception>
#include <ostream>
#include "Bureaucrat.hpp"

class Form
{
    public:
        class GradeTooHighException : public std::exception
        {
            virtual const char* what() const noexcept override;
        };
        class GradeTooLowException : public std::exception
        {
            virtual const char* what() const noexcept override;
        };

        ~Form() = default;
        Form(const std::string& name = "Unnamed Form",
             unsigned int sign_require_grade = Bureaucrat::GRADE_LOWEST,
             unsigned int execute_require_grade = Bureaucrat::GRADE_LOWEST);
        Form(const Form&) = default;
        Form(Form&&) = delete;

        Form& operator=(const Form&) = delete;
        Form& operator=(Form&&) = delete;

        const std::string&  getName() const;
        bool                getIsSigned() const;
        unsigned int        getSignRequiredGrade() const;
        unsigned int        getExecuteRequiredGrade() const;

        void                beSigned(const Bureaucrat& bureaucrat);

    private:
        const std::string   _name;
        bool                _is_signed = false;
        const unsigned int  _sign_required_grade;
        const unsigned int  _execute_required_grade;

        static void         validateGrade(unsigned int grade);
};

std::ostream& operator<<(std::ostream& os, const Form& form);
