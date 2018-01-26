#include <opencv2\opencv.hpp>
#include <random>

using namespace std;
using namespace cv;

void main()
{
	int radius = 250;
	long long max_try = 1000000000;
	long long ntry = 0;
	long long n_in = 0;
	Mat plain(Size(2 * radius + 1, 2 * radius + 1), CV_8UC3);
	plain.setTo(Scalar(0));
	circle(plain, Point(radius, radius), radius, Scalar(0, 255, 0), 2);

	default_random_engine gen;
	uniform_real_distribution<double> udis(-0.5, 0.5);
	while (ntry <= max_try)
	{
		++ntry;
		double p1 = udis(gen);
		double p2 = udis(gen);
		int x = (p1 + 0.5) * 2. * radius;
		int y = (p2 + 0.5) * 2. * radius;

		double dist = sqrt((p1*p1) + (p2*p2));
		if (dist < 0.5) // in
		{
			plain.at<Vec3b>(x, y)[2] = 255;
			++n_in;
		}
		else  // out
		{
			plain.at<Vec3b>(x, y)[0] = 255;
		}

		cout << ntry << ": " << 4.0*((double)n_in / (double)ntry) << endl;

		imshow("show", plain);
		
		if (waitKey(1) == 27)
			break;				
	}		
}