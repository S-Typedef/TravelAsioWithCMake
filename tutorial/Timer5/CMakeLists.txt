cmake_minimum_required(VERSION 3.15)

project(Timer5 VERSION 1.0)

set(BOOST_ROOT /usr/local/boost)
set(Boost_NO_SYSTEM_PATHS ON)

find_package(Boost COMPONENTS thread REQUIRED)
if (Boost_FOUND)

	include_directories(
		${Boost_INCLUDE_DIRS}
	)

endif()

set(SRC_LIST timer-5.cc)

add_library(${PROJECT_NAME} ${SRC_LIST})

target_link_libraries(
    ${PROJECT_NAME}
    Boost::thread
  )

target_include_directories(${PROJECT_NAME}
	INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)
