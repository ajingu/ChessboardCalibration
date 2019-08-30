#include <opencv2/opencv.hpp>
#include "camera.hpp"
#include "webcamera.hpp"

using namespace std;
using namespace cv;

const string RELATIVE_IMAGE_DIR_PATH = "../data/image";
const int CAMERA_WIDTH = 640;
const int CAMERA_HEIGHT = 480;

string buildSaveImgPath(int index)
{
	string index_str = to_string(index);

	if (index < 10)
	{
		index_str = "0" + index_str;
	}

	return RELATIVE_IMAGE_DIR_PATH + "/image" + index_str + ".png";
}

int main()
{
	int index = 0;
	Mat img;

	WebCamera camera = WebCamera(CAMERA_WIDTH, CAMERA_HEIGHT);
	camera.start();

	while (true)
	{
		camera.getImage(img);
		imshow("Show", img);

		int key = waitKey(10);
		if (key == 'q')
		{
			camera.release();
			break;
		}
		else if (key == 's')
		{
			string save_img_path = buildSaveImgPath(index);
			imwrite(save_img_path, img);
			index++;
			cout << "Saved: " << save_img_path << endl;
		}
	}

	return 0;
}