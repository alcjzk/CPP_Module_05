#include <cstdlib>
#include <utility>
#include <cassert>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat bureaucrat_default; // <- Can be default constructed
    Bureaucrat bureaucrat_copied(bureaucrat_default); // <- Can be copy constructed

    // Since the bureaucrats name is constant, assignent operations & move construction is not
    // a valid operation. These are explicitly deleted, so uncommenting any of the lines below
    // will not compile.

    // Bureaucrat bureaucrat_moved(std::move(bureaucrat_default));
    // Bureaucrat bureaucrat_copy_assigned; bureaucrat_copy_assigned = bureaucrat_default;
    // Bureaucrat bureaucrat_move_assigned;
        // bureaucrat_move_assigned = std::move(bureaucrat_default);

    Bureaucrat bureaucrat_named("Named Bureaucrat", 50); // <- Can be constructed with values.

    // Getters
    assert(bureaucrat_named.getName() == "Named Bureaucrat");
    assert(bureaucrat_named.getGrade() == 50);

    // Stream insertion
    std::cout << bureaucrat_default;
    std::cout << bureaucrat_named;

    // Constructing a bureaucrat with too low of a grade throws the appropriate exception.
    try {
        Bureaucrat bureaucrat_too_low("Invalid bureaucrat", 151);
        assert(false);
    }
    catch (const Bureaucrat::GradeTooLowException&) {}

    // Constructing a bureaucrat with too high of a grade throws the appropriate exception.
    try {
        Bureaucrat bureaucrat_too_high("Invalid bureaucrat", 0);
        assert(false);
    }
    catch (const Bureaucrat::GradeTooHighException&) {}

    // Decrementing the bureaucrats grade too much throws the appropriate exception.
    try {
        Bureaucrat bureaucrat_low("Invalid bureaucrat", 150);
        assert(true);
        bureaucrat_low.decrementGrade();
        assert(false);
    }
    catch (const Bureaucrat::GradeTooLowException&) {}

    // Incrementing the bureaucrats grade too much throws the appropriate exception.
    try {
        Bureaucrat bureaucrat_high("Invalid bureaucrat", 1);
        assert(true);
        bureaucrat_high.incrementGrade();
        assert(false);
    }
    catch (const Bureaucrat::GradeTooHighException&) {}

    // Bureaucrat exceptions are catchable as standard exceptions.
    try   { throw Bureaucrat::GradeTooHighException(); }
    catch (const std::exception&) {}

    try   { throw Bureaucrat::GradeTooLowException(); }
    catch (const std::exception&) {}

    return EXIT_SUCCESS;
}
