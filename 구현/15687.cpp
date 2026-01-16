#include <iostream>

using namespace std;

class Rectangle
{
private:
    int width;
    int height;

public:
    Rectangle(int width, int height) : width(1), height(1)
    {
        set_width(width);
        set_height(height);
    }

    int get_width() const
    {
        return width;
    }

    int get_height() const
    {
        return height;
    }

    void set_width(int width)
    {
        if (width <= 0 || width > 1000) return;
        this->width = width;
    }

    void set_height(int height)
    {
        if (height <= 0 || height > 2000) return;
        this->height = height;
    }

    int area() const
    {
        return width * height;
    }

    int perimeter() const
    {
        return width * 2 + height * 2;
    }

    bool is_square() const
    {
        return width == height;
    }
};

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);


    return 0;
}