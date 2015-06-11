#include "Pony.class.hpp"


void ponyOnTheStack(const char *color, const char *name)
{
	Pony stack;

	stack.define_it(color, name, "Stack");
	stack.speak();
	return;
}

void ponyOnTheHeap(const char *color, const char *name)
{
	Pony *heap = new Pony;

	heap->define_it(color, name, "Heap");
	heap->speak();
	delete heap;
	if (heap)
		std::cout << "Pony is still alive it's a miracle !!!" << std::endl;
}

int main(void)
{
	ponyOnTheStack("Brown", "Hari");
	ponyOnTheHeap("White", "Seldon");
	return (0);
}