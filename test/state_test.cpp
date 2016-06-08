#include <iostream>
#include "gtest/gtest.h"

#include "Transition.hpp"

TEST(StateTest, StateConstruction)
{
	using namespace StateTrans;

    std::function<bool()> trigger = [] () -> bool
        {
            return true;
        };

    std::function<void()> action = [] () -> void
        {

        };

	std::function<void()> operation = [] () -> void
		{

		};

    Transition transition1 = Transition();
    Transition transition2 = Transition(trigger, action);

	std::vector<Transition> transitions;
	transitions.push_back(transition1);
	transitions.push_back(transition1);
	transitions.push_back(transition1);

	State state1 = State();
	State state2 = State("Test State", operation, transitions);
}
