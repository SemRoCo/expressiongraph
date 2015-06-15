/**
 * Created on: Jun., 2015
 *     Author: Georg Bartels
 *
 * Playing with two points attached to a flying
 * frame. Imagine two points on the rim of a flying
 * glass..
 */

#include <kdl/expressiontree.hpp>

int main(int argc, char* argv[])
{
  using namespace KDL;
  using namespace std;

  Expression<Vector>::Ptr cup_position = KDL::vector(input(0), input(1), input(2));
  Expression<Rotation>::Ptr cup_orientation = rot_x(input(3)) * rot_y(input(4)) * rot_z(input(5));
  Expression<Frame>::Ptr cup_pose = cached<Frame>(frame(cup_position) * frame(cup_orientation, cup_position));

  Expression<Vector>::Ptr rim_point1 = cup_pose * KDL::vector(Constant(0.0), Constant(0.02), Constant(0.05));
  Expression<Vector>::Ptr rim_point2 = cup_pose * KDL::vector(Constant(0.0), Constant(-0.02), Constant(0.05));

  Expression<double>::Ptr height_point1_point2 = coord_z(rim_point1) - coord_z(rim_point2);

  std::vector<double> input;
  input.push_back(0.0);
  input.push_back(0.0);
  input.push_back(0.0);
  input.push_back(0.0);
  input.push_back(0.0);
  input.push_back(M_PI / 4.0);
  height_point1_point2->setInputValues(input);

  cout << "THERE ARE TWO POINTS ON THE RIM OF A CUP\n";
  cout << "POINT 1 (in world coordinates):\n";
  cout << rim_point1->value() << "\n";

  cout << "POINT 2 (in world coordinates):\n";
  cout << rim_point2->value() << "\n";

  cout << "HEIGHT OF POINT1 OVER POINT2:\n";
  cout << height_point1_point2->value() << "\n";

  cout << "NUMBER OF DERIVATIVES:\n";
  cout << height_point1_point2->number_of_derivatives() << "\n";

  cout << "HERE ARE THE DERIVATIVES:\n";
  for(unsigned int i=0; i<height_point1_point2->number_of_derivatives(); ++i)
    cout << height_point1_point2->derivative(i) << "\n";

  return -1;
}
