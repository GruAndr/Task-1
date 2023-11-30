#include <random>
//#include "CADEX C++ assignment.h"
#include "curves.h"




int main()
{
    std::vector<std::unique_ptr<Curve>> curves;

    for (int i = 0; i < 50; i++)
    {
        int o = rand()%3;
        std::vector<double> result;
        
       
        switch (o)
        {
        case 0:

            curves.push_back(std::make_unique<Circle>(rand() % 9, rand() % 9, 0.0, rand() % 25));
            std::cout << " Circle with point at t = PI/4 || x = ";
            result = curves[i]->getPoint(M_PI / 4);
            std::cout << result[0] << " / y =  " << result[1] << " / z= 0.0 " << std::endl;
            result = curves[i]->getDerivative(M_PI / 4);
            std::cout << " and deriviative with t= PI/4 || x = " << result[0] << " /y =  " << result[1] << " /z =  0.0" << std::endl;
            std::cout << std::endl;

            break;

        case 1:

            curves.push_back(std::make_unique <Ellipse>(rand() % 9, rand() % 9, 0.0, rand() % 25, rand() % 25));
            std::cout << " Ellipse with point at t = PI/4 || x = ";
            result = curves[i]->getPoint(M_PI / 4);
            std::cout << result[0] << " / y =  " << result[1] << " / z= 0.0 " << std::endl;
            result = curves[i]->getDerivative(M_PI / 4);
            std::cout << " and deriviative with t= PI/4 || x = " << result[0] << " /y =  " << result[1] << " /z =  0.0" << std::endl;
            std::cout << std::endl;

            break;

        case 2:

            curves.push_back(std::make_unique <Helix>(rand() % 9, rand() % 9, 0.0, rand() % 25, rand() % 25));
            std::cout << " Helix with point at t = PI/4 ||  x = ";
            result = curves[i]->getPoint(M_PI / 4);
            std::cout << result[0] << " / y =  " << result[1] << " / z=  " << result[2] << std::endl;


            result = curves[i]->getDerivative(M_PI / 4);
            std::cout << " and deriviative with t= PI/4 || x = " << result[0] << " /y =  " << result[1] << " /z =  " << result[2] << std::endl;
            std::cout << std::endl;


            break;

        default:

            break;

        }
        
        
    }

    std::vector<Circle*> circles;


    for (const auto& curve : curves) {
        if (dynamic_cast<Circle*>(curve.get())) {
            circles.push_back(static_cast<Circle*>(curve.get()));
        }
    }


    std::sort(circles.begin(), circles.end(), [](Circle* a,Circle* b) {
        return a->getRadius() < b->getRadius();
        });

    int sum = 0;


    for (const auto& circle : circles)
    {
        sum += circle->getRadius();
        
    }

    for (const auto& curve : curves) {
        curve->~Curve();
        
    }
    

    for (const auto& circle:circles)
    {
        circle->~Circle();
    }


    curves.clear();
    curves.shrink_to_fit();

    circles.clear();
    circles.shrink_to_fit();

    return 0;
}
