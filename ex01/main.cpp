#include <cstdlib>
#include <utility>
#include <cassert>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Form form_default; // <- Can be default constructed.
    Form form_copy(form_default); // <- Can be copy constructed.

    // Since the form contains constant data members, assignent operations & move construction is
    // not a valid operation. These are explicitly deleted, so uncommenting any of the lines below
    // will not compile.

    // Form form_moved(std::move(form_default));
    // Form form_copy_assigned; form_copy_assigned = form_default;
    // Form form_move_assigned;
    //     form_move_assigned = std::move(form_default);

    Form form_named("Named Form", 12, 34); // <- Can be constructed with values.

    // Getters
    assert(form_named.getName() == "Named Form");
    assert(form_named.getSignRequiredGrade() == 12);
    assert(form_named.getExecuteRequiredGrade() == 34);
    assert(form_named.getIsSigned() == false);

    // Stream insertion
    std::cout << form_default << '\n';
    std::cout << form_named << '\n';

    // Constructing a form with a grade out of bounds throws the appropriate exception.
    try {
        Form invalid_form("Invalid Form", 0, 1);
        assert(false);
    }
    catch (const Form::GradeTooHighException&) {}

    try {
        Form invalid_form("Invalid Form", 1, 0);
        assert(false);
    }
    catch (const Form::GradeTooHighException&) {}

    try {
        Form invalid_form("Invalid Form", 151, 1);
        assert(false);
    }
    catch (const Form::GradeTooLowException&) {}

    try {
        Form invalid_form("Invalid Form", 1, 151);
        assert(false);
    }
    catch (const Form::GradeTooLowException&) {}

    Bureaucrat low_grade_bureaucrat("Low Grade Bureaucrat", 150);
    Bureaucrat high_grade_bureaucrat("High Grade Bureaucrat", 1);

    // Sign via Form::beSigned
    {
        Form high_grade_form("High Grade Form", 1, 1);

        // A bureaucrat with too low of a grade cannot sign the form
        try {
            high_grade_form.beSigned(low_grade_bureaucrat);
            assert(false);
        }
        catch (const Form::GradeTooLowException&) {}
        assert(high_grade_form.getIsSigned() == false);

        // A bureaucrat with a high enough grade can sign the form
        high_grade_form.beSigned(high_grade_bureaucrat);
        assert(high_grade_form.getIsSigned() == true);
    }

    // Sign via Bureaucrat::signForm
    {
        Form high_grade_form("High Grade Form", 1, 1);

        // A bureaucrat with too low of a grade cannot sign the form
        low_grade_bureaucrat.signForm(high_grade_form);
        assert(high_grade_form.getIsSigned() == false);

        // A bureaucrat with a high enough grade can sign the form
        high_grade_bureaucrat.signForm(high_grade_form);
        assert(high_grade_form.getIsSigned() == true);
    }

    return EXIT_SUCCESS;
}
