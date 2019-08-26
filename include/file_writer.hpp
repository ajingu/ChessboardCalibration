#pragma once

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void write_params(const string file_path, const Mat& intrinsics, const Mat& distCoeffs);