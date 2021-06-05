
#ifndef __SHAPE_H__
#define __SHAPE_H__

#define RADIUS_BALL 5
#define MIN_EDGE 5

class Shape
{
public:
   virtual void fill(void) = 0;
   virtual void render(void) = 0;
   virtual void rotate(void) = 0;
   virtual void update(Mouse) = 0;
   virtual void releaseMouse(void) = 0;
   virtual bool checkUpdateShape(Mouse) = 0;
   virtual bool isInside(float x, float y) = 0;
   void color(float r, float g, float b)
   {
      this->r = r;
      this->g = g;
      this->b = b;
   }
   virtual void high_light()
   {
      CV::color(0.5f + (1 + cos(this->gold)) / 4, 0.5f + (1 + cos(this->gold)) / 4, 0);
      this->gold += 0.05;
      CV::polygon(vx, vy, 4);
      CV::color(1, 1, 1);
      for (int i = 0; i < 4; i++)
      {
         CV::circleFill(update_x[i], update_y[i], RADIUS_BALL, 10);
      }
      CV::circleFill(midle_x, this->up_y, RADIUS_BALL, 10);
   }

protected:
   float *vx;
   float *vy;
   int elems;

   float update_x[4];
   float update_y[4];
   float width_box;
   float height_box;

   float midle_x;
   float up_y;

   float *draw_x;
   float *draw_y;

   bool fill_flag = true;

   float r = 1, g = 1, b = 1;
   float gold = 0.2;
};

#endif
