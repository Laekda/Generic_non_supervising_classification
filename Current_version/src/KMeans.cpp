#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Functions.hpp"
#include "KMeans.hpp"

using namespace cimg_library;
using T = double;

int main(int argc, char const *argv[]) {

  // srand(time(NULL)); // initialisation de rand
  std::string name, path_name("../images/");
  int nb_clusters(1), max_iter(100);

  std::cout << "Enter the name of the image you want to analyse :" << '\n';
  std::cin >> name;
  CImg<T> image((path_name+name).c_str());
  T max_value = 255;

  average_grey(image);

  std::cout << "How many clusters do you want to identify ?" << '\n';
  std::cin >> nb_clusters;

  std::cout << "What is the max limit ?" << '\n';
  std::cin >> max_iter;

  // KMeans<T, Linf<T>> kfisrt(image, nb_clusters, max_iter);
  KMeans<T, Linf<T>> kfisrt(image, nb_clusters, max_iter);

  kfisrt.display_centroids();

  // std::cout << "The distance is " << kfisrt.get_distance(0,105,142) << '\n';

  kfisrt.compute(1e-3);

  // std::cout << Euclidian<T>()(1,5) << '\n';

  // std::cout << image.depth() << '\n';

  // image.display();

  return 0;
}
