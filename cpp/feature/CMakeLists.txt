
add_executable(test_feature main.cc)

if (UNIX AND NOT ANDROID)
    set(PLATFORM_DEPS pthread)
endif()

target_link_libraries(test_feature glog gflags ${PLATFORM_DEPS})