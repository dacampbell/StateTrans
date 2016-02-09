# Created by Duncan Campbell

# Add in the StateTrans library
add_library(StateTrans Action.c
                       Machine.c
                       State.c
                       Transition.c
                      )

target_include_directories(StateTrans PUBLIC ${PROJEcT_SOURCE_DIR})
