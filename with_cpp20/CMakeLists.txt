set(V 20)
set(CMAKE_CXX_STANDARD ${V})

include_directories(
        ${CMAKE_CURRENT_LIST_DIR}/inc
)
aux_source_directory(${CMAKE_CURRENT_LIST_DIR} TESTCASES)

foreach (TEST ${TESTCASES})
    get_filename_component(TESTNAME ${TEST} NAME_WE)
    add_executable(test_${V}_${TESTNAME} ${TEST})
    target_link_libraries(test_${V}_${TESTNAME} ${TORCH_LIBRARIES} ${OpenCV_LIBRARIES})

    if (${TESTNAME} MATCHES matplotlib)
        message(STATUS "${TESTNAME} matches")
        #        include_directories(
        #                /tool/miniconda3/envs/build_pytorch_1.6/lib/python3.8/site-packages/numpy/core/include
        #                /usr/include/python3.8
        #        )
        target_link_libraries(test_${V}_${TESTNAME} python3.8)
    endif ()

endforeach ()
