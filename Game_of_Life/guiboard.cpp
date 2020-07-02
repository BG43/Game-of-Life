#include "guiboard.h"
#include "CImg.h"

using namespace cimg_library;

void GuiBoard::setup(int side_size)
{
    CImg<unsigned char> visualization(side_size * _width, side_size * _height, 1, 3, 0);
    const unsigned char red[] = {255, 0, 0}, black[] = {0, 0, 0};
    CImgDisplay disp(visualization,"setup");
    while(!disp.is_closed()) {
        disp.wait();
        if (disp.button()) {
            const int x = disp.mouse_x() / side_size;
            if (x >= 0 && x < _width) {
                const int y = disp.mouse_y() / side_size;
                if (y >= 0 && y < _height) {
                    auto value = !_read(x, y);
                    _write(x, y, value);
                    visualization.draw_rectangle(
                        side_size * x + 1,
                        side_size * y + 1, 
                        side_size * x + side_size - 1,
                        side_size * y + side_size - 1, 
                        value ? red : black, 1.0f);
                    disp.display(visualization);
                }
            }
        }
    }
}
