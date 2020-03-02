include(${CMAKE_MODULE_PATH}/qt5.cmake)

set(QT_TARGET_NAME qt_test)

aux_source_directory(. Qt_SRCS)

qt5_add_resources(UI_QRC ui.rcc)

add_executable(${QT_TARGET_NAME} ${Qt_SRCS} ${UI_QRC})

if (UNIX AND NOT Android)
    set(PLATFORM_DEPS pthread)
endif ()

target_link_libraries(${QT_TARGET_NAME} Qt5::Gui Qt5::Qml ${PLATFORM_DEPS})