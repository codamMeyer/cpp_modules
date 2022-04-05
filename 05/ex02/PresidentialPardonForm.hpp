#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H
#include "Bureaucrat.hpp"
#include "Form.hpp"

class PresidentialPardonForm : public Form
{
public:
  PresidentialPardonForm(std::string target);
  PresidentialPardonForm(const PresidentialPardonForm& other);
  ~PresidentialPardonForm();

  PresidentialPardonForm& operator=(PresidentialPardonForm const& other);

  void execute(Bureaucrat const& executor) const;

private:
  PresidentialPardonForm();
  std::string target;
};
#endif // PRESIDENTIALPARDONFORM_H