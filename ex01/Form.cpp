#include "Form.hpp"

Form::Form(const std::string& name = "Unnamed Form",
           const unsigned int sign_require_grade = Bureaucrat::GRADE_LOWEST,
           const unsigned int execute_require_grade = Bureaucrat::GRADE_LOWEST)
    : _name(name), _sign_require_grade(sign_require_grade),
      _execute_require_grade(execute_require_grade)
{
    // TODO:
}
