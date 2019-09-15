#include "calibrator.hpp"

void calibrate_charuco(vector<Mat>& images, Mat& intrinsics, Mat& distCoeffs, Ptr<aruco::Dictionary>& dictionary, Ptr<aruco::CharucoBoard>& board)
{
	int images_length = images.size();

	vector<vector<Point2f>> allCharucoCorners;
	vector<vector<int>> allCharucoIds;

	Ptr<aruco::DetectorParameters> params;
	params->cornerRefinementMethod = aruco::CORNER_REFINE_NONE;

	for (int image_idx = 0; image_idx < images_length; image_idx++)
	{
		vector<int> ids;
		vector<vector<Point2f>> corners;
		Mat image = images[image_idx];
		aruco::detectMarkers(image, dictionary, corners, ids, params);

		if (ids.size() <= 0) continue;

		vector<Point2f> charucoCorners;
		vector<int> charucoIds;
		aruco::interpolateCornersCharuco(corners, ids, image, board, charucoCorners, charucoIds);

		if (charucoIds.size() <= 0) continue;

		aruco::drawDetectedCornersCharuco(image, charucoCorners, charucoIds, Scalar(255, 0, 0));
		cout << "success: " << image_idx << endl;
		imshow("show", image);
		waitKey(0);

		allCharucoCorners.push_back(charucoCorners);
		allCharucoIds.push_back(charucoIds);
	}

	if (allCharucoIds.empty())
	{
		cerr << "No charuco boards" << endl;
		exit(1);
	}

	aruco::calibrateCameraCharuco(allCharucoCorners, allCharucoIds, board, images[0].size(), intrinsics, distCoeffs);
}

void calibrate_chessboard(vector<Mat>& images, Mat& intrinsics, Mat& distCoeffs, Size patSize, float chessSize)
{
	int images_length = images.size();

	vector<vector<Point3f>> obj_points(images_length);
	vector<vector<Point2f>> img_points(images_length);


	for (int image_idx = 0; image_idx < images_length; image_idx++)
	{
		//image_points
		if (findChessboardCorners(images[image_idx], patSize, img_points[image_idx]))
		{
			drawChessboardCorners(images[image_idx], patSize, img_points[image_idx], true);
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
		for (int corner_idx = 0; corner_idx < patSize.area(); corner_idx++)
		{
			Point3f p(
				static_cast<float>(corner_idx % patSize.width * chessSize),
				static_cast<float>(corner_idx / patSize.width * chessSize),
				0.0f
			);

			obj_points[image_idx].push_back(p);
		}
	}

	vector<Mat> rvecs, tvecs;
	calibrateCamera(obj_points, img_points, images[0].size(), intrinsics, distCoeffs, rvecs, tvecs);
	//cout << images[0].cols << " " << images[0].rows << endl;
}