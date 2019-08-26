#include "calibrator.hpp"

void calibrate(vector<Mat>& images, Mat& intrinsics, Mat& distCoeffs)
{
	int images_length = images.size();

	vector<vector<Point3f>> obj_points(images_length);
	vector<vector<Point2f>> img_points(images_length);


	for (int image_idx = 0; image_idx < images_length; image_idx++)
	{
		//image_points
		if (findChessboardCorners(images[image_idx], PAT_SIZE, img_points[image_idx]))
		{
			drawChessboardCorners(images[image_idx], PAT_SIZE, img_points[image_idx], true);
			cout << "success: " << image_idx << endl;
			//imshow("Show", images[i]);
			//waitKey(0);
		}
		else
		{
			cout << "fail: " << image_idx << endl;
			exit(1);
		}

		//object points
		for (int corner_idx = 0; corner_idx < PAT_SIZE.area(); corner_idx++)
		{
			Point3f p(
				static_cast<float>(corner_idx % PAT_SIZE.width * CHESS_SIZE),
				static_cast<float>(corner_idx / PAT_SIZE.width * CHESS_SIZE),
				0.0f
			);

			obj_points[image_idx].push_back(p);
		}
	}

	vector<Mat> rvecs, tvecs;
	calibrateCamera(obj_points, img_points, images[0].size(), intrinsics, distCoeffs, rvecs, tvecs);
	//cout << images[0].cols << " " << images[0].rows << endl;
}