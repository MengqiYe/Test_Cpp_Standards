set(CMAKE_CXX_STANDARD 11)

include_directories(
        ${CMAKE_CURRENT_LIST_DIR}/inc
)

aux_source_directory(${CMAKE_CURRENT_LIST_DIR} TESTCASES)
aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/stl_algorithms TESTCASES)
aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/templates TESTCASES)

message(STATUS "TESTCASES : ${TESTCASES}")

foreach (TEST ${TESTCASES})
    get_filename_component(TESTNAME ${TEST} NAME_WE)
    add_executable(test_11_${TESTNAME} ${TEST})
    target_link_libraries(test_11_${TESTNAME} ${TORCH_LIBRARIES} ${OpenCV_LIBRARIES})

    if (${TESTNAME} MATCHES matplotlib)
        message(STATUS "${TESTNAME} matches")
        target_link_libraries(test_11_${TESTNAME} python3.8)
    endif ()

endforeach ()

