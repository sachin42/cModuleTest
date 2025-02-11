# Create an INTERFACE library for our C module.
add_library(cJson INTERFACE)

# Add our source files to the lib
target_sources(cJson INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/CJson.c
)

# Add the current directory as an include directory.
target_include_directories(cJson INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}
)

# Link our INTERFACE library to the usermod target.
target_link_libraries(usermod INTERFACE cJson)
