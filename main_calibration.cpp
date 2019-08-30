#include <opencv2/opencv.hpp>

#include "collect.hpp"
#include "calibrator.hpp"
#include "file_writer.hpp"

using namespace std;
using namespace cv;

const string RELATIVE_CALIB_DIR_PATH = "../data/calibration";
const string RELATIVE_IMAGE_DIR_PATH = "../data/image";

int main()
{
	Mat intrinsics, distCoeffs;
	vector<Mat> images;

	collectImages(RELATIVE_IMAGE_DIR_PATH, images);

	calibrate(images, intrinsics, distCoeffs);

	cout << "intrinsics" << endl << intrinsics << endl;
	cout << "dist" << endl << distCoeffs << endl;

	writeParams(RELATIVE_CALIB_DIR_PATH + "/camera_params.xml", intrinsics, distCoeffs);

	return 0;
}