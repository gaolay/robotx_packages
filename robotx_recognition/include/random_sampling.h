#ifndef RANDOM_SAMPLING_H_INCLUDED
#define RANDOM_SAMPLING_H_INCLUDED

#include <vector>
#include <opencv2/opencv.hpp>

class random_sampling
{
public:
    struct parameters
    {
        struct width
        {
            int max;
            int min;
        };
        struct height
        {
            int max;
            int min;
        };
        struct aspect_ratio
        {
            double max;
            double min;
        };
        width roi_width;
        height roi_height;
        aspect_ratio roi_aspect_ratio;
        int num_roi;
        int image_width;
        int image_height;
        parameters()
        {
            num_roi = 100;
            image_width = 640;
            image_height = 480;
            roi_width.max = 320;
            roi_width.min = 20;
            roi_height.max = 320;
            roi_height.min = 20;
            roi_aspect_ratio.max = 5.0;
            roi_aspect_ratio.min = 0.2;
        }
    };
    std::vector<cv::Rect> get_rois();
    random_sampling();
    random_sampling(parameters params);
    ~random_sampling();
private:
    parameters params_;
};

#endif  //RANDOM_SAMPLING_H_INCLUDED