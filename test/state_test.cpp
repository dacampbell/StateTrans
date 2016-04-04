#include <iostream>
#include "gtest/gtest.h"

#include "Transition.hpp"

TEST(TransitionTest, TransitionContruction)
{
	using namespace StateTrans;

    std::function<bool()> trigger = [] () -> bool
        {
            return true;
        };

    std::function<void()> action = [] () -> void
        {

        };

    Transition transition1 = Transition();
    Transition transition2 = Transition(trigger, action);
}
