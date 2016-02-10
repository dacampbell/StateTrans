# Created by Duncan Campbell

# Add in the StateTrans library
add_library(StateTrans Machine.cpp
                       State.cpp
                       Transition.cpp
                      )

target_include_directories(StateTrans PUBLIC ${PROJEcT_SOURCE_DIR})
