#include <opencv2/opencv.hpp>

#include "collect.hpp"
#include "calibrator.hpp"
#include "file_writer.hpp"

using namespace std;
using namespace cv;

const string RELATIVE_CALIB_DIR_PATH = "../data/calibration";
const string RELATIVE_IMAGE_DIR_PATH = "../data/image/chessboard";
const Size PAT_SIZE(10, 7);
const float CHESS_SIZE = 23.0; //mm

int main()
{
	Mat intrinsics, distCoeffs;
	vector<Mat> images;

	collectImages(RELATIVE_IMAGE_DIR_PATH, images);

	calibrate_chessboard(images, intrinsics, distCoeffs, PAT_SIZE, CHESS_SIZE);

	cout << "intrinsics" << endl << intrinsics << endl;
	cout << "dist" << endl << distCoeffs << endl;

	writeParams(RELATIVE_CALIB_DIR_PATH + "/camera_params.xml", intrinsics, distCoeffs);

	return 0;
}