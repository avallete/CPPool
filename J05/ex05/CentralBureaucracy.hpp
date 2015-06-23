#ifndef CENTRAL_BUREAUCRACY_HPP
#define CENTRAL_BUREAUCRACY_HPP
#include <iostream>
class Bureaucrat;
class CentralBureaucracy
{
	public:
		CentralBureaucracy(void);
		CentralBureaucracy(CentralBureaucracy const & src);
		~CentralBureaucracy(void);
		void feedBureaucrat(void);
		void feedAllBureaucrat(void);
		void queueUp(std::string name);
		void doBureaucracy(void);

		CentralBureaucracy& operator=(CentralBureaucracy const & rhs);
	protected:
		class Queue
		{
			public:
				Queue(void);
				Queue(std::string first);
				Queue(Queue const & src);
				~Queue(void);
				void	addQueue(std::string elem);
				void	printIt(void);
		
				Queue& operator=(Queue const & rhs);
				std::string data;
				Queue		*next;
		};
		Queue *m_target;
		Bureaucrat* m_list[20];
		int b_index;
};
#endif