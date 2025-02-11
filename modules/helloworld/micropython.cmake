# Create an INTERFACE library for our C module.
add_library(helloWorld INTERFACE)

# Add our source files to the lib
target_sources(helloWorld INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/helloWorld.c
)

# Add the current directory as an include directory.
target_include_directories(helloWorld INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}
)

# Link our INTERFACE library to the usermod target.
target_link_libraries(usermod INTERFACE helloWorld)
