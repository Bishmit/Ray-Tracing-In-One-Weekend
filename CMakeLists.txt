cmake_minimum_required(VERSION 3.15)

project(Ray_Tracing_In_One_Week)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(${PROJECT_NAME}
    main.cpp
    src/Vec3.cpp
    src/Camera.cpp
    src/Ray.cpp
    src/Sphere.cpp
    src/HittableList.cpp
)

