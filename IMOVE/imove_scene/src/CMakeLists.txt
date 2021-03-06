find_package(Threads REQUIRED)
find_package(Boost 1.54.0 COMPONENTS system thread REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})
find_package(SFML 2.3.0 REQUIRED system window graphics network audio)
include_directories(${SFML_INCLUDE_DIR})
find_package(OpenCV REQUIRED HINTS ${OpenCV_DIR})
include_directories( ${OpenCV_INCLUDE_DIRS} )

file(GLOB_RECURSE GAME_SOURCE_FILES
        ../../../game/src/gameEntities/*.h
        ../../../game/src/gameEntities/*.cpp
        ../../../game/src/control/*.h
        ../../../game/src/control/*.cpp
        ../../../game/src/gameEntities/*.h
        ../../../game/src/gameEntities/*.cpp
        ../../../game/src/storage/*.h
        ../../../game/src/storage/*.cpp
        ../../../game/src/utility/*.h
        ../../../game/src/utility/*.cpp
        ../../../game/src/rendering/*.h
        ../../../game/src/rendering/*.cpp
        )

file(GLOB_RECURSE SOURCE_FILES
        "*.cpp"
        "../../scene_interface/src/*.cpp"
        "../../scene_interface_sma/src/*.cpp"
        "../../peopleextractor_interface_sma/src/*.cpp"
        "../../util/src/*.cpp"
        "Scene/GameIntegration/*.h"
        "Scene/GameIntegration/*.cpp")

message(STATUS "------------- Included Files -----------")
message(STATUS ${SOURCE_FILES})
message(STATUS "----------------------------------------")


ADD_EXECUTABLE(imove_scene ${SOURCE_FILES} ${GAME_SOURCE_FILES})
SET_TARGET_PROPERTIES(imove_scene PROPERTIES ENABLE_EXPORTS true)
SET_TARGET_PROPERTIES(imove_scene PROPERTIES COMPILE_FLAGS "${CMAKE_CXX_FLAGS}")

TARGET_LINK_LIBRARIES(imove_scene scene_interface)
TARGET_LINK_LIBRARIES(imove_scene scene_interface_sma)
TARGET_LINK_LIBRARIES(imove_scene peopleextractor_interface_sma)
TARGET_LINK_LIBRARIES(imove_scene ${CMAKE_THREAD_LIBS_INIT})
if(UNIX AND NOT APPLE)
    TARGET_LINK_LIBRARIES(imove_scene rt)
endif(UNIX AND NOT APPLE)
TARGET_LINK_LIBRARIES(imove_scene ${Boost_SYSTEM_LIBRARY})
TARGET_LINK_LIBRARIES(imove_scene ${Boost_THREAD_LIBRARY})
TARGET_LINK_LIBRARIES(imove_scene ${SFML_LIBRARIES})
TARGET_LINK_LIBRARIES(imove_scene ${OpenCV_LIBS})
