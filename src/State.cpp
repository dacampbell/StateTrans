/**
 * @file State.cpp
 * @author Duncan Campbell
 * @version 1.0
 *
 * @section LICENSE
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2016 Duncan Campbell
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * @section DESCRIPTION
 *
 * This class represents a state within a finite state machine.  It is composed
 * of an operation to be performed and a set of triggers that will enable the
 * next state.  Each state is designed to be contained within a finite state
 * machine.
 */

#include "State.hpp"

using namespace StateTrans;

State::State(std::string name, Operation operation, std::vector<Transition> transitions) :
    name(name),
    operation(operation),
    transitions(transitions)
{

}

State::~State()
{

}

void State::UpdateState()
{
    this->operation();

    for(auto& transition : transitions)
    {
        if(transition.CheckTrigger())
        {
            transition.ExecuteAction();
            break;
        }
    }
}

Operation State::GetOperation() const
{
    return this->operation;
}

void State::SetOperation(const Operation& operation)
{
    this->operation = operation;
}

std::string State::GetName() const
{
    return this->name;
}

void State::SetName(const std::string& name)
{
    this->name = name;
}

void State::AddTransition(const Transition& transition)
{
    this->transitions.push_back(transition);
}
