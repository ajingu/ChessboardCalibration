#pragma once

#include <iostream>
#include <filesystem>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace std::experimental::filesystem;
using namespace cv;

void collectImages(const string relative_image_dir_path, vector<Mat>& images);