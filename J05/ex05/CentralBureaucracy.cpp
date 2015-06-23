#include "CentralBureaucracy.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"

CentralBureaucracy::CentralBureaucracy(void): b_index(0)
{
	srand(time(NULL));
	m_target = new Queue("first");
	m_target->data = "first";
	m_target->next = NULL;
	for (int i = 0; i < 20; i++)
		m_list[i] = NULL;
	return;
}

CentralBureaucracy::CentralBureaucracy(CentralBureaucracy const & src)
{
	*this = src;
	return;
}

CentralBureaucracy::~CentralBureaucracy(void)
{
	for (int i = 0; i < b_index; i++)
	{
		delete	m_list[i];
		m_list[i] = NULL;
	}
	return;
}

void	CentralBureaucracy::feedBureaucrat(void)
{
	const std::string pool[10] = {
		"adur", "aes", "anim", "apoll", "imac",
		"educ", "equis", "extr", "guius", "hann"
	};
	if (b_index < 20)
	{
		m_list[b_index] = new Bureaucrat(pool[rand() % 10], (rand() % 72) + 1);
		b_index++;
	}
	else
		std::cout << "All slots are empty, request rejected" << std::endl;
	return;
}


void CentralBureaucracy::feedAllBureaucrat(void)
{
	for (int i = b_index; i < 20; i++)
		feedBureaucrat();
}

void CentralBureaucracy::queueUp(std::string name)
{
	Queue* tmp;

	tmp = m_target;
	while (tmp->next)
		tmp = tmp->next;
	tmp->addQueue(name);
	return;
}

void	CentralBureaucracy::doBureaucracy(void)
{
	Queue *tmp;
	OfficeBlock block;
	Intern 		someintern;
	std::string form[4] = {"robotomy request", "pardon request", "robotomy request"};
	tmp = m_target->next;
	while (tmp)
	{
		try
		{
			try{
			block.setIntern(someintern);}
			catch (std::exception &e){std::cout << "Intern set error: " << e.what() << std::endl;}
			try{
			block.setSigner(*m_list[rand() % b_index]);}
			catch (std::exception &e){std::cout << "Signer set error: " << e.what() << std::endl;}
			try{
			block.setExecutor(*m_list[rand() % b_index]);}
			catch (std::exception &e){std::cout << "Executor set error: " << e.what() << std::endl;}
			try{
			block.doBureaucracy(form[rand() % 2], tmp->data);}
			catch (std::exception &e){std::cout << "Bureaucracy  error: " << e.what() << std::endl;}
		}
		catch (std::exception &e)
		{
			std::cout << "Error std :" << e.what() << std::endl;
		}
		tmp = tmp->next;
	}
}

CentralBureaucracy& CentralBureaucracy::operator=(CentralBureaucracy const & rhs)
{
	m_target = rhs.m_target;
	for (int i = 0; i < 20; i++)
		m_list[i] = rhs.m_list[i];
	return (*this);
}

/* Chained list imbricated Class */

CentralBureaucracy::Queue::Queue(void): next(NULL)
{
	return;
}

CentralBureaucracy::Queue::Queue(std::string first): data(first), next(NULL)
{
	return;
}

CentralBureaucracy::Queue::Queue(Queue const & src)
{
	*this = src;
	return;
}

CentralBureaucracy::Queue::~Queue(void)
{
	return;
}

void	CentralBureaucracy::Queue::addQueue(std::string elem)
{
	next = new Queue(elem);
}

void CentralBureaucracy::Queue::printIt(void)
{
	Queue* tmp;

	tmp = this;
	while (tmp->next)
	{
		std::cout << tmp->data << std::endl;
		tmp = tmp->next;
	}
	std::cout << tmp->data << std::endl;
}

CentralBureaucracy::Queue& CentralBureaucracy::Queue::operator=(Queue const & rhs)
{
	data = rhs.data;
	next = rhs.next;
	return (*this);
}