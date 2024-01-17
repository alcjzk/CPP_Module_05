#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
    return "Grade is too low!";
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const std::string& name, unsigned int grade) : _name(name), _grade(grade)
{
    validateGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
}

void Bureaucrat::incrementGrade()
{
    validateGrade(_grade - 1);
    _grade--;
}

void Bureaucrat::decrementGrade()
{
    validateGrade(_grade + 1);
    _grade++;
}

unsigned int Bureaucrat::getGrade() const
{
    return _grade;
}

const std::string& Bureaucrat::getName() const
{
    return _name;
}

void Bureaucrat::validateGrade(unsigned int grade)
{
    if (grade > GRADE_LOWEST)
        throw GradeTooLowException();
    if (grade < GRADE_HIGHEST)
        throw GradeTooHighException();
}
