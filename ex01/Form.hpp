#pragma once

class Form
{
    public:
        ~Form() = default;
        Form() = default;
        Form(const Form&) = default;
        Form(Form&&) = default;

        Form& operator=(const Form&) = default;
        Form& operator=(Form&&) = default;
};
