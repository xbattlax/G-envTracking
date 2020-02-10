//
//  enregistementModel.cpp
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


class Model {
    const char ext[5] = "yml/";
    int static entrainement(Ptr<FaceRecognizer> model, char* name[])
    {
        VideoCapture cam;
        cam.open(0);
        std::vector<int> YesOrNot;
        std::vector<GpuMat> images;
        int i;
        while (i<5000){
            GpuMat img;
            cam>>img;
            images.insert(img);
            YesOrNot.insert(1);
        }
        model->fit(images, YesOrNot);
        
        model->save(**name+".yml");
        return model;
    }
    
}

