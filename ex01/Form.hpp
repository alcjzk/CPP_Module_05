#pragma once

#include <string>
#include "Bureaucrat.hpp"

class Form
{
    public:
        ~Form() = default;
        Form(const std::string& name = "Unnamed Form",
             const unsigned int sign_require_grade = Bureaucrat::GRADE_LOWEST,
             const unsigned int execute_require_grade = Bureaucrat::GRADE_LOWEST);
        Form(const Form&) = default;
        Form(Form&&) = delete;

        Form& operator=(const Form&) = delete;
        Form& operator=(Form&&) = delete;

        const std::string&  getName() const;
        bool                getIsSigned() const;
        const unsigned int  getSignRequiredGrade() const;
        const unsigned int  getExecuteRequiredGrade() const;

    private:
        const std::string   _name;
        bool                _is_signed = false;
        const unsigned int  _sign_required_grade;
        const unsigned int  _execute_required_grade;
};
