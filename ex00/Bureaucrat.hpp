#pragma once

class Bureaucrat
{
    public:
        ~Bureaucrat();
        Bureaucrat();
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat(Bureaucrat&& other);

        Bureaucrat& operator=(const Bureaucrat& other);
        Bureaucrat& operator=(Bureaucrat&& other);
};
