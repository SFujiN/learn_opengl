CXXFLAGS = -lglfw -lGL -lX11 -lXxf86vm -lXinerama -lXcursor -lpthread -lXrandr -lXi -ldl -lm
CC = g++
INC = -I ../include

all : hello_window hello_triangle hello_triangle_ex1 hello_triangle_ex2 hello_triangle_ex3 shader_crimson shader_uniform shader_rotate shader_more_attr shader_ex1 shader_ex2 shader_ex3 texture_brick_triangle texture_wooden_container texture_ex1 texture_ex2 texture_ex3 texture_ex4 transformation transformation_ex1 transformation_ex2 coordinate_system coordinate_system_cube coordinate_system_many_cubes coordinate_system_ex1 coordinate_system_ex2 coordinate_system_ex3 camera camera_walk_around camera_ex1 camera_ex2

hello_window : hello_window.cpp glad.o
	$(CC) hello_window.cpp glad.o $(CXXFLAGS) $(INC) -o hello_window

hello_triangle : hello_triangle.cpp glad.o
	$(CC) hello_triangle.cpp glad.o $(CXXFLAGS) $(INC) -o hello_triangle

hello_triangle_ex1 : hello_triangle_ex1.cpp glad.o
	$(CC) hello_triangle_ex1.cpp glad.o $(CXXFLAGS) $(INC) -o hello_triangle_ex1

hello_triangle_ex2 : hello_triangle_ex2.cpp glad.o
	$(CC) hello_triangle_ex2.cpp glad.o $(CXXFLAGS) $(INC) -o hello_triangle_ex2

hello_triangle_ex3 : hello_triangle_ex3.cpp glad.o
	$(CC) hello_triangle_ex3.cpp glad.o $(CXXFLAGS) $(INC) -o hello_triangle_ex3

shader_crimson : shader_crimson.cpp glad.o
	$(CC) shader_crimson.cpp glad.o $(CXXFLAGS) $(INC) -o shader_crimson

shader_uniform : shader_uniform.cpp glad.o
	$(CC) shader_uniform.cpp glad.o $(CXXFLAGS) $(INC) -o shader_uniform

shader_rotate : shader_rotate.cpp glad.o
	$(CC) shader_rotate.cpp glad.o $(CXXFLAGS) $(INC) -o shader_rotate

shader_more_attr : shader_more_attr.cpp glad.o
	$(CC) shader_more_attr.cpp glad.o $(CXXFLAGS) $(INC) -o shader_more_attr

shader_ex1: shader_ex1.cpp glad.o shader_s.o
	$(CC) shader_ex1.cpp glad.o shader_s.o $(CXXFLAGS) $(INC) -o shader_ex1

shader_ex2: shader_ex2.cpp glad.o shader_s.o
	$(CC) shader_ex2.cpp glad.o shader_s.o $(CXXFLAGS) $(INC) -o shader_ex2

shader_ex3: shader_ex3.cpp glad.o shader_s.o
	$(CC) shader_ex3.cpp glad.o shader_s.o $(CXXFLAGS) $(INC) -o shader_ex3

texture_brick_triangle: texture_brick_triangle.cpp glad.o shader_s.o stb_image.o
	$(CC) texture_brick_triangle.cpp glad.o shader_s.o stb_image.o $(CXXFLAGS) $(INC) -o texture_brick_triangle

texture_wooden_container: texture_wooden_container.cpp glad.o shader_s.o stb_image.o
	$(CC) texture_wooden_container.cpp glad.o shader_s.o stb_image.o $(CXXFLAGS) $(INC) -o texture_wooden_container

texture_ex1: texture_ex1.cpp glad.o shader_s.o stb_image.o
	$(CC) texture_ex1.cpp glad.o shader_s.o stb_image.o $(CXXFLAGS) $(INC) -o texture_ex1

texture_ex2: texture_ex2.cpp glad.o shader_s.o stb_image.o
	$(CC) texture_ex2.cpp glad.o shader_s.o stb_image.o $(CXXFLAGS) $(INC) -o texture_ex2

texture_ex3: texture_ex3.cpp glad.o shader_s.o stb_image.o
	$(CC) texture_ex3.cpp glad.o shader_s.o stb_image.o $(CXXFLAGS) $(INC) -o texture_ex3

texture_ex4: texture_ex4.cpp glad.o shader_s.o stb_image.o
	$(CC) texture_ex4.cpp glad.o shader_s.o stb_image.o $(CXXFLAGS) $(INC) -o texture_ex4

transformation: transformation.cpp glad.o shader_s.o stb_image.o
	$(CC) transformation.cpp glad.o shader_s.o stb_image.o $(CXXFLAGS) $(INC) -o transformation

transformation_ex1: transformation_ex1.cpp glad.o shader_s.o stb_image.o
	$(CC) transformation_ex1.cpp glad.o shader_s.o stb_image.o $(CXXFLAGS) $(INC) -o transformation_ex1

transformation_ex2: transformation_ex2.cpp glad.o shader_s.o stb_image.o
	$(CC) transformation_ex2.cpp glad.o shader_s.o stb_image.o $(CXXFLAGS) $(INC) -o transformation_ex2

coordinate_system: coordinate_system.cpp glad.o shader_s.o stb_image.o
	$(CC) coordinate_system.cpp glad.o shader_s.o stb_image.o $(CXXFLAGS) $(INC) -o coordinate_system

coordinate_system_cube: coordinate_system_cube.cpp glad.o shader_s.o stb_image.o
	$(CC) coordinate_system_cube.cpp glad.o shader_s.o stb_image.o $(CXXFLAGS) $(INC) -o coordinate_system_cube

coordinate_system_many_cubes: coordinate_system_many_cubes.cpp glad.o stb_image.o
	$(CC) coordinate_system_many_cubes.cpp glad.o stb_image.o $(CXXFLAGS) $(INC) -o coordinate_system_many_cubes

coordinate_system_ex1: coordinate_system_ex1.cpp glad.o shader_s.o stb_image.o
	$(CC) coordinate_system_ex1.cpp glad.o shader_s.o stb_image.o $(CXXFLAGS) $(INC) -o coordinate_system_ex1

coordinate_system_ex2: coordinate_system_ex2.cpp glad.o shader_s.o stb_image.o
	$(CC) coordinate_system_ex2.cpp glad.o shader_s.o stb_image.o $(CXXFLAGS) $(INC) -o coordinate_system_ex2

coordinate_system_ex3: coordinate_system_ex3.cpp glad.o shader_s.o stb_image.o
	$(CC) coordinate_system_ex3.cpp glad.o shader_s.o stb_image.o $(CXXFLAGS) $(INC) -o coordinate_system_ex3

camera: camera.cpp glad.o stb_image.o
	$(CC) camera.cpp glad.o stb_image.o $(CXXFLAGS) $(INC) -o camera

camera_walk_around: camera_walk_around.cpp glad.o stb_image.o
	$(CC) camera_walk_around.cpp glad.o stb_image.o $(CXXFLAGS) $(INC) -o camera_walk_around

camera_ex1: camera_ex1.cpp glad.o stb_image.o
	$(CC) camera_ex1.cpp glad.o stb_image.o $(CXXFLAGS) $(INC) -o camera_ex1

camera_ex2: camera_ex2.cpp glad.o stb_image.o
	$(CC) camera_ex2.cpp glad.o stb_image.o $(CXXFLAGS) $(INC) -o camera_ex2

colors_scene: colors_scene.cpp glad.o stb_image.o
	$(CC) colors_scene.cpp glad.o stb_image.o $(CXXFLAGS) $(INC) -o colors_scene

basic_lighting: basic_lighting.cpp glad.o stb_image.o
	$(CC) basic_lighting.cpp glad.o stb_image.o $(CXXFLAGS) $(INC) -o basic_lighting

basic_lighting_ex1: basic_lighting_ex1.cpp glad.o stb_image.o
	$(CC) basic_lighting_ex1.cpp glad.o stb_image.o $(CXXFLAGS) $(INC) -o basic_lighting_ex1

basic_lighting_ex2: basic_lighting_ex2.cpp glad.o stb_image.o
	$(CC) basic_lighting_ex2.cpp glad.o stb_image.o $(CXXFLAGS) $(INC) -o basic_lighting_ex2

basic_lighting_ex3: basic_lighting_ex3.cpp glad.o stb_image.o
	$(CC) basic_lighting_ex3.cpp glad.o stb_image.o $(CXXFLAGS) $(INC) -o basic_lighting_ex3

materials: materials.cpp glad.o
	$(CC) materials.cpp glad.o $(CXXFLAGS) $(INC) -o materials

materials_ex1: materials_ex1.cpp glad.o
	$(CC) materials_ex1.cpp glad.o $(CXXFLAGS) $(INC) -o materials_ex1

materials_ex2: materials_ex2.cpp glad.o
	$(CC) materials_ex2.cpp glad.o $(CXXFLAGS) $(INC) -o materials_ex2

glad.o : glad.c
	$(CC) $(INC) -c glad.c

shader_s.o : shader_s.cpp
	$(CC) $(INC) -c shader_s.cpp

stb_image.o : stb_image.cpp
	$(CC) $(INC) -c stb_image.cpp

.PHONY: clean
clean :
	rm -f hello_window hello_triangle hello_triangle_ex1 hello_triangle_ex2 hello_triangle_ex3 shader_crimson shader_uniform shader_rotate shader_more_attr shader_ex1 shader_ex2 shader_ex3 texture_brick_triangle texture_wooden_container texture_ex1 texture_ex2 texture_ex3 texture_ex4 transformation transformation_ex1 transformation_ex2 coordinate_system coordinate_system_cube coordinate_system_many_cubes coordinate_system_ex1 coordinate_system_ex2 coordinate_system_ex3 camera camera_walk_around camera_ex1 camera_ex2 colors_scene basic_lighting basic_lighting_ex1 basic_lighting_ex2 basic_lighting_ex3 materials materials_ex1 materials_ex2

clean_objects :
	rm -f glad.o shader.o stb_image.o
