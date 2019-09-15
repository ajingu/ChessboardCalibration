#include <opencv2/opencv.hpp>
#include <opencv2/aruco.hpp>
#include <opencv2/aruco/charuco.hpp>

#include "collect.hpp"
#include "calibrator.hpp"
#include "file_writer.hpp"

using namespace std;
using namespace cv;

const string RELATIVE_CALIB_DIR_PATH = "../data/calibration";
const string RELATIVE_IMAGE_DIR_PATH = "../data/image/charuco";

int main()
{
	Mat intrinsics, distCoeffs;
	vector<Mat> images;

	Ptr<aruco::Dictionary> dictionary = aruco::getPredefinedDictionary(aruco::DICT_6X6_250);
	Ptr<aruco::CharucoBoard> board = aruco::CharucoBoard::create(5, 7, 0.04, 0.02, dictionary);

	collectImages(RELATIVE_IMAGE_DIR_PATH, images);

	calibrate_charuco(images, intrinsics, distCoeffs, dictionary, board);

	cout << "intrinsics" << endl << intrinsics << endl;
	cout << "dist" << endl << distCoeffs << endl;

	writeParams(RELATIVE_CALIB_DIR_PATH + "/camera_params.xml", intrinsics, distCoeffs);

	return 0;
}