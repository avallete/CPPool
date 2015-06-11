#include "ZombieEvent.hpp"

int main(void)
{
	ZombieEvent Events;

	for (int i = 0; i < 42; i++)
		Events.randomChump();
	return (0);
}