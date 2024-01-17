#pragma once

#include <exception>
#include <string>
#include <ostream>

class Bureaucrat
{
    public:
        static const unsigned int GRADE_HIGHEST = 1;
        static const unsigned int GRADE_LOWEST = 150;

        class GradeTooHighException : public std::exception
        {
            virtual const char* what() const noexcept override;
        };

        class GradeTooLowException : public std::exception
        {
            virtual const char* what() const noexcept override;
        };

        ~Bureaucrat();
        Bureaucrat(const std::string& name = "Unnamed Bureaucrat", unsigned int grade = GRADE_LOWEST);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat(Bureaucrat&&) = delete;

        void incrementGrade();
        void decrementGrade();

        unsigned int        getGrade() const;
        const std::string&  getName() const;

        Bureaucrat& operator=(const Bureaucrat&) = delete;
        Bureaucrat& operator=(Bureaucrat&&) = delete;

    private:
        const std::string   _name;
        unsigned int        _grade;

        static void         validateGrade(unsigned int grade);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
