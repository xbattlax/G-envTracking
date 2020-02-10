//
//  main.cpp
//  G-EnvVideoTracking
//
//  Created by Nathan Metzger on 2/10/20.
//  Copyright © 2020 Monlon Metzger. All rights reserved.
//

#include "main.hpp"
#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/gpu/gpu.hpp"

using namespace cv;
using namespace cv::gpu;

int main(int argc, char* argv[])
{
    VideoCapture cam;
    cam.open(0);
    
    if (!cam.open(0)){
        return 0;
    }
    
    while (true){
        GpuMat img;
        cam >> img;
        if (img.empty()){
            return 9;
        }
        imshow("Camera", img);
    }
}
