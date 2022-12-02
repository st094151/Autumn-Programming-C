#ifndef CLDRAW_H
#define CLDRAW_H
#include &lt;cstdlib&gt;
#include &lt;iostream&gt;
#include &lt;graphics.h&gt;
using namespace std;
class clDraw
{
public:
virtual void Show()=0;
};
#endif // CLDRAW_H

//заголовочный файл clCircle.h

#ifndef CLCIRCLE_H
#define CLCIRCLE_H
#include &quot;clDraw.h&quot;
class clCircle : public clDraw
{
public:
clCircle();
clCircle(int x0, int y0);
virtual ~clCircle();
int Getx() { return x; }
void Setx(int val) { x = val; }
int Gety() { return y; }
void Sety(int val) { y = val; }
void Show();
private:
int x;
int y;
const int r = 20;
};
#endif // CLCIRCLE_H

// файл реализации класса clCircle.cpp

#include &quot;clCircle.h&quot;
void clCircle::Show()
{
circle(x,y,r);
}
clCircle::clCircle()

{
cout &lt;&lt; &quot;clCircle();\n&quot;;
}
clCircle::clCircle(int x0, int y0) : x(x0), y(y0)
{
cout &lt;&lt; x &lt;&lt; &quot; clCircle(int x0, int y0);\n&quot;;
}
clCircle::~clCircle()
{
cout &lt;&lt; x &lt;&lt; &quot; ~clCircle();\n&quot;;
}

//заголовочный файл clNode.h

#ifndef CLNODE_H
#define CLNODE_H
#include &quot;clCircle.h&quot;
class clNode : public clCircle
{
public:
clNode();
clNode(int x0, int y0, int num0);
virtual ~clNode();
char *Getnum() { return num; }
void Setnum(int val) { itoa(val,num,10); }
void Show();
private:
char *num;
};
#endif // CLNODE_H

//файл реализации класса clNode.h

#include &quot;clNode.h&quot;
void clNode::Show()
{
clCircle::Show();
outtextxy(Getx(), Gety(), num);
}

clNode::clNode(): num(new char[4])
{
cout &lt;&lt; &quot;clNode();\n&quot;;
}

clNode::clNode(int x0, int y0, int num0)

: clCircle(x0,y0), num(new char[4])

{
Setnum(num0);
cout &lt;&lt; Getx() &lt;&lt; &quot; clNode(int x0, int y0, int num0);\n&quot;;
}
clNode::~clNode()
{
delete [] num; //освободить память
cout &lt;&lt; Getx() &lt;&lt; &quot; ~clNode();\n&quot;;
}

//файл main.cpp

#include &quot;clNode.h&quot;
void f(clDraw *q) {
q-&gt;Show();
}
int main() {
clCircle a;
a.Setx(100);
a.Sety(100);
clCircle b(300,300);
clNode c;
c.Setx(50);
c.Sety(200);
c.Setnum(99);
clNode d(300, 50, 111);
int gd = DETECT;
int gm;
initgraph(&amp;gd, &amp;gm,&quot;&quot;);
f(&amp;a); //a.Show();
f(&amp;b); //b.Show();
f(&amp;c); //c.Show();
f(&amp;d); //d.Show();
readkey();
closegraph();
return 0;
}
