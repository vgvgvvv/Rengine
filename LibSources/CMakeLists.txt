

add_definitions(
	-DTW_STATIC
	-DTW_NO_LIB_PRAGMA
	-DTW_NO_DIRECT3D
	-DGLEW_STATIC
	-D_CRT_SECURE_NO_WARNINGS
)

### GLFW ###

add_subdirectory (glfw)

include_directories(
		glfw/include/GLFW/
		glew/include/
		stb/
		)

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
set(OPENGL_LIBRARY
	${OPENGL_LIBRARY}
	-lGL -lGLU -lXrandr -lXext -lX11 -lrt
	${CMAKE_DL_LIBS}
	${GLFW_LIBRARIES}
)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
set(OPENGL_LIBRARY
	${OPENGL_LIBRARY}
	${CMAKE_DL_LIBS}
	${GLFW_LIBRARIES}
)
endif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")


### GLEW ###

set(GLEW_SOURCE
	glew/src/glew.c
)

set(GLEW_HEADERS
)


add_library( GLEW_1130 STATIC
		${GLEW_SOURCE}
		${GLEW_INCLUDE}
		)

target_link_libraries(GLEW_1130
		${OPENGL_LIBRARY}
		${EXTRA_LIBS}
		)

### GLM ###
add_subdirectory(glm)
set(OPENGL_LIBRARY
        ${OPENGL_LIBRARY}
        ${glm}
        )

### STB ###
set(STB_SOURCE
        stb/stb_image.cpp
        )

add_library(STB STATIC
        ${STB_SOURCE}
        )
