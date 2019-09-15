#include <opencv2/opencv.hpp>
#include <opencv2/aruco.hpp>
#include <opencv2/aruco/charuco.hpp>

using namespace std;
using namespace cv;

void calibrate_charuco(vector<Mat>& images, Mat& intrinsics, Mat& distCoeffs, Ptr<aruco::Dictionary>& dictionary, Ptr<aruco::CharucoBoard>& board);
void calibrate_chessboard(vector<Mat>& images, Mat& intrinsics, Mat& distCoeffs, Size patSize, float chessSize);