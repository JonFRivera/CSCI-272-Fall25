#include <iostream>
using namespace std;

class Rectangle {

private:
  double m_length {0.0};
  double m_width {0.0};
  double m_height {0.0};

public:
  Rectangle() = default;

  Rectangle(double length)
    : Rectangle(length, 0.0, 0.0)
  {}

  Rectangle(double length, double width)
    : Rectangle(length, width, 0.0)
  {}

  Rectangle(double length, double width, double height)
    : m_length{length}, m_width{width}, m_height{height}
  {}

  double rectangleArea() const {
    cout << m_length * m_width << endl;
    return 0;
  }

  double rectangleVolume() const {
    cout << m_length * m_width * m_height << endl;
    return 0;
  }

  double rectanglePerimeter() const {
    cout << (2 * m_length) + (2 * m_width) << endl;
    return 0;
  }

};

double getUserLength();
double getUserWidth();
double getUserHeight();


int main() {

  double userLength = getUserLength();
  double userWidth = getUserWidth();
  double userHeight = getUserHeight();

  Rectangle rectangle1 {userLength, userWidth, userHeight};

  rectangle1.rectangleArea();
  rectangle1.rectangleVolume();
  rectangle1.rectanglePerimeter();
  
}

double getUserLength() {

  int length {0};
  cout << "Input Length: ";
  cin >> length;

  return length;

}

double getUserWidth() {

  int width {0};
  cout << "Input Length: ";
  cin >> width;

  return width;

}

double getUserHeight() {

  int height {0};
  cout << "Input Height: ";
  cin >> height;

  return height;

}

