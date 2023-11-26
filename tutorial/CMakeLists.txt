cmake_minimum_required(VERSION 3.15)

project(Tutorial VERSION 1.0)

add_subdirectory(Timer1)
add_subdirectory(Timer2)
add_subdirectory(Timer3)
add_subdirectory(Timer4)
add_subdirectory(Timer5)
add_subdirectory(SyncDaytime)
add_subdirectory(ASyncDaytime)
add_subdirectory(SyncUDPDaytime)
list(APPEND EXTRA_LIBS
	Timer1
	Timer2
	Timer3
	Timer4
	Timer5
	SyncDaytimeClient
	SyncDaytimeServer
	ASyncDaytimeClient
	ASyncDaytimeServer
	SyncUDPDaytimeClient
	SyncUDPDaytimeServer
)

add_compile_definitions(USE_ASYNC)

set(SRC_LIST tutorial.cc)

add_executable(${PROJECT_NAME} ${SRC_LIST})

target_link_libraries(
	${PROJECT_NAME} PUBLIC ${EXTRA_LIBS}
)

target_include_directories(
	${PROJECT_NAME} PUBLIC
	${PROJECT_BINARY_DIR}
)