#include <iostream>
#include <windows.h>
#include "graphics2.h"
using namespace std;

int l, midx, midy, dim;
void hilbert (int x1, int y1, int x2, int y2, int r, int d, int n);
bool ok=1;

int main()
{
    int n;
    cout<<"Intrduceti rangul dorit (1<=n<=6): ";
    cin>>n;
    int driver, mod;
    initgraph(&driver, &mod, "", 1024, 768);
    midx = getmaxx()/2; midy = getmaxy()/2;
    setcolor(WHITE);
    dim=10;
    l=((1<<n)-1)*dim;
    hilbert (midx-l/2, midy-l/2, midx+l/2, midy+l/2, 1, 1, n);
    while( !kbhit() );
    closegraph();
    return 0;
}

void hilbert (int x1, int y1, int x2, int y2, int r, int d, int n)
{
 int mx1, my1, mx2, my2;
 bool ok2;
 if (n==0) return;
 mx1=x1+(x2-x1-dim)/2;
 my1=y1+(y2-y1-dim)/2;
 mx2=x2-(x2-x1-dim)/2;
 my2=y2-(y2-y1-dim)/2;
 if (ok) setcolor(rand()%16+1);
 ok2=ok;
 if (r==1)
    {
     if (d==1)
        {
         ok=0;
         hilbert (x1, y1, mx1, my1, 4, 2, n-1);
         rectangle (x1, my1, x1, my2);
         Sleep(8);
         hilbert (x1, my2, mx1, y2, 1, 1, n-1);
         rectangle(mx1, my2, mx2, my2);
         Sleep(8);
         hilbert (mx2, my2, x2, y2, 1, 1, n-1);
         rectangle (x2, my1, x2, my2);
         Sleep(8);
         ok=ok2;
         hilbert (mx2, y1, x2, my1, 2, 2, n-1);
        }
        else
        {
         ok=0;
         hilbert (mx2, y1, x2, my1, 2, 1, n-1);
         rectangle (x2, my1, x2, my2);
         Sleep(8);
         hilbert (mx2, my2, x2, y2, 1, 2, n-1);
         rectangle(mx1, my2, mx2, my2);
         Sleep(8);
         hilbert (x1, my2, mx1, y2, 1, 2, n-1);
         rectangle (mx1, my1, mx1, my2);
         Sleep(8);
         ok=ok2;
         hilbert (x1, y1, mx1, my1, 4, 1, n-1);
        }
    }
    else
    if (r==2)
       {
        if (d==1)
           {
            ok=0;
            hilbert (mx2, y1, x2, my1, 1, 2, n-1);
            rectangle(mx1, y1, mx2, y1);
            Sleep(8);
            hilbert (x1, y1, mx1, my1, 2, 1, n-1);
            rectangle (mx1, my1, mx1, my2);
            Sleep(8);
            hilbert (x1, my2, mx1, y2, 2, 1, n-1);
            rectangle (mx1, y2, mx2, y2);
            Sleep(8);
            ok=ok2;
            hilbert (mx2, my2, x2, y2, 3, 2, n-1);
           }
           else
           {
            ok=0;
            hilbert (mx2, my2, x2, y2, 3, 1, n-1);
            rectangle (mx1, y2, mx2, y2);
            Sleep(8);
            hilbert (x1, my2, mx1, y2, 2, 2, n-1);
            rectangle (mx1, my1, mx1, my2);
            Sleep(8);
            hilbert (x1, y1, mx1, my1, 2, 2, n-1);
            rectangle(mx1, y1, mx2, y1);
            Sleep(8);
            ok=ok2;
            hilbert (mx2, y1, x2, my1, 1, 1, n-1);
           }
       }
       else
       if (r==3)
          {
           if (d==1)
              {
               ok=0;
               hilbert (mx2, my2, x2, y2, 2, 2, n-1);
               rectangle (x2, my1, x2, my2);
               Sleep(8);
               hilbert (mx2, y1, x2, my1, 3, 1, n-1);
               rectangle (mx1, my1, mx2, my1);
               Sleep(8);
               hilbert (x1, y1, mx1, my1, 3, 1, n-1);
               rectangle (x1, my1, x1, my2);
               Sleep(8);
               ok=ok2;
               hilbert (x1, my2, mx1, y2, 4, 2, n-1);
              }
              else
              {
               ok=0;
               hilbert (x1, my2, mx1, y2, 4, 1, n-1);
               rectangle (x1, my1, x1, my2);
               Sleep(8);
               hilbert (x1, y1, mx1, my1, 3, 2, n-1);
               rectangle (mx1, my1, mx2, my1);
               Sleep(8);
               hilbert (mx2, y1, x2, my1, 3, 2, n-1);
               rectangle (x2, my1, x2, my2);
               Sleep(8);
               ok=ok2;
               hilbert (mx2, my2, x2, y2, 2, 1, n-1);
              }
          }
          else
          {
           if (d==1)
              {
               ok=0;
               hilbert (x1, my2, mx1, y2, 3, 2, n-1);
               rectangle (mx1, y2, mx2, y2);
               Sleep(8);
               hilbert (mx2, my2, x2, y2, 4, 1, n-1);
               rectangle (mx2, my1, mx2, my2);
               Sleep(8);
               hilbert (mx2, y1, x2, my1, 4, 1, n-1);
               rectangle (mx2, y1, mx1, y1);
               Sleep(8);
               ok=ok2;
               hilbert (x1, y1, mx1, my1, 1, 2, n-1);
              }
              else
              {
               ok=0;
               hilbert (x1, y1, mx1, my1, 1, 1, n-1);
               rectangle (mx2, y1, mx1, y1);
               Sleep(8);
               hilbert (mx2, y1, x2, my1, 4, 2, n-1);
               rectangle (mx2, my1, mx2, my2);
               Sleep(8);
               hilbert (mx2, my2, x2, y2, 4, 2, n-1);
               rectangle (mx1, y2, mx2, y2);
               Sleep(8);
               ok=ok2;
               hilbert (x1, my2, mx1, y2, 3, 1, n-1);
              }
          }
}
