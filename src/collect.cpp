#include "collect.hpp"

void collectImages(const string relative_image_dir_path, vector<Mat>& images)
{
	for (auto& p : directory_iterator(relative_image_dir_path))
	{
		Mat img = imread(p.path().string());
		images.push_back(img);
		//imshow(p.path().string(), img);
	}
}