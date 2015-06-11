/**
 * Created on: Jun., 2015
 *     Author: Georg Bartels
 *
 * Playing with the function y = 2*x*x - 1, and its first four
 * derivatives at x = 3.0.
 */

#include <kdl/expressiontree.hpp>

int main(int argc, char* argv[])
{
  using namespace KDL;
  using namespace std;

  // using a cached variable just for the fun of it..
  Expression<double>::Ptr var = cached<double>(input(0));

  // constructing expression and all derivatives
  Expression<double>::Ptr expr = Constant(2.0) * var * var - Constant(1.0);
  Expression<double>::Ptr first_deriv = expr->derivativeExpression(0);
  Expression<double>::Ptr second_deriv = first_deriv->derivativeExpression(0);
  Expression<double>::Ptr third_deriv = second_deriv->derivativeExpression(0);
  Expression<double>::Ptr fourth_deriv = third_deriv->derivativeExpression(0);

  // setting the input
  expr->setInputValue(0, 3.0);

  // spaming the user with evaluation results on the console
  cout << "ORIGINAL EXPRESSION:\n";
  expr->print(cout);
  cout << "\nValue: " << expr->value() << "\n";
  cout << "Derivative Value: " << expr->derivative(0) << "\n";

  cout << "\nFIRST DERIVATIVE:\n"; 
  first_deriv->print(cout);
  cout << "\nValue: " << first_deriv->value() << "\n";
  cout << "Derivative Value: " << first_deriv->derivative(0) << "\n";

  cout << "\nSECOND DERIVATIVE:\n"; 
  second_deriv->print(cout);
  cout << "\nValue: " << second_deriv->value() << "\n";
  cout << "Derivative Value: " << second_deriv->derivative(0) << "\n";

  cout << "\nTHIRD DERIVATIVE:\n"; 
  third_deriv->print(cout);
  cout << "\nValue: " << third_deriv->value() << "\n";
  cout << "Derivative Value: " << third_deriv->derivative(0) << "\n";

  cout << "\nFOURTH DERIVATIVE:\n"; 
  fourth_deriv->print(cout);
  cout << "\nValue: " << fourth_deriv->value() << "\n";
  cout << "Derivative Value: " << fourth_deriv->derivative(0) << "\n";

  return 0;
}
