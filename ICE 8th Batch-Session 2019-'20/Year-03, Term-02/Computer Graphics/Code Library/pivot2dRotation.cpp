#include <graphics.h>
#include <cmath>

// Function to draw a rectangle
void drawRectangle(int x1, int y1, int x2, int y2) {
    rectangle(x1, y1, x2, y2);
}

// Function to rotate a point about the origin
void rotatePoint(int &x, int &y, float angle) {
    float rad = angle * 3.14159265358979323846 / 180.0;
    int newX = round(x * cos(rad) - y * sin(rad));
    int newY = round(x * sin(rad) + y * cos(rad));
    x = newX;
    y = newY;
}

// Function to rotate a rectangle about a pivot point
void rotateRectangle(int &x1, int &y1, int &x2, int &y2, float angle, int pivotX, int pivotY) {
    // Translate the rectangle to make pivot point the origin
    x1 -= pivotX;
    y1 -= pivotY;
    x2 -= pivotX;
    y2 -= pivotY;

    // Rotate the rectangle
    rotatePoint(x1, y1, angle);
    rotatePoint(x2, y2, angle);

    // Translate the rectangle back to its original position
    x1 += pivotX;
    y1 += pivotY;
    x2 += pivotX;
    y2 += pivotY;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1 = 100, y1 = 100; // Coordinates of the top-left corner
    int x2 = 300, y2 = 200; // Coordinates of the bottom-right corner

    // Draw the original rectangle
    drawRectangle(x1, y1, x2, y2);

    // Rotation angle (in degrees)
    float angle = 45.0;

    // Pivot point coordinates
    int pivotX = 200, pivotY = 150;

    // Rotate the rectangle about the pivot point
    rotateRectangle(x1, y1, x2, y2, angle, pivotX, pivotY);

    // Draw the rotated rectangle
    setcolor(RED);
    drawRectangle(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}
