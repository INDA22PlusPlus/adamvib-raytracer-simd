#include <iostream>
#include <vector>
#include <cmath>
#include <nanobench.h>
#include "Vector3.hpp"
#include "Ray.hpp"
#include "Camera.hpp"
#include "Light.hpp"
#include "Material.hpp"
#include "Object.hpp"
#include "Sphere.hpp"
#include "Plane.hpp"
#include "Scene.hpp"

int main(int argc, char *argv[])
{
    Scene scene(Vector3(0.3, 0.3, 0.3));
    
    scene.addObject(new Sphere(Vector3(1, 0, 3), 0.5, Material(Vector3(1, 0, 0), 0.4)));
    scene.addObject(new Sphere(Vector3(-1, 0, 3), 0.5, Material(Vector3(0, 1, 0), 0.4)));
    scene.addObject(new Sphere(Vector3(0, 0.3, 2), 0.2, Material(Vector3(1, 0.25, 1), 0.1)));
    
    scene.addObject(new Plane(Vector3(0, 1, 0), Vector3(0, -1, 0), Material(Vector3(0, 0, 1), 0.5)));
    scene.addObject(new Plane(Vector3(0, 0, 3.5), Vector3(0, 0, -1), Material(Vector3(0, 0, 1), 0.5)));
    scene.addObject(new Plane(Vector3(1.5, 0, 0), Vector3(-1, 0, 0), Material(Vector3(0, 0, 1), 0.5)));
    scene.addObject(new Plane(Vector3(-1.5, 0, 0), Vector3(1, 0, 0), Material(Vector3(0, 0, 1), 0.5)));

    scene.addLight(Light(Vector3(0, -1, -1), Vector3(1, 1, 1)));
    
    double width = 300;
    double height = 300;

    // if (argc > 1)
    // {
    //     width = std::stoi(argv[1]);
    //     height = std::stoi(argv[2]);
    // }

    double aspectRatio = width / height;

    Camera camera(Vector3(0, 0, 0), Vector3(0, 0, 1), aspectRatio, 90);

    // std::cout << "P3" << std::endl;
    // std::cout << "# Raytracer output" << std::endl;
    // std::cout << width << " " << height << std::endl;
    // std::cout << "255" << std::endl;

    ankerl::nanobench::Bench().warmup(3).run("rayracer", [&] {
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                // Ray middleRay = camera.getRay((double)x / width, (double)y / height);
                // Ray rays[] = {
                //     camera.getRay((double)x / width + 0.5 / width, (double)y / height + 0.5 / height),
                //     camera.getRay((double)x / width + 0.5 / width, (double)y / height - 0.5 / height),
                //     camera.getRay((double)x / width - 0.5 / width, (double)y / height + 0.5 / height),
                //     camera.getRay((double)x / width - 0.5 / width, (double)y / height - 0.5 / height),
                // };
                // Vector3 color = scene.trace(middleRay, 0);
                // for (int i = 0; i < 5; i++)
                // {
                //     color = color.avarage(scene.trace(rays[i], 0));
                // }
                // std::cout << (int)(color.x * 255) << " " << (int)(color.y * 255) << " " << (int)(color.z * 255) << std::endl;


                Ray ray = camera.getRay((double)x / width, (double)y / height);
                Vector3 color = scene.trace(ray, 0);
                // std::cout << (int)(color.x * 255) << " " << (int)(color.y * 255) << " " << (int)(color.z * 255) << std::endl;
            }
        }
    });

    return 0;
}