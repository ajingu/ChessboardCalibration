#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

const string RELATIVE_IMAGE_DIR_PATH = "../data/image";

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
	VideoCapture cam(0);

	if (!cam.isOpened())
	{
		cerr << "Camera is not opened." << endl;
		return -1;
	}


	while (true)
	{
		cam >> img;
		imshow("Show", img);

		int key = waitKey(10);
		if (key == 'q')
		{
			cam.release();
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