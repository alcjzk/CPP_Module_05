#include "AForm.hpp"

const char* AForm::GradeTooHighException::what() const noexcept
{
    return "grade is too high";
}

const char* AForm::GradeTooLowException::what() const noexcept
{
    return "grade is too low";
}

AForm::AForm(const std::string& name,
           unsigned int sign_required_grade,
           unsigned int execute_required_grade)
    : _name(name), _sign_required_grade(sign_required_grade),
      _execute_required_grade(execute_required_grade)
{
    validateGrade(sign_required_grade);
    validateGrade(execute_required_grade);
}

const std::string& AForm::getName() const
{
    return _name;
}

bool AForm::getIsSigned() const
{
    return _is_signed;
}

unsigned int AForm::getSignRequiredGrade() const
{
    return _sign_required_grade;
}

unsigned int AForm::getExecuteRequiredGrade() const
{
    return _execute_required_grade;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _sign_required_grade)
        throw GradeTooLowException();
    _is_signed = true;
}

void AForm::validateGrade(unsigned int grade)
{
    if (grade < Bureaucrat::GRADE_HIGHEST)
        throw GradeTooHighException();
    if (grade > Bureaucrat::GRADE_LOWEST)
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
    os << form.getName() << " (" << (form.getIsSigned() ? "" : "not ") << "signed)";
    os << " requires a grade of at least " << form.getSignRequiredGrade() << " to be signed,";
    os << " and a grade of at least " << form.getExecuteRequiredGrade() << " to be executed";
    return os;
}
