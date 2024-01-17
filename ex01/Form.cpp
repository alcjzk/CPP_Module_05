#include "Form.hpp"

const char* Form::GradeTooHighException::what() const noexcept
{
    return "grade is too high";
}

const char* Form::GradeTooLowException::what() const noexcept
{
    return "grade is too low";
}

Form::Form(const std::string& name,
           unsigned int sign_required_grade,
           unsigned int execute_required_grade)
    : _name(name), _sign_required_grade(sign_required_grade),
      _execute_required_grade(execute_required_grade)
{
    validateGrade(sign_required_grade);
    validateGrade(execute_required_grade);
}

const std::string& Form::getName() const
{
    return _name;
}

bool Form::getIsSigned() const
{
    return _is_signed;
}

unsigned int Form::getSignRequiredGrade() const
{
    return _sign_required_grade;
}

unsigned int Form::getExecuteRequiredGrade() const
{
    return _execute_required_grade;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _sign_required_grade)
        throw GradeTooLowException();
    _is_signed = true;
}

void Form::validateGrade(unsigned int grade)
{
    if (grade < Bureaucrat::GRADE_HIGHEST)
        throw GradeTooHighException();
    if (grade > Bureaucrat::GRADE_LOWEST)
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << form.getName() << " (" << (form.getIsSigned() ? "" : "not ") << "signed)";
    os << " requires a grade of at least " << form.getSignRequiredGrade() << " to be signed,";
    os << " and a grade of at least " << form.getExecuteRequiredGrade() << " to be executed";
    return os;
}
