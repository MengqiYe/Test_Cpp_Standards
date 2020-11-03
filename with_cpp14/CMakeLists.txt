set(CMAKE_CXX_STANDARD 14)

include_directories(
        ${CMAKE_CURRENT_LIST_DIR}/inc
)

aux_source_directory(${CMAKE_CURRENT_LIST_DIR} TESTCASES)
aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/stl_algorithms TESTCASES)
aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/templates TESTCASES)

message(STATUS "TESTCASES : ${TESTCASES}")

foreach (TEST ${TESTCASES})
    get_filename_component(dirname ${TEST} DIRECTORY)
    set(relative_dir "")
    string(REPLACE ${CMAKE_CURRENT_LIST_DIR} "" M ${dirname})
    if (NOT ${M} STREQUAL "")
        string(REPLACE "/" "_" M ${M})
    endif ()
    get_filename_component(TESTNAME ${TEST} NAME_WE)
    set(EXECUTABLE_NAME test_14${M}_${TESTNAME})
    add_executable(${EXECUTABLE_NAME} ${TEST})
    target_link_libraries(${EXECUTABLE_NAME} ${TORCH_LIBRARIES} ${OpenCV_LIBRARIES})

    if (${TESTNAME} MATCHES matplotlib)
        message(STATUS "${TESTNAME} matches")
        target_link_libraries(${EXECUTABLE_NAME} python3.8)
    endif ()

    if (${TESTNAME} MATCHES thread)
        target_link_libraries(${EXECUTABLE_NAME} pthread)
    endif ()

endforeach ()

