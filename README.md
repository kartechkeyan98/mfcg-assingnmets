# Assignment 3
Till now we have covered making spheres and donuts among the primitive shapes for our ray tracer. We have also covered different types of materials like glass, metals and diffuse materials.

Build and run the current project to check the output. It should look something like this : 
![image.png](image.png)

Notice it does not show any donuts. We have purposefully deleted the `donut.h` file which was shown during the session while covering ray-donut intersections. 

- Your FIRST TASK is to rewrite the `donut.h` file and add instances of donuts in the `main.cpp` file. Render the final image, covert to png add it in a folder `renders` in the root directory.
- Your SECOND TASK is to add one more material class in the `material.h` file. This material will have the property of being able to emit it own light apart from reflecting off and scattering other lights. Take reasonable parameters like `light_intensity` and `light_color` accordingly. Add the material to some of the objects in the scene. Render the image and save it as png in the `renders` folder in the root directory.

Make sure the project builds properly using CMake and you get a valid output.

Submission deadline : 26 June, 11:59 PM

[Link to the GitHub repository :](https://github.com/ishanbawne20/mfcg2023.git)

Resources :

[Ray tracing in one weekend (almost everything is from here)](https://raytracing.github.io/books/RayTracingInOneWeekend.html)

[C++](https://www.w3schools.com/cpp/cpp_oop.asp)

[Cmake Documentation](https://cmake.org/documentation/)

[A short refresher to rendering equation](https://youtu.be/GOfzX7kRwys)

[A short refresher to ray tracing](https://youtu.be/gGKup9tUSrU)

[OOP(if youre still struggling with understanding the project structure)](https://youtu.be/wN0x9eZLix4)