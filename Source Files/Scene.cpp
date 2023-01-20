#include "Scene.h"

Scene::Scene(const Vector3 &background) : background(background) {}

void Scene::addObject(Object *object) { objects.push_back(object); }
void Scene::addLight(const Light &light) { lights.push_back(light); }

Vector3 Scene::trace(const Ray &ray, int depth)
{
    Vector3 point, normal;
    Object *closestObject = nullptr;
    double closestT = 1e9;
    for (auto object : objects)
    {
        Vector3 point1, normal1;
        if (object->intersect(ray, point1, normal1))
        {
            double t = (point1 - ray.origin).length();
            if (t < closestT)
            {
                closestT = t;
                closestObject = object;
                normal = normal1;
                point = point1;
            }
        }
    }
    if (!closestObject)
        return background;
    Vector3 color = Vector3(0, 0, 0);
    for (auto light : lights)
    {
        Vector3 lightDirection = (light.position - point).normalize();
        bool inShadow = false;
        for (auto object : objects)
        {
            if (object == closestObject)
                continue;
            Vector3 shadowPoint, shadowNormal;
            if (object->intersect(Ray(point, lightDirection), shadowPoint, shadowNormal))
            {
                if ((shadowPoint - point).length() < (light.position - point).length())
                {
                    inShadow = true;
                    break;
                }
            }
        }

        double diffuse = normal.dot(lightDirection);
        if (diffuse > 0)
        {
            color = color + closestObject->material.color * light.color * diffuse;
            if (inShadow) {
                color = color * 0.25;
            }
        }
    }
    if (depth < 10 && closestObject->material.reflectivity > 0)
    {
        Vector3 reflectionDirection = (ray.direction - normal * 2 * ray.direction.dot(normal)).normalize();
        Vector3 reflectionColor = trace(Ray(point, reflectionDirection), depth + 1);
        color = color + reflectionColor * closestObject->material.reflectivity;
    }
    return color;
}