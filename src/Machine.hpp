/**
 * @file Machine.hpp
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
 * This class represents a finite state machine.  It is responsible for managing
 * the machine and controlling the transition between states.
 */

#ifndef MACHINE_HPP_65083FA30B194E769ACA5E560D9E200B
#define MACHINE_HPP_65083FA30B194E769ACA5E560D9E200B

#include <string>
#include <map>

#include "State.hpp"

namespace StateTrans
{
    class Machine
    {
        public:
            /**
             * Constructor for Machine that takes no arguments
             */
            Machine();

            /**
             * Constructor for Machine that takes a mapping of name to state as
             * well as a name for the machine
             *
             * @param states Mapping of names to states for the machine
             *
             * @param name Name for the machine
             */
            Machine(std::map<std::string, State>, std::string);

            /**
             * Destructor for machine
             */
            ~Machine();

            /**
             * Runs the update function on the current state that the machine is
             * running.
             */
            void UpdateMachine();

            /**
             * Adds a state to the current list of states the machine manages.
             *
             * @param state The state to add to the machine
             */
            void AddState(const State& state);

            /**
             * Sets the current state of the state machine
             *
             * @param state The name of the state to set the machine to
             */
            void SetState(const std::string&);

            /**
             * Gets the current stat of the state machine
             *
             * @return Current state of the state machine
             */
            std::string GetState() const;

            /**
             * Get the name of the machine
             *
             * @return The name of the machine
             */
            std::string GetName() const;

            /**
             * Set the name if the machine
             +
             * @param name Name to set the machine to
             */
            void SetName(const std::string&);

        private:
            std::string name;
            std::string currentState;
            std::map<std::string, State> states;
    };
}

#endif
