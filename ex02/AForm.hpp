#pragma once

#include <string>
#include <exception>
#include <ostream>
#include "Bureaucrat.hpp"

class AForm
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

        virtual ~AForm() = default;
        AForm(AForm&&) = delete;

        AForm& operator=(const AForm&) = delete;
        AForm& operator=(AForm&&) = delete;

        const std::string&  getName() const;
        bool                getIsSigned() const;
        unsigned int        getSignRequiredGrade() const;
        unsigned int        getExecuteRequiredGrade() const;

        void                beSigned(const Bureaucrat& bureaucrat);
        virtual void        execute(const Bureaucrat& executor) const = 0;

    protected:
        AForm(const std::string& name = "Unnamed Form",
             unsigned int sign_require_grade = Bureaucrat::GRADE_LOWEST,
             unsigned int execute_require_grade = Bureaucrat::GRADE_LOWEST);
        AForm(const AForm&) = default;

        static void         validateGrade(unsigned int grade);

    private:
        const std::string   _name;
        bool                _is_signed = false;
        const unsigned int  _sign_required_grade;
        const unsigned int  _execute_required_grade;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);
