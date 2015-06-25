#ifndef OPERATION_HPP
#define OPERATION_HPP

class Operation
{
	public:
		Operation(char c);
		~Operation(void);
	private:
		Operation& operator=(Operation const & rhs);
		Operation(void);	
		Operation(Operation const & src);
};
#endif