set(DEMO_SOURCE_FILES tecolor_demo.cpp ../include/TeColor/TeColor)
add_executable(tecolor_demo ${DEMO_SOURCE_FILES})
target_link_libraries(tecolor_demo tecolor)

