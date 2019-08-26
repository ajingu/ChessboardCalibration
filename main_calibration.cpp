#include <opencv2/opencv.hpp>

#include "collect.hpp"

using namespace std;
using namespace cv;

const string RELATIVE_CALIB_DIR_PATH = "../data/calibration";
const string RELATIVE_IMAGE_DIR_PATH = "../data/image";
const Size PAT_SIZE(10, 7);

int main()
{
	Mat intrinsics, dist;
	vector<Mat> r_vecs, t_vecs, images;

	collectImages(RELATIVE_IMAGE_DIR_PATH, images);

	waitKey(0);

	return 0;
}