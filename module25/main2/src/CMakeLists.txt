add_executable(
    main2 
    main.cpp
    cpu.cpp
    disk.cpp
    gpu.cpp
    keyboard.cpp
    ram.cpp
)

target_include_directories(main2 PUBLIC ${PROJECT_SOURCE_DIR}/include)