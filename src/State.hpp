/**
 * @file State.hpp
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

#ifndef STATE_HPP_9F6091FF276D42BA8446B45454883361
#define STATE_HPP_9F6091FF276D42BA8446B45454883361

#include <functional>
#include <vector>

#include "Transition.hpp"

namespace StateTrans
{
    using Operation = std::function<void()>;

    class State
    {
        public:
            State();
            State(std::string, Operation, std::vector<Transition>);
            ~State();

            void UpdateState();

            Operation GetOperation() const;
            void SetOperation(const Operation&);

            std::string GetName() const;
            void SetName(const std::string&);

            void AddTransition(const Transition&);

        private:
            std::string name;
            Operation operation;
            std::vector<Transition> transitions;
    };
} // end namespace

#endif
