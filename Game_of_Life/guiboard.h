#include <functional>

typedef std::function<bool(int,int)> TRead;
typedef std::function<void(int,int,bool)> TWrite;

class GuiBoard
{
public:
    GuiBoard(int width, int height, TRead read, TWrite write) :
     _width(width), _height(height), _read(read), _write(write) {}
    void setup(int side_size = 30);

private:
    int _width, _height;
    TRead _read;
    TWrite _write;
};
