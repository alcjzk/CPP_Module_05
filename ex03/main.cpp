#include <cstdlib>
#include <iostream>
#include <cassert>
#include "Intern.hpp"

int main()
{
    Intern intern;

    AForm* unknown_form = intern.makeForm("Unknown Form", "Unknown_Target");
    assert(unknown_form == nullptr);

    AForm* shrubbery_form = intern.makeForm("Shrubbery Creation Form", "Shrubbery_Target");
    delete shrubbery_form;

    AForm* robotomy_form = intern.makeForm("Robotomy Request Form", "Robotomy_Target");
    delete robotomy_form;

    AForm* presidential_form = intern.makeForm("Presidential Pardon Form", "Presidential_Target");
    delete presidential_form;

    return EXIT_SUCCESS;
}
