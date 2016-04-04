# Add in the unit tests
add_executable(transition_test transition_test.cpp)
add_executable(state_test state_test.cpp)
add_executable(machine_test machine_test.cpp)

# Standard linking to gtest stuff.
target_link_libraries(transition_test gtest gtest_main)
target_link_libraries(state_test gtest gtest_main)
target_link_libraries(machine_test gtest gtest_main)

# Extra linking for the project.
target_link_libraries(transition_test StateTrans)
target_link_libraries(state_test StateTrans)
target_link_libraries(machine_test StateTrans)

# This is so you can do 'make test' to see all your tests run, instead of
# manually running the executable runUnitTests to see those specific tests.
add_test(TransitionTest transition_test)
add_test(StateTest state_test)
add_test(MachineTest machine_test)
