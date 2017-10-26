#ifndef _PREDECLARE
#define _PREDECLARE

#pragma once

#ifndef GLEW_BUILD
    #define GLEW_BUILD
    #include <GL/glew.h>
    #include <GLFW/glfw3.h>
#endif // GLEW_BUILD

#ifndef STDLIBRARIES
    #define STDLIBRARIES
    #include <iostream>
    #include <fstream>
    #include <cstdio>
    #include <cstring>
    #include <vector>
    #include <string>
    #include <map>
    #include <iomanip>
#endif // STDLIBRARIES

//    #ifndef EIGEN
//        #define EIGEN
//        #include <Eigen/Eigen>
//    #endif // EIGEN

#ifndef GLM
    #include <glm/glm.hpp>
    #include <glm/gtc/matrix_transform.hpp>
    #include <glm/gtc/type_ptr.hpp>
#endif // GLM

#endif // _PREDECLARE
