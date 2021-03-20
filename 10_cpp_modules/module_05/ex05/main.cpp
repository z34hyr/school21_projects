
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"
#include "CentralBureaucracy.hpp"

int main(void)
{
	std::string names[] = {"Boris", "Jack", "Nikolai",
						"Semen", "Gleb", "Sergey",
						"Chuck", "Katya", "Lena",
						"Oleg", "Vasya", "Igor",
						"Portfelii", "Karina", "Vasilisa",
						"Adam", "Eva", "Gupta"};

	CentralBureaucracy central;
	central.showBureauInfo(0);

	Bureaucrat* signing_stack[21];
	Bureaucrat* executing_stack[21];
	std::string queue[100];
	for (int i = 0; i < 21; i++)
	{
		signing_stack[i] = new Bureaucrat(names[std::rand() % 15], std::rand() % 30 + 1);
		executing_stack[i] = new Bureaucrat(names[std::rand() % 15], std::rand() % 10 + 1);
		central.feedBureacurat(signing_stack[i]);
		central.feedBureacurat(executing_stack[i]);
	}
	central.fireExecBureaucrat(10);
	central.feedBureacurat(executing_stack[20]);
	central.showBureauInfo(0);
	for (int i = 0; i < 100; i++)
	{
		queue[i] = names[std::rand() % 18];
		central.queueUp(queue[i]);
	}
	std::cout << "queue length: " << central.queue_length() << std::endl;
	central.doBureaucracy();
	std::cout << "queue length: " << central.queue_length() << std::endl;
}
