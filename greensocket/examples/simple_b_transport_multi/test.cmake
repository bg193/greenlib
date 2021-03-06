# Read executable output
file(READ "executable_output.txt" EXECUTABLE_OUTPUT_CONTENT)

# Find and replace S0 ID
string(REGEX REPLACE ".*S0 using tag ([0-9]+) for my socket.*" "\\1"
       ID0 ${EXECUTABLE_OUTPUT_CONTENT})
string(REGEX REPLACE ${ID0} "{ID0}" EXECUTABLE_OUTPUT_CONTENT
       ${EXECUTABLE_OUTPUT_CONTENT})

# Find and replace S1 ID
string(REGEX REPLACE ".*S1 using tag ([0-9]+) for my socket.*" "\\1"
       ID1 ${EXECUTABLE_OUTPUT_CONTENT})
string(REGEX REPLACE ${ID1} "{ID1}" EXECUTABLE_OUTPUT_CONTENT
      ${EXECUTABLE_OUTPUT_CONTENT})

file(WRITE executable_output.template "${EXECUTABLE_OUTPUT_CONTENT}")
