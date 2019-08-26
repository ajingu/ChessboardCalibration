#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

const Size PAT_SIZE(10, 7);
const float CHESS_SIZE = 23.0; //mm

void calibrate(vector<Mat>& images, Mat& intrinsics, Mat& distCoeffs);