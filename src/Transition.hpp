/**
 * @file Transition.hpp
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
 * This class represents a transition from one state to another state.  A
 * transition is composed of a trigger and an action.  A trigger represents the
 * condition under which the trigger will activate.  An action will represent
 * the measures that are taken to transition over to the next state.
 */

#ifndef TRANSITION_HPP_66C3A6E53EF44E6EBDDAD71B3252D6A6
#define TRANSITION_HPP_66C3A6E53EF44E6EBDDAD71B3252D6A6

#include <functional>

namespace StateTrans
{
    using Trigger = std::function<bool()>;
    using Action  = std::function<void()>;

    class Transition
    {
        public:
            /**
              * Constructor for Transitions that takes no arguments
              */
            Transition();

            /**
             * Constructor for Transitions that takes a Trigger and an Action
             *
             * @param trigger Trigger for the transition
             *
             * @param action Action for the transition
             */
            Transition(Trigger, Action);

            /**
             * Destructor for Transitions
             */
            ~Transition();

            /**
             * Checks the current state of the trigger for the Transition
             *
             * @return State of the Trigger
             */
            bool CheckTrigger();

            /**
             * Executes the action of the Transition
             */
            void ExecuteAction();

            /**
             * Get the Trigger for the Transition
             *
             * @return Trigger of the Transition
             */
            Trigger GetTrigger() const;

            /**
             * Set the Trigger for the Transition
             *
             * @param trigger Trigger to be set
             */
            void SetTrigger(const Trigger&);

            /**
             * Get the Action for the Transition
             *
             * @return Action of the Transition
             */
            Action GetAction() const;

            /**
             * Set the Action for the Transition
             *
             * @param action Action to be set
             */
            void SetAction(const Action&);

        private:
            Trigger trigger;
            Action  action;
    };

} // end namespace

#endif
