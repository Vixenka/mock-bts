set(MBTS_SOURCES
    "main.cpp"
    "network/bts.cpp"
    "network/bts_inner.cpp"
    "network/manager.cpp"
    "network/receiver.cpp"
    "logger/log.cpp"
)

add_executable(MockBTS ${MBTS_SOURCES})
