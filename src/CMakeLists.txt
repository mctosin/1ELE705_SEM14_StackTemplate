set(src main.c)

add_library(${PROJECT_NAME} SHARED ${src})

#Poderia apagar
target_link_libraries(${PROJECT_NAME} pthread)

